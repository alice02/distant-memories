#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


#define PORT 8765

#define BRACK '*'
#define WHITE 'o'
#define SPACE ' '


char osero[8][8];   /* 盤面データ */
int fd;		    /* ソケットディスクリプタ */


/* 盤面を表示 */
void print_osero(void)
{
  int i, j;

  printf(" |A|B|C|D|E|F|G|H|\n");
  printf("-+-+-+-+-+-+-+-+-+\n");

  for (i = 0; i < 8; i++)
    {
      printf("%c|", ('a' + i));
      for(j = 0; j < 8; j++)
	{
	  printf("%c|", osero[i][j]);
	}
      printf("\n");
      printf("-+-+-+-+-+-+-+-+-+\n");
    }
}


/* ネットワーク接続関係 */
void network_init(char *hostname)
{
  struct sockaddr_in addr;
  struct hostent *hp;

  int    len;

  /*
   *  ソケットを作る。このソケットはUNIXドメインで、ストリーム型ソケット。
   */
  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  /* 
   * addrの中身を0にしておかないと、bind()でエラーが起こることがある
   */
  bzero((char *)&addr, sizeof(addr));

  /*
   * ソケットの名前を入れておく
   */
  if ((hp = gethostbyname(hostname)) == NULL) {
    perror("No such host");
    exit(1);
  }
  bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);

  /*
   *  サーバーとの接続を試みる。これが成功するためには、サーバーがすでに
   *  このアドレスをbind()して、listen()を発行していなければならない。
   */
  if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0){
    perror("connect");
    exit(1);
  }

}


/* メイン処理 */
void game(void)
{
  char buf[256];
  char str[10], now[10];
  char b_num[3], w_num[3], winner[6];
  int ret;


  /* サーバーから先手 or 後手の情報を受け取る(黒:先手、白:後手) */
  ret = read(fd, str, sizeof(char)*10);


  printf("Your color is %s.\n", str);
  printf("NOTES ~ How to Choice the spot ~\n");
  printf("ex: PLAYER's turn. Choice the spot. : gH\n");


  while (1) {
    /* サーバーから盤面の情報を受け取り表示 */
    ret = read(fd, osero, sizeof(char) * 8 * 8);
    print_osero();

    /* 現在の状態を取得(黒or白の番、入力エラー、対局終了) */
    ret = read(fd, now, sizeof(char) * 10);

    /* 自分の番 */
    if (strcmp(now, str) == 0) {
      printf("%s's turn. Choice the spot. : ", str);
      scanf("%s", buf);
      /* コマンドをサーバーに送信 */
      write(fd, buf, sizeof(char)*256);
    }
    /* 入力エラー */
    else if (now[0] == 'E' && strcmp(&(now[1]), str) == 0) {
      printf("Input is the error. Please retry the input. : ");
      scanf("%s", buf);
      /* コマンドをサーバーに送信 */
      write(fd, buf, sizeof(char)*256);
    }
    /* 対局終了 */
    else if (strcmp(now, "FINISH") == 0) {
      /* 対局結果をサーバーから受け取る */
      ret = read(fd, b_num, sizeof(char) * 3);
      ret = read(fd, w_num, sizeof(char) * 3);
      ret = read(fd, winner, sizeof(char) * 6);
      /* 結果の表示 */
      printf("Finish!! BRACK:%s, WHITE:%s. Winner is %s!!\n", b_num, w_num, winner);
      break;
    }
    /* 相手の番 */
    else {
      printf("NOW, ENEMY's turn.\n");
    }
  }

}


int main(int argc, char *argv[])
{
  /* 引数が異常な場合の処理 */
  if (argc != 2){
    printf("Usage: %s SERVER_NAME\n", argv[0]);
    exit(1);
  }

  /* ネットワーク関連の処理 */
  network_init(argv[1]);

  /* メイン処理 */
  game();

  /* 通信が終わったらソケットを閉じる */
  close(fd);

  return 0;
}


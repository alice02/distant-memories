/*
  FILE NAME: network.c

  DESCRIPTION:
  ネットワーク通信に関する処理
*/


#include "daifugo.h"


void network_init_server(int s[], fd_set* readfds)
{
  //  int s[SOCK_MAX + 1]; // array of socket descriptors
  int max = 0;         // max num of used socket
  int n = 0;
  int len;
  //  fd_set readfds;
  int clilen;               /* client length */
  struct sockaddr_in saddr; /* サーバ側(自分)のアドレス情報 */
  struct sockaddr_in caddr; /* クライアント側のアドレス情報を入れるところ */
  char str[1024];           /* string buffer */
  int i, j;                 /* loop counter */
  int msglen;
  int count;
  int on = 1;
  
  // ソケットを作る。
  // このソケットはINETドメインでストリーム型(コネクション型) 。
  if ((s[0] = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }
  
  // saddrの中身を0にしておかないと、bind()でエラーが起こることがある
  bzero((char *)&saddr, sizeof(saddr));
  
  // ソケットに名前をつける bind()
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = INADDR_ANY;
  saddr.sin_port = htons(PORT); // 定数PORTは#defineしたもの
  
  /// !!!!!!!!
  setsockopt(s[0], SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  /// !!!!!!!!

  if ((bind(s[0], (struct sockaddr *)&saddr, sizeof(saddr))) == -1) {
    perror("bind");
    exit(1);
  }
  
  // 接続されるのを待つ listen()
  // 第2引数の値を大きくする
  if ((listen(s[0], SOCK_MAX)) == -1) {
    perror("listen");
    exit(1);
  } 
  max = 1;   // s[0] is ready
  
  // メインループ
  /// 4人集まったら、初期化終了
  while (max < PLAYER_NUM+1) {

    FD_ZERO(readfds);    // fdsの初期化
    printf("max: %d\n", max);

    // すでにクライアントと接続されているソケットのビットを
    // セットしてselect()の検査対象にする。
    for (i = 0; i < max; i++) {
      if (s[i] != UNUSED) {
	FD_SET(s[i], readfds);
      }
    }


    // 新たな接続要求があった場合は、s[0]のビットが立つ。
    // 以下では新たな接続の受け付けを行う。
    if (FD_ISSET(s[0], readfds) != 0) {
      printf("Accept New one.\n");
      // 接続を確立する accept()
      len = sizeof(caddr);
      s[max] = accept(s[0], (struct sockaddr *)&caddr, &len);
      printf("%d = accept()\n", s[max]);
      if (s[max] == -1) {
	perror(NULL);
	exit(1);
      }
      if (max < SOCK_MAX) {
	printf("client accepted(%d).\n", max);
	max++;
      } else {
	printf("refuse connection.\n");
	strcpy(str, "Server is too busy.\n");
	write(s[max], str, strlen(str));
	close(s[max]);
      }
    }
  }
}



void network_init_client(int *fd, char *host[])
{
  struct sockaddr_in    addr;
  struct hostent *hp;


  /*
   *  ソケットを作る。このソケットはUNIXドメインで、ストリーム型ソケット。
   */
  if ((*fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
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

  hp = gethostbyname(host[1]);
  if (hp == NULL) {
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

  if (connect((*fd), (struct sockaddr *)&addr, sizeof(addr)) < 0){
    perror("connect");
    exit(1);
  }

}



// クライアントにcontrol_dataを送る
void send_control_data(int s[], int control)
{
  int i;

  for (i = 0; i < PLAYER_NUM; i++) {
	if (s[i+1] != UNUSED) {
	  send(s[i+1], &control, sizeof(int), 0);
	}
  }

}

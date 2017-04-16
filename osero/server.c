#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>  /* #include < sys/un.h >の代わり */


#define PORT 8765

#define BRACK '*'
#define WHITE 'o'
#define SPACE ' '

#define UPPERLEFT 0
#define UP 1
#define UPPERRIGHT 2
#define LEFT 3
#define RIGHT 4
#define LOWERLEFT 5
#define LOW 6
#define LOWERRIGHT 7

int    fd1, fd2;    /* ソケットディスクリプタ */
char osero[8][8];   /* 盤面データ */


void init(void)
{
  int i, j;

  for(i = 0; i < 8; i++)
    {
      for (j = 0; j < 8; j++)
	{
	  osero[i][j] = SPACE;
	}
    }

  osero[3][3] = osero[4][4] = WHITE;
  osero[3][4] = osero[4][3] = BRACK;
}

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

int check_input(char input[3], char color)
{
  int i, j, x, y;
  char checker;

  if ((input[0] < 'a') || ('h' < input[0])) return -1;
  if ((input[1] < 'A') || ('H' < input[1])) return -1;

  if(osero[input[0] - 'a'][input[1] - 'A'] != SPACE) return 1;

  y = input[0] - 'a';
  x = input[1] - 'A';
  if(color == BRACK) checker = WHITE;
  else if(color == WHITE) checker = BRACK;

  for (i = 0; i < 8; i++)
    {
      switch(i)
	{
	case UPPERLEFT:
	  j = 0;
	  if ((osero[y - 1][x - 1] == color) || (osero[y - 1][x - 1] == SPACE)) break;
	  while(osero[y - 1 - j][x - 1 - j] == checker) j++;
	  if(osero[y - 1 - j][x - 1 - j] == color) return 0;
	  else break;
	  
	case UP:
	  j = 0;
	  if ((osero[y - 1][x] == color) || (osero[y - 1][x] == SPACE)) break;
	  while(osero[y - 1 - j][x] == checker) j++;
	  if(osero[y - 1 - j][x] == color) return 0;
	  else break;	
	  
	case UPPERRIGHT:
	  j = 0;
	  if ((osero[y - 1][x + 1] == color) || (osero[y - 1][x + 1] == SPACE)) break;
	  while(osero[y - 1 - j][x + 1 + j] == checker) j++;
	  if(osero[y - 1 - j][x + 1 + j] == color) return 0;
	  else break;

	case LEFT:
	  j = 0;
	  if ((osero[y][x - 1] == color) || (osero[y][x - 1] == SPACE)) break;
	  while(osero[y][x - 1 - j] == checker) j++;
	  if(osero[y][x - 1 - j] == color) return 0;
	  else break;
	  
	case RIGHT:
	  j = 0;
	  if ((osero[y][x + 1] == color) || (osero[y][x + 1] == SPACE)) break;
	  while(osero[y][x + 1 + j] == checker) j++;
	  if(osero[y][x + 1 + j] == color) return 0;
	  else break;

	case LOWERLEFT:
	  j = 0;
	  if ((osero[y + 1][x - 1] == color) || (osero[y + 1][x - 1] == SPACE)) break;
	  while(osero[y + 1 + j][x - 1 - j] == checker) j++;
	  if(osero[y + 1 + j][x - 1 - j] == color) return 0;
	  else break;

	case LOW:
	  j = 0;
	  if ((osero[y + 1][x] == color) || (osero[y + 1][x] == SPACE)) break;
	  while(osero[y + 1 + j][x] == checker) j++;
	  if(osero[y + 1 + j][x] == color) return 0;
	  else break;

	case LOWERRIGHT:
	  j = 0;
	  if ((osero[y + 1][x + 1] == color) || (osero[y + 1][x + 1] == SPACE)) break;
	  while(osero[y + 1 + j][x + 1 + j] == checker) j++;
	  if(osero[y + 1 + j][x + 1 + j] == color) return 0;
	  else break;
	}
    }
  
  return 2;
}
	
int check_finish(char color)
{
  int x, y, i, j, checker;

  if (color == BRACK) checker = WHITE;
  else if (color == WHITE) checker = BRACK;

  for (y = 0; y < 8; y++)
    {
      for (x = 0; x < 8; x++)
	{
	  if(osero[y][x] == SPACE)
	    {
	      
	      for (i = 0; i < 8; i++)
		{
		  switch(i)
		    {
		    case UPPERLEFT:
		      j = 0;
		      if ((osero[y - 1][x - 1] == color) || (osero[y - 1][x - 1] == SPACE)) break;
		      while(osero[y - 1 - j][x - 1 - j] == checker) j++;
		      if(osero[y - 1 - j][x - 1 - j] == color) return -1;
		      else break;
		      
		    case UP:
		      j = 0;
		      if ((osero[y - 1][x] == color) || (osero[y - 1][x] == SPACE)) break;
		      while(osero[y - 1 - j][x] == checker) j++;
		      if(osero[y - 1 - j][x] == color) return -1;
		      else break;	
		      
		    case UPPERRIGHT:
		      j = 0;
		      if ((osero[y - 1][x + 1] == color) || (osero[y - 1][x + 1] == SPACE)) break;
		      while(osero[y - 1 - j][x + 1 + j] == checker) j++;
		      if(osero[y - 1 - j][x + 1 + j] == color) return -1;
		      else break;
		      
		    case LEFT:
		      j = 0;
		      if ((osero[y][x - 1] == color) || (osero[y][x - 1] == SPACE)) break;
		      while(osero[y][x - 1 - j] == checker) j++;
		      if(osero[y][x - 1 - j] == color) return -1;
		      else break;
		      
		    case RIGHT:
		      j = 0;
		      if ((osero[y][x + 1] == color) || (osero[y][x + 1] == SPACE)) break;
		      while(osero[y][x + 1 + j] == checker) j++;
		      if(osero[y][x + 1 + j] == color) return -1;
		      else break;
		      
		    case LOWERLEFT:
		      j = 0;
		      if ((osero[y + 1][x - 1] == color) || (osero[y + 1][x - 1] == SPACE)) break;
		      while(osero[y + 1 + j][x - 1 - j] == checker) j++;
		      if(osero[y + 1 + j][x - 1 - j] == color) return -1;
		      else break;
		      
		    case LOW:
		      j = 0;
		      if ((osero[y + 1][x] == color) || (osero[y + 1][x] == SPACE)) break;
		      while(osero[y + 1 + j][x] == checker) j++;
		      if(osero[y + 1 + j][x] == color) return -1;
		      else break;
		      
		    case LOWERRIGHT:
		      j = 0;
		      if ((osero[y + 1][x + 1] == color) || (osero[y + 1][x + 1] == SPACE)) break;
		      while(osero[y + 1 + j][x + 1 + j] == checker) j++;
		      if(osero[y + 1 + j][x + 1 + j] == color) return -1;
		      else break;
		    }
		}
	      
	    }
	}
    }
  
  return 0;
}

void send_translation(char *str)
{
  int x, y, i;

  i = 0;
  for (y = 0; y < 8; y++)
    {
      for (x = 0; x < 8; x++)
	{
	  str[i] = osero[y][x];
	  i++;
	}
    }
  str[i] = '\0';

}

void receive_translation(char *str)
{
  int x, y, i;

  x = y = 0;
  for (i = 0; i != '\0'; i++)
    {
      osero[y][x] = str[i];
      x++;
      if (x == 8)
	{
	  y++;
	  x = 0;
	}
    }
}

void check_winner(int *brack, int *white, char winner[6])
{
  int i, j, b, w;

  b = w = 0;

  for (i = 0; i < 8; i++)
    {
      for (j = 0; j < 8; j++)
	{
	  if (osero[i][j] == BRACK) b++;
	  else if (osero[i][j] == WHITE) w++;
	}
    }

  if (b > w) strcpy(winner, "BRACK");
  else if (b < w) strcpy(winner, "WHITE");
  *brack = b;
  *white = w;
}

void stone_reverse(char color, int x, int y)
{
  int i, j, checker;

  if (color == BRACK) checker = WHITE;
  else if (color == WHITE) checker = BRACK;

  for (i = 0; i < 8; i++)
    {
      switch(i)
      {
      case UPPERLEFT:
	//printf("UPPERLEFT\n");   
	j = 0;
	while(osero[y - 1 - j][x - 1 - j] == checker) j++;
	if(osero[y - 1 - j][x - 1 - j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y - 1 - j][x - 1 - j] = color;
		j--;
	      }
	  }
	break;
	
      case UP:   
	//printf("UP\n");
	j = 0;
	while(osero[y - 1 - j][x] == checker) j++;
	if(osero[y - 1 - j][x] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y - 1 - j][x] = color;
		j--;
	      }
	  }
	break;	
	
      case UPPERRIGHT:
	//printf("UPPERRIGHT\n");    
	j = 0;
	while(osero[y - 1 - j][x + 1 + j] == checker) j++;
	if(osero[y - 1 - j][x + 1 + j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y - 1 - j][x + 1 + j] = color;
		j--;
	      }
	  }
	break;
	
      case LEFT:
	//printf("LEFT\n");	
	j = 0;
	while(osero[y][x - 1 - j] == checker) j++;
	if(osero[y][x - 1 - j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y][x - 1 - j] = color;
		j--;
	      }
	  }
	break;
	
      case RIGHT:
	//printf("RIGHT\n");      
	j = 0;
	while(osero[y][x + 1 + j] == checker) j++;
	if(osero[y][x + 1 + j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y][x + 1 + j] = color;
		j--;
	      }
	    }
	break;
	
      case LOWERLEFT:
	//printf("LOWERLEFT\n");   
	j = 0;
	while(osero[y + 1 + j][x - 1 - j] == checker) j++;
	if(osero[y + 1 + j][x - 1 - j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y + 1 + j][x - 1 - j] = color;
		j--;
	      }
	  }
	break;
	
      case LOW:
	//printf("LOW\n");   
	j = 0;
	while(osero[y + 1 + j][x] == checker) j++;
	if(osero[y + 1 + j][x] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y + 1 + j][x] = color;
		j--;
	      }
	  }
	break;
	
      case LOWERRIGHT:
	//printf("LOWERRIGHT\n");      
	j = 0;
	while(osero[y + 1 + j][x + 1 + j] == checker) j++;
	if(osero[y + 1 + j][x + 1 + j] == color)
	  {
	    j--;
	    while(0 <= j)
	      {
		osero[y + 1 + j][x + 1 + j] = color;
		j--;
	      }
	  }
	break;
	
      }
  
    }

}

void game(void)
{
  char buffer[256], input[3], winner[6];
  char color[10], now[10];
  char b_num[3], w_num[3];
  int brack, white, ret, val;


  srand((unsigned)time(NULL));


  /* 先手・後手を決定 */
  val = rand() % 2;
  if (val == 1) {
    strcpy(color, "BRACK");  /* server側:黒(先手) */
    write(fd2, "WHITE", sizeof(char) * 10); /* client側:白(後手) */
  }
  else {
    strcpy(color, "WHITE");		/* server側:白(後手) */
    write(fd2, "BRACK", sizeof(char) * 10); /* client側:黒(先手) */
  }


  printf("Your color is %s.\n", color);
  printf("NOTES ~ How to Choice the spot ~\n");
  printf("ex: PLAYER's turn. Choice the spot. : gH\n");


  /* 盤面の表示 */
  print_osero();
  /* クライアントに盤面データを送信 */
  write(fd2, osero, sizeof(char) * 8 * 8);


  while(1) {

      /************* 先手 *************/
      /* 今は黒のターン */
      strcpy(now, "BRACK");;
      write(fd2, now, sizeof(char) * 10);

      /* 自分の番ならコマンド入力、相手の番なら待機 */
      if (strcmp(color, "BRACK") == 0) {
	printf("BRACK's turn. Choice the spot. : ");
	scanf("%s", buffer);
      }
      else {
	printf("NOW, ENEMY's turn.\n");
	ret = read(fd2, buffer, sizeof(char) * 256);
      }

      input[0] = buffer[0];
      input[1] = buffer[1];
      input[2] = '\0';

      if(check_input(input, BRACK) != 0)
	{
	  while(check_input(input, BRACK) != 0)
	    {
	      //printf("errorcode = %d\n", check_input(input, BRACK));

	      /* 盤面の表示(クライアントとの通信の関係で) */
	      print_osero();
	      write(fd2, osero, sizeof(char) * 8 * 8);

	      /* 黒のターンで入力エラーが発生したことをクライアントに伝える */
	      strcpy(now, "EBRACK"); 
	      write(fd2, now, sizeof(char) * 10);

	      if (strcmp(color, "BRACK") == 0) {
		printf("Input is the error. Please retry the input. : ");
		scanf("%s", buffer);
	      }
	      else {
		printf("NOW, ENEMY's turn.\n");
		ret = read(fd2, buffer, sizeof(char) * 256);
	      }

	      input[0] = buffer[0];
	      input[1] = buffer[1];
	      input[2] = '\0';
	    }
	}

      osero[input[0] - 'a'][input[1] - 'A'] = BRACK;
      stone_reverse(BRACK, (input[1] - 'A'), (input[0] - 'a'));

      print_osero();
      write(fd2, osero, sizeof(char) * 8 * 8);


      if(check_finish(BRACK) == 0) break;


      /************* 後手 *************/
      /* 今は白のターン */
      strcpy(now,  "WHITE");
      write(fd2, now, sizeof(char) * 10);

      /* 自分の番ならコマンド入力、相手の番なら待機 */
      if (strcmp(color, "WHITE") == 0) {
	printf("WHITE's turn. Choice the spot. : ");
	scanf("%s", buffer);
      }
      else {
	printf("NOW, ENEMY's turn.\n");
	ret = read(fd2, buffer, sizeof(char) * 256);
      }

      input[0] = buffer[0];
      input[1] = buffer[1];
      input[2] = '\0';

      if(check_input(input, WHITE) != 0)
	{
	  while(check_input(input, WHITE) != 0)
	    {
	      //printf("errorcode = %d\n", check_input(input, WHITE));
	      print_osero();
	      write(fd2, osero, sizeof(char) * 8 * 8);

	      /* 白のターンで入力エラーが発生したことをクライアントに伝える */
	      strcpy(now, "EWHITE");
	      write(fd2, now, sizeof(char) * 10);

	      if (strcmp(color, "WHITE") == 0) {
		printf("Input is the error. Please retry the input. : ");
		scanf("%s", buffer);
	      }
	      else {
		printf("NOW, ENEMY's turn.\n");
		ret = read(fd2, buffer, sizeof(char) * 256);
	      }

	      input[0] = buffer[0];
	      input[1] = buffer[1];
	      input[2] = '\0';
	    }
	}

      osero[input[0] - 'a'][input[1] - 'A'] = WHITE;
      stone_reverse(WHITE, (input[1] - 'A'), (input[0] - 'a'));

      print_osero();
      write(fd2, osero, sizeof(char) * 8 * 8);


      if(check_finish(WHITE) == 0) break;
    }


  /* ゲーム終了をクライアントに伝える */
  strcpy(now, "FINISH");
  write(fd2, now, sizeof(char)*10);

  check_winner(&brack, &white, winner);

  /* 数値を数字に変換 */
  sprintf(b_num, "%d", brack);
  sprintf(w_num, "%d", white);

  /* 結果をクライアントに送信 */
  write(fd2, b_num, sizeof(char) * 3);
  write(fd2, w_num, sizeof(char) * 3);
  write(fd2, winner, sizeof(char) * 6);

  printf("Finish!! BRACK:%d, WHITE:%d. Winner is %s!!\n", brack, white, winner);

}


/* ネットワーク関係 */
void network_init(void)
{
  int    i;
  int    len;
  int    ret;
  int    on = 1;
  struct sockaddr_in    saddr;
  struct sockaddr_in    caddr;


  /*
   * ソケットを作る。このソケットはUNIXドメインで、ストリーム型ソケット。
   */
  if ((fd1 = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  /* 
   * saddrの中身を0にしておかないと、bind()でエラーが起こることがある
   */
  bzero((char *)&saddr, sizeof(saddr));

  /*
   * ソケットの名前を入れておく
   */
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = INADDR_ANY;
  saddr.sin_port = htons(PORT);

  /* 「bind: Address already in use」対策 */
  setsockopt(fd1, SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));

  /*
   * ソケットにアドレスをバインドする。
   */
  if (bind(fd1, (struct sockaddr *)&saddr, sizeof(saddr)) < 0){
    perror("bind");
    exit(1);
  }
    
  /*
   * listenをソケットに対して発行する
   */
  if (listen(fd1, 1) < 0) {
    perror("listen");
    exit(1);
  }

  len = sizeof(caddr);
  /*
   * accept()により、クライアントからの接続要求を受け付ける。
   * 成功すると、クライアントと接続されたソケットのディスクリプタが
   * fd2に返される。このfd2を通して通信が可能となる。
   * fd1は必要なくなるので、close()で閉じる。
   */
  if ((fd2 = accept(fd1, (struct sockaddr *)&caddr, &len)) < 0) {
    perror("accept");
    exit(1);
  }
  close(fd1);

}


int main(void)
{
  network_init();
  init();
  game();

  /* 通信が終わったらソケットを閉じる */
  close(fd2);

  return 0;
}

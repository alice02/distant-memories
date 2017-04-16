#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 16 /* 4の倍数が好ましい... */

struct parameter {
  int position_x;
  int position_y;
  int hp;
  int stage;
  int clear_flag;
  int pass_flag[MAX_SIZE][MAX_SIZE];
  int bomb[MAX_SIZE][MAX_SIZE];
  int play_mode;
  int steps;
};

void initialize(struct parameter player[], int ct);
int disp_map(struct parameter player[]);
void input_key(struct parameter player[]);
void menu(struct parameter player[], int *ct);

int main(int argc, char *argv[])
{
  srand((unsigned)time(NULL));

  struct parameter player[1];

  int ct = 1, score = 0, hiscore;

  if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'm') {
    menu(player, &ct);
  }
  else if (argc >= 3) {
    printf("ERROR!!!\n");
    exit(1);
  }

  while (ct <= 3) {
    initialize(player, ct);
    disp_map(player);
    while (player[0].hp>0) {
      if (player[0].clear_flag==TRUE) {
	printf("GOAL!!!!!\n");
	sleep(1);
	break;
      }
      input_key(player);
      disp_map(player);
    }
    score += player[0].hp - player[0].steps;
    if (player[0].hp<=0) {
      printf("GAME OVER...\n");
      break;
    }
    ct++;
  }

  printf("score : %d\n", score);

  return 0;
}

void menu(struct parameter player[], int *ct)
{
  char buf[BUFSIZ], moji[BUFSIZ];
  int n;

  printf("****************************\n");
  printf("*        MAIN MENU         *\n");
  printf("* ------------------------ *\n");
  printf("*  1.NOMAL PLAY            *\n");
  printf("*  2.DEBUG MODE            *\n");
  printf("*  3.CHEAT MODE            *\n");
  printf("* ------------------------ *\n");
  printf("****************************\n\n");

  while (1) {
    printf("PLEASE SECECT PLAY MODE!! : ");
    fgets(buf, BUFSIZ, stdin);
    n = sscanf(buf, "%d%s", &player[0].play_mode, moji);
    if (player[0].play_mode >= 0 && player[0].play_mode <= 3 && n == 1) {
      break;
    }
    else {
      printf("INPUT ERROR!!!\n");
    }
  }

  if (player[0].play_mode == 2) {
    while (1) {
      printf("PLEASE INPUT STAGE NUMBER!! : ");
      fgets(buf, BUFSIZ, stdin);
      n = sscanf(buf, "%d%s", &*ct, moji);
      if (player[0].play_mode >= 0 && player[0].play_mode <= 3 && n == 1) {
	break;
      }
      else {
	printf("INPUT ERROR!!!\n");
      }
    }
  }

}

void input_key(struct parameter player[])
{
  char buf[BUFSIZ], moji[BUFSIZ];
  int n, key, size;

  if (player[0].stage == 1) {
    size = MAX_SIZE/2;
  }
  else if (player[0].stage == 2) {
    size = MAX_SIZE/2 + MAX_SIZE/4;
  }
  else {
    size = MAX_SIZE;
  }

  while (1) {
    printf("key = ");
    fgets(buf, BUFSIZ, stdin);
   n =  sscanf(buf, "%d%s", &key, moji);
    if (key == 2 && n == 1) {
      break;
    }
    else if (key == 4 && n == 1) {
      break;
    }
    else if (key == 6 && n == 1) {
      break;
    }
    else if (key == 8 && n == 1) {
      break;
    }
    else {
      printf("INPUT ERROR!!!\n");
    }
  }

  if (key==2 && player[0].position_y==size-1) {
    input_key(player);
  }
  else if (key==4 && player[0].position_x==0) {
    input_key(player);
  }
  else if (key==6 && player[0].position_x==size-1) {
    input_key(player);
  }
  else if (key==8 && player[0].position_y==0) {
    input_key(player);
  }
  else if (key==2) {
    player[0].position_y++;
  }
  else if (key==4) {
    player[0].position_x--;
  }
  else if (key==6) {
    player[0].position_x++;
  }
  else {
    player[0].position_y--;
  }

  player[0].steps++;

}

void initialize(struct parameter player[], int ct)
{
  int i, j;

  player[0].position_x = 0; /* プレイヤーx座標初期化 */
  player[0].position_y = 0; /* プレイヤーy座標初期化 */
  player[0].hp = 1000; /* プレイヤーHP初期化 */
  player[0].stage = ct; /* ステージ初期化 */
  player[0].clear_flag = FALSE; /* クリアフラグ初期化(FALSE) */
  player[0].steps = 0;

  /* 通過箇所初期化 */
  for (i=0; i<MAX_SIZE; i++) {
    for (j=0; j<MAX_SIZE; j++) {
      player[0].pass_flag[i][j] = 0;
    }
  }

  /* 爆弾配置 */
  for (i=0; i<MAX_SIZE; i++) {
    for (j=0; j<MAX_SIZE; j++) {
      if (rand()%100<30) {
	if (i==0 && j==0) {
	  player[0].bomb[j][i] = FALSE;
	}
	else {
	  player[0].bomb[j][i] = TRUE;
	}
      }
      else {
	player[0].bomb[j][i] = FALSE;
      }
    }
  }


}

int disp_map(struct parameter player[])
{
  int i, j;
  int size;

  if (player[0].stage == 1) {
    size = MAX_SIZE/2;
  }
  else if (player[0].stage == 2) {
    size = MAX_SIZE/2 + MAX_SIZE/4;
  }
  else {
    size = MAX_SIZE;
  }

  printf("\x1b[2J");


  printf("********************\n");
  printf("*      STAGE %d     *\n", player[0].stage);
  printf("********************\n\n");

  printf(" ");
  for (i=0; i<size; i++) {
    printf("%4d", i);
  }
  printf("\n");

  printf("  +");
  for (i=0; i<size-1; i++) {
    printf("----");
  }
  printf("--+\n");

  for (i=0; i<size; i++) {
    printf("%2d|", i);
    for (j=0; j<size; j++) {
      if (player[0].position_y==i && player[0].position_x==j) {
	printf("\x1b[31m");
	printf("@@");
	printf("\x1b[0m");
	player[0].pass_flag[j][i] = TRUE;
	if (player[0].bomb[j][i] == TRUE) {
	  player[0].hp -= rand()%5 * 100;
	  player[0].bomb[j][i] = FALSE;
	}
      }
      else if (player[0].pass_flag[j][i]==TRUE) {
	printf("  ");
      }
      else if (player[0].play_mode == 3 && player[0].bomb[j][i] == TRUE) {
	printf("\x1b[33m");
	printf("**");
	printf("\x1b[0m");
      }
      else {
	printf("**");
      }

      if (j!=size-1) {
	printf("  ");
      }
    }
    printf("|\n");
  }

  printf("  +");
  for (i=0; i<size-1; i++) {
    printf("----");
  }
  printf("--+\n");

  printf("HP:%d\n", player[0].hp);
  if (player[0].position_x==size-1 && player[0].position_y==size-1) {
    player[0].clear_flag = TRUE;
  }

  return player[0].hp;
}

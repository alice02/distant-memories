#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 16 /* 4の倍数が望ましい... */

struct parameter {
  int position_x;
  int position_y;
  int hp;
  int clear_flag;
  int play_mode;
  int stage;
  int pass_flag[MAX_SIZE][MAX_SIZE];
  int bomb[MAX_SIZE][MAX_SIZE];
};

void initialize(struct parameter player[], int ct);
void disp_map(struct parameter player[]);
void input_key(struct parameter player[]);
void menu(struct parameter player[]);

int main(void)
{
  struct parameter player[1];

  srand((unsigned)time(NULL));

  int ct = 1;

  menu(player);

  disp_map(player);

  while (ct <= 3) {
    initialize(player, ct);  
    while(player[0].hp > 0) {
      if (player[0].clear_flag == TRUE) {
	printf("GOAL!!!!\n");
	exit(0);
      }
      input_key(player);
      disp_map(player);
    }
    ct++;
  }

  printf("GAME OVER....\n");

  return 0;
}

void menu(struct parameter player[])
{

  char buf[BUFSIZ], tmp[BUFSIZ];
  int n;

  printf("\x1b[2J");

  printf("*********************\n");
  printf("*     MAIN MENU     *\n");
  printf("*                   *\n");
  printf("*  1.NOMAL PLAY     *\n");
  printf("*  2.DEBUG MODE     *\n");
  printf("*  3.CHEAT MODE     *\n");
  printf("*                   *\n");
  printf("*********************\n");


  while (1) {
    printf("SELECT PLAY MODE : ");
    fgets(buf, BUFSIZ, stdin);
    n = sscanf(buf, "%d%s", &player[0].play_mode, tmp);
    if (1 <= player[0].play_mode && player[0].play_mode <= 3 && n == 1) {
      break;
    }
    else {
      printf("INPUT ERROR!!\n");
    }
  }

  if (player[0].play_mode == 1) {
    player[0].stage = 1;
  }
  else if (player[0].play_mode == 2) {
    while (1) {
      printf("PLEASE INPUT STAGE : ");
      fgets(buf, BUFSIZ, stdin);
      n = sscanf(buf, "%d%s", &player[0].stage, tmp);
      if (1 <= player[0].stage && player[0].stage <= 3 && n == 1) {
	break;
      }
      else {
	printf("INPUT ERROR!!\n");
      }
    }
  }

}

void input_key(struct parameter player[])
{
  char buf[BUFSIZ], tmp[BUFSIZ];
  int key, n, size;

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
    n = sscanf(buf, "%d%s", &key, tmp);
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
      printf("INPUT ERROR!!\n");
    }
  }

  if (key == 2 && player[0].position_y==size-1) {
    input_key(player);
  }
  else if (key == 4 && player[0].position_x == 0) {
    input_key(player);
  }
  else if (key == 6 && player[0].position_x == size-1) {
    input_key(player);
  }
  else if (key == 8 && player[0].position_y == 0) {
    input_key(player);
  }
  else  if (key == 2) {
    player[0].position_y ++;
  }
  else if (key == 4) {
    player[0].position_x --;
  }
  else if (key == 6) {
    player[0].position_x ++;
  }
  else if (key == 8) {
    player[0].position_y --;
  }

}

 void initialize(struct parameter player[], int ct)
{
  int i, j;

  player[0].position_x = 0;
  player[0].position_y = 0;
  player[0].hp = 1000;
  player[0].clear_flag = FALSE;
  player[0].stage = ct;

  for (i=0; i<MAX_SIZE; i++) {
    for (j=0; j<MAX_SIZE; j++) {
      player[0].pass_flag[j][i] = FALSE;
    }
  }

  for (i=0; i<MAX_SIZE; i++) {
    for (j=0; j<MAX_SIZE; j++) {
      if (rand()%100<40) {
	player[0].bomb[j][i] = TRUE;
      }
    }
  }

}

void disp_map(struct parameter player[])
{
  int i, j, size;

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

  printf("*****************\n");
  printf("*    STAGE %d    *\n", player[0].stage);
  printf("*****************\n\n");

  printf(" ");
  for (i=0; i<size; i++) {
    printf("%4d", i);
  }

  printf("\n  +");
  for (i=0; i<(size-1); i++) {
    printf("----");
  }
  printf("--+\n");

  for (i=0; i<size; i++) {
    printf("%2d|", i);
    for (j=0; j<size; j++) {
      if (player[0].position_x == j && player[0].position_y == i) {
	printf("\x1b[34m");
	printf("@@");
	printf("\x1b[0m");
	if (player[0].bomb[j][i] == TRUE) {
	  player[0].hp -= rand()%3 * 100;
	  player[0].bomb[j][i] = FALSE;
	}
	player[0].pass_flag[j][i] = TRUE;
      }
      else if (player[0].pass_flag[j][i] == TRUE) {
	printf("  ");
      }
      else if (player[0].play_mode == 3 && player[0].bomb[j][i] == TRUE) {
	printf("\x1b[31m");
	printf("**");
	printf("\x1b[0m");
      }
      else {
	printf("**");
      }

      if (j<size-1) {
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

  if (player[0].pass_flag[size-1][size-1] == TRUE) {
    player[0].clear_flag = TRUE;
  }
}


#include <stdio.h>
#include <string.h>
#include "robots.h"

void disp_field(struct zahyou *r_header, struct zahyou player, struct zahyou *s_header)
{
  struct zahyou *r_now;
  struct zahyou *s_now;
  int i, j, flag;

  /* 上枠 */
  printf("\n\n+");
  for (i = 0; i < X_SIZE; i++) {
    printf("-");
  }
  printf("+\n");

  for (i = 0; i < Y_SIZE; i++) {
    printf("|");
    for (j = 0; j < X_SIZE; j++) {
      flag = FALSE;
      r_now = r_header->next;
      s_now = s_header->next;

      /* プレイヤの位置を表示 */
      if (player.x == j && player.y == i) {
	printf("@");
	flag = TRUE;
      }

      /* ロボットの位置を表示 */
      while (r_now != NULL) {
	if (flag == FALSE && r_now->x == j && r_now->y == i) {
	  printf("+");
	  flag = TRUE;
	}
	r_now = r_now->next;
      }

      /* スクラップの位置を表示 */
      while (s_now != NULL) {
	if (flag == FALSE && s_now->x == j && s_now->y == i) {
	  printf("*");
	  flag = TRUE;
	}
	s_now = s_now->next;
      }

      /* 何も無いところは空白 */
      if (flag == FALSE) {
	printf(" ");
      }
    }
    printf("|\n");
  }

  /* 下枠 */
  printf("+");
  for (i = 0; i < X_SIZE; i++) {
    printf("-");
  }
  printf("+\n");

}


void game_over(void)
{
  int i;
  char str[] = "AARRrrgghhhh....";

  /* strの中身を一文字ずつ表示 */
  printf("\n\n");
  for (i = 0; str[i] != '\0'; i++) {
    printf("%c", str[i]);
    usleep(100000);	/* エフェクト用usleep */
    fflush(NULL);
  }
  usleep(400000);	/* エフェクト用usleep */
  printf("\n\n");
  sleep(1);
}


void stage_clear(void)
{
  int i;
  char str[] = "Yahoo!!";

  /* strの中身を一文字ずつ表示 */
  printf("\n\n");
  for (i = 0; str[i] != '\0'; i++) {
    printf("%c", str[i]);
    usleep(100000);	/* エフェクト用usleep */
    fflush(NULL);
  }
  usleep(400000);	/* エフェクト用usleep */
  printf("\n\nGo to next level...\n");
  usleep(700000);	/* エフェクト用usleep */
}



#include <stdio.h>
#include <string.h>
#include "robots.h"

void disp_field(struct zahyou *r_header, struct zahyou player, struct zahyou *s_header)
{
  struct zahyou *r_now;
  struct zahyou *s_now;
  int i, j, flag;

  /* ���� */
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

      /* �ץ쥤��ΰ��֤�ɽ�� */
      if (player.x == j && player.y == i) {
	printf("@");
	flag = TRUE;
      }

      /* ��ܥåȤΰ��֤�ɽ�� */
      while (r_now != NULL) {
	if (flag == FALSE && r_now->x == j && r_now->y == i) {
	  printf("+");
	  flag = TRUE;
	}
	r_now = r_now->next;
      }

      /* ������åפΰ��֤�ɽ�� */
      while (s_now != NULL) {
	if (flag == FALSE && s_now->x == j && s_now->y == i) {
	  printf("*");
	  flag = TRUE;
	}
	s_now = s_now->next;
      }

      /* ����̵���Ȥ���϶��� */
      if (flag == FALSE) {
	printf(" ");
      }
    }
    printf("|\n");
  }

  /* ���� */
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

  /* str����Ȥ��ʸ������ɽ�� */
  printf("\n\n");
  for (i = 0; str[i] != '\0'; i++) {
    printf("%c", str[i]);
    usleep(100000);	/* ���ե�������usleep */
    fflush(NULL);
  }
  usleep(400000);	/* ���ե�������usleep */
  printf("\n\n");
  sleep(1);
}


void stage_clear(void)
{
  int i;
  char str[] = "Yahoo!!";

  /* str����Ȥ��ʸ������ɽ�� */
  printf("\n\n");
  for (i = 0; str[i] != '\0'; i++) {
    printf("%c", str[i]);
    usleep(100000);	/* ���ե�������usleep */
    fflush(NULL);
  }
  usleep(400000);	/* ���ե�������usleep */
  printf("\n\nGo to next level...\n");
  usleep(700000);	/* ���ե�������usleep */
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "robots.h"


int main(int argc, char *argv[])
{
  struct zahyou Rlist_header;	/* ��ܥåȤκ�ɸ(Ϣ��ꥹ��) */
  struct zahyou *Rlist_last;
  struct zahyou Slist_header;	/* ������åפκ�ɸ(Ϣ��ꥹ��) */
  struct zahyou *Slist_last;
  struct zahyou player;		/* �ץ쥤��κ�ɸ */
  int level = 1;	/* �ץ쥤���Ƥ����٥�(�����:1) */
  int robots_num;	/* �ץ쥤���Ƥ����٥�ǤΥ�ܥåȤθĿ��ν���� */
  int remaining;	/* �Ĥ�Υ�ܥåȿ� */
  int score = 0;	/* ������ */
  int wait_flag;	/* 'w'�����򲡤�������ư���ѹ��ѥե饰 */
  int val, judge;	/* ����ͤ��Ǽ�����ѿ� */

  
  /* ������ɽ���⡼�� (-s)*/
  if (argc-1 == 1) {
    if (argv[1][0] == '-' && argv[1][1] == 's') {
      print_score();
      exit(0);
    }
  }

  srand((unsigned)time(NULL)); 

  do {
    /* �ꥹ�Ȥν���� */
    Rlist_header.next = NULL;
    Rlist_last = &Rlist_header;
    Slist_header.next = NULL;
    Slist_last = &Slist_header;

    /* ����� */
    initialization(&Rlist_header, Rlist_last, &player, level, &robots_num, &remaining);
    wait_flag = FALSE;

    /* �ᥤ��롼�� */
    do {

      disp_field(&Rlist_header, player, &Slist_header); /* �ե�����ɤ�ɽ�� */
      if (wait_flag == TRUE) {
	usleep(100000);
      }

      printf("(level:%d, score:%d):?", level, score); /* ��٥롢��������ɽ�� */

      if (wait_flag == FALSE) {
	val = move_player(&player, &Rlist_header, &Slist_header); /* �ץ쥤��ΰ�ư */
      }

      if (val == NORMAL) {
	move_robots(&Rlist_header, player); /* ��ܥåȤΰ�ư */
      }
      else if (val == WAIT_FOR_END) {
	wait_flag = TRUE;
	val = NORMAL;
      }

      judge = crash_judge(&Rlist_header, player, &Slist_header, Slist_last, robots_num, &remaining, &score); /* ����Ƚ�� */

    } while (judge == ALIVE && remaining != 0);

    /* �����९�ꥢ�ξ�� */
    if (judge == ALIVE) {
      score += level*10;	/* �������ι��� */
      level++;			/* ��٥�ι��� */
      stage_clear();		/* ��å�������ɽ�� */
    }
    /* �����४���С��ξ�� */
    else {
      game_over();		/* ��å�������ɽ�� */
    }

  } while (judge == ALIVE);

  save_score(score, level);

  return 0;
}

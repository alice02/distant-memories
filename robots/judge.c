#include <stdio.h>
#include <stdlib.h>
#include "robots.h"

int crash_judge(struct zahyou *r_header, struct zahyou player, struct zahyou *s_header, struct zahyou *s_last, int r_num, int *remaining, int *score)
{
  struct zahyou *now_j, *now_i, *scrap;
  int retval, count, r_flag , s_flag;
  int index_x[r_num], index_y[r_num];
  int i, j;

  count = 0;
  r_flag = FALSE;
  now_i = r_header->next;

  while (now_i != NULL) {

    now_j = r_header->next;
    /* ロボットがぶつかった場所の判定 */
    while (now_j != NULL) {
 
      /* プレイヤとぶつかった時 */
      if (now_j->x == player.x && now_j->y == player.y) {
	return 1;
      }

      /* ロボット同士がぶつかった時 */
      if (now_j->x == now_i->x && now_j->y == now_i->y && now_j != now_i) {
	for (i = 0; i < count; i++) {
	  if (index_x[i] == now_j->x && index_y[i] == now_j->y) {
	    r_flag = TRUE;
	  }
	}
	if (r_flag == FALSE) {
	  index_x[count] = now_j->x;
	  index_y[count] = now_j->y;
	  count++;
	}
      }
      now_j = now_j->next;
    }
    now_i = now_i->next;
  }


  /* ロボット同士がぶつかったら、ロボットを削除してスクラップを設置 */
  for (i = 0; i < count; i++) {
    for (j = 0; j < r_num; j++) {
      retval = delete_robots(r_header, index_x[i], index_y[i]);
      if (retval == 1) {
	(*remaining)--;
	(*score)++;
      }
    }
    s_last = set_scrap(s_last, index_x[i], index_y[i]);
  }
  

  /* スクラップにぶつかった時の処理 */
  now_i = r_header->next;
  while (now_i != NULL) {
    scrap = s_header->next;
    s_flag = FALSE;
    while (scrap != NULL) {
      if (scrap->x == now_i->x && scrap->y == now_i->y) {
	retval = delete_robots(r_header, now_i->x, now_i->y);
	if (retval == 1) {
	  (*remaining)--;
	  (*score)++;
	}
	s_flag = TRUE;
      }
      scrap = scrap->next;
    }
    if (s_flag == TRUE) {
      break;
    }
    now_i = now_i->next;
  }


  return 0;
}


/* 指定した座標にいるロボットを探して削除 */
int delete_robots(struct zahyou *header, int x, int y)
{
  struct zahyou *now;
  struct zahyou *delete;
  int i_ret = 0;

  now = header;

  while (now->next != NULL && (now->next->x != x || now->next->y != y)) {
    now = now->next;
  }

  if (now->next != NULL) {
    delete = now->next;
    now->next = delete->next;
    free(delete);
    i_ret = 1;
  }

  return i_ret;
}


/* 実際にスクラップを設置する */
struct zahyou *set_scrap(struct zahyou *tmp, int x, int y)
{
  struct zahyou *p;

  p = (struct zahyou *)malloc(sizeof(struct zahyou) * 1);

  if (p == NULL) {
    printf("ERROR: memory full.\n");
    exit(1);
  }

  p->x = x;
  p->y = y;

  p->next = tmp->next;
  tmp->next = p;

  return p;
}

#include <stdio.h>
#include <stdlib.h>
#include "robots.h"


/* 初期化関数 */
void initialization(struct zahyou *header, struct zahyou *last, struct zahyou *player, int level, int *r_num, int *remaining)
{
  int table[Y_SIZE][X_SIZE] = {FALSE}; /* ロボットが配置された場所を記憶しておく配列 */
  int i;

  *r_num = *remaining = min(level*5, 40);

  for (i = 0; i < *r_num; i++) {
    last = set_robots(last, table);
  }

  player->x = rand()%X_SIZE;
  player->y = rand()%Y_SIZE;

}


/* ロボットを設置する */
struct zahyou *set_robots(struct zahyou *x, int table[][X_SIZE])
{
  struct zahyou *p;
  int flag;

  p = (struct zahyou *)malloc(sizeof(struct zahyou) * 1);

  if (p == NULL) {
    printf("ERROR: memory full.\n");
    exit(1);
  }

  do {
    flag = FALSE;
    p->x = rand()%X_SIZE;
    p->y = rand()%Y_SIZE;
    if (table[p->y][p->x] == TRUE) {
      flag = TRUE;
    }
    else {
      table[p->y][p->x] = TRUE;
    }
  } while (flag == TRUE);

  p->next = x->next;
  x->next = p;

  return p;
}


/* 引数の大小を比べる */
int min(int a, int b)
{

  if (a < b) {
    return a;
  }
  else {
    return b;
  }

}

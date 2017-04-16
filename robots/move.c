#include <stdio.h>
#include "robots.h"

/* プレイヤの移動 */
int move_player(struct zahyou *player, struct zahyou *r_header, struct zahyou *s_header)
{
  struct zahyou *now;
  int i_ret = NORMAL;
  char ch;

  now = s_header->next;

  ch = getChar();		/* 文字入力 */
  printf("\n");

  switch(ch) {
  case '1':			/* 左斜め下 */
    /* 進みたい方向にスクラップがある場合は進めない */
    while (now != NULL) {
      if (player->x-1 == now->x && player->y+1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* フィールドの端にいると進めない */
    if (player->x < 1 || player->y >= Y_SIZE-1) {
      i_ret = 1;
    } else if (i_ret != 1) {
      player->x--;
      player->y++;
    }
    break;

  case '2':			/* 下 */
    /* 進みたい方向にスクラップがある場合は進めない */
    while (now != NULL) {
      if (player->x == now->x && player->y+1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* フィールドの端にいると進めない */
    if (player->y >= Y_SIZE-1) {
      i_ret = 1;
    } else if (i_ret != 1) {
      player->y++;
    }
    break;

  case '3':			/* 右斜め下 */
    /* 進みたい方向にスクラップがある場合は進めない */
    while (now != NULL) {
      if (player->x+1 == now->x && player->y+1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* フィールドの端にいると進めない */
    if (player->x >= X_SIZE-1 || player->y >= Y_SIZE-1) {
      i_ret = 1;
    } else if (i_ret != 1) {
      player->x++;
      player->y++;
    }
    break;

  case '4':			/* 左 */
    /* 進みたい方向にスクラップがある場合は進めない */
    while (now != NULL) {
      if (player->x-1 == now->x && player->y == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* フィールドの端にいると進めない */
    if (player->x < 1) {
      i_ret = 1;
    } else if (i_ret != 1) {
      player->x--;
    }
    break;

  case '5':			/* 待つ */
    break;

  case '6':			/* 右 */
    /* 進みたい方向にスクラップがある場合は進めない */
    while (now != NULL) {
      if (player->x+1 == now->x && player->y == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* フィールドの端にいると進めない */
    if (player->x >= X_SIZE-1) {
      i_ret = 1;
    } else if (i_ret != 1) {     
      player->x++;
    }
    break;

  case '7':			/* 左斜め上 */
    /* 進みたい方向にスクラップがある場合は進めない */
    while (now != NULL) {
      if (player->x-1 == now->x && player->y-1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* フィールドの端にいると進めない */
    if (player->x < 1 || player->y < 1) {
      i_ret = 1;
    } else {
      player->x--;
      player->y--;
    }
    break;

  case '8':			/* 上 */
    /* 進みたい方向にスクラップがある場合は進めない */
    while (now != NULL) {
      if (player->x == now->x && player->y-1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* フィールドの端にいると進めない */
    if (player->y < 1) {
      i_ret = 1;
    } else {
      player->y--;
    }
    break;

  case '9':			/* 右斜め上 */
    /* 進みたい方向にスクラップがある場合は進めない */
    while (now != NULL) {
      if (player->x+1 == now->x && player->y-1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* フィールドの端にいると進めない */
    if (player->x >= X_SIZE-1 || player->y < 1) {
      i_ret = 1;
    } else {
      player->x++;
      player->y--;
    }
    break;

  case '0':			/* テレポート */
    teleport(player, r_header, s_header);
    break;

  case 'w':			/* どちらかが死ぬまで待機 */
    i_ret = WAIT_FOR_END;
    break;

  default:
    i_ret = 1;
    break;
  }

  return i_ret;
}

/* ロボットの移動 */
void move_robots(struct zahyou *header, struct zahyou player)
{
  struct zahyou *now;
  now =  header->next;

  while (now != NULL) {
    if (now->x < player.x) {
      now->x++;
    }else if (now->x > player.x) {
      now->x--;
    }
    if (now->y < player.y) {
      now->y++;
    }else if (now->y > player.y) {
      now->y--;
    }
    now = now->next;
  }
}


/* テレポート */
void teleport(struct zahyou *player, struct zahyou *robo_header, struct zahyou *scrap_header)
{
  struct zahyou *now;
  int x, y, flag;

  /* すでにロボット・スクラップのある場所にはテレポートできないようにする */
  do {
    flag = FALSE;
    x = rand()%X_SIZE;
    y = rand()%Y_SIZE;
    now = robo_header;
    while (now != NULL) {
      if (now->x == x && now->y == y) {
	flag = TRUE;
      }
      now = now->next;
    }

    now = scrap_header;
    while (now != NULL) {
      if (now->x == x && now->y == y) {
	flag = TRUE;
      }
      now = now->next;
    }
  } while (flag == TRUE);

  player->x = x;
  player->y = y;

}

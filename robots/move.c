#include <stdio.h>
#include "robots.h"

/* �ץ쥤��ΰ�ư */
int move_player(struct zahyou *player, struct zahyou *r_header, struct zahyou *s_header)
{
  struct zahyou *now;
  int i_ret = NORMAL;
  char ch;

  now = s_header->next;

  ch = getChar();		/* ʸ������ */
  printf("\n");

  switch(ch) {
  case '1':			/* ���Ф᲼ */
    /* �ʤߤ��������˥�����åפ�������Ͽʤ�ʤ� */
    while (now != NULL) {
      if (player->x-1 == now->x && player->y+1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* �ե�����ɤ�ü�ˤ���ȿʤ�ʤ� */
    if (player->x < 1 || player->y >= Y_SIZE-1) {
      i_ret = 1;
    } else if (i_ret != 1) {
      player->x--;
      player->y++;
    }
    break;

  case '2':			/* �� */
    /* �ʤߤ��������˥�����åפ�������Ͽʤ�ʤ� */
    while (now != NULL) {
      if (player->x == now->x && player->y+1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* �ե�����ɤ�ü�ˤ���ȿʤ�ʤ� */
    if (player->y >= Y_SIZE-1) {
      i_ret = 1;
    } else if (i_ret != 1) {
      player->y++;
    }
    break;

  case '3':			/* ���Ф᲼ */
    /* �ʤߤ��������˥�����åפ�������Ͽʤ�ʤ� */
    while (now != NULL) {
      if (player->x+1 == now->x && player->y+1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* �ե�����ɤ�ü�ˤ���ȿʤ�ʤ� */
    if (player->x >= X_SIZE-1 || player->y >= Y_SIZE-1) {
      i_ret = 1;
    } else if (i_ret != 1) {
      player->x++;
      player->y++;
    }
    break;

  case '4':			/* �� */
    /* �ʤߤ��������˥�����åפ�������Ͽʤ�ʤ� */
    while (now != NULL) {
      if (player->x-1 == now->x && player->y == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* �ե�����ɤ�ü�ˤ���ȿʤ�ʤ� */
    if (player->x < 1) {
      i_ret = 1;
    } else if (i_ret != 1) {
      player->x--;
    }
    break;

  case '5':			/* �Ԥ� */
    break;

  case '6':			/* �� */
    /* �ʤߤ��������˥�����åפ�������Ͽʤ�ʤ� */
    while (now != NULL) {
      if (player->x+1 == now->x && player->y == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* �ե�����ɤ�ü�ˤ���ȿʤ�ʤ� */
    if (player->x >= X_SIZE-1) {
      i_ret = 1;
    } else if (i_ret != 1) {     
      player->x++;
    }
    break;

  case '7':			/* ���Ф�� */
    /* �ʤߤ��������˥�����åפ�������Ͽʤ�ʤ� */
    while (now != NULL) {
      if (player->x-1 == now->x && player->y-1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* �ե�����ɤ�ü�ˤ���ȿʤ�ʤ� */
    if (player->x < 1 || player->y < 1) {
      i_ret = 1;
    } else {
      player->x--;
      player->y--;
    }
    break;

  case '8':			/* �� */
    /* �ʤߤ��������˥�����åפ�������Ͽʤ�ʤ� */
    while (now != NULL) {
      if (player->x == now->x && player->y-1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* �ե�����ɤ�ü�ˤ���ȿʤ�ʤ� */
    if (player->y < 1) {
      i_ret = 1;
    } else {
      player->y--;
    }
    break;

  case '9':			/* ���Ф�� */
    /* �ʤߤ��������˥�����åפ�������Ͽʤ�ʤ� */
    while (now != NULL) {
      if (player->x+1 == now->x && player->y-1 == now->y) {
	i_ret = 1;
	break;
      }
      now = now->next;
    }
    /* �ե�����ɤ�ü�ˤ���ȿʤ�ʤ� */
    if (player->x >= X_SIZE-1 || player->y < 1) {
      i_ret = 1;
    } else {
      player->x++;
      player->y--;
    }
    break;

  case '0':			/* �ƥ�ݡ��� */
    teleport(player, r_header, s_header);
    break;

  case 'w':			/* �ɤ��餫����̤ޤ��Ե� */
    i_ret = WAIT_FOR_END;
    break;

  default:
    i_ret = 1;
    break;
  }

  return i_ret;
}

/* ��ܥåȤΰ�ư */
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


/* �ƥ�ݡ��� */
void teleport(struct zahyou *player, struct zahyou *robo_header, struct zahyou *scrap_header)
{
  struct zahyou *now;
  int x, y, flag;

  /* ���Ǥ˥�ܥåȡ�������åפΤ�����ˤϥƥ�ݡ��ȤǤ��ʤ��褦�ˤ��� */
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

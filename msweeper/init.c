#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include "msweeper.h"


/* ����� */
void init(PARAMETER *data)
{
  data->open_count = 0;         /* �ޤ��ե�����ɤ�1�ĤⳫ����Ƥ��ʤ� */

  data->mflag_count = 0;	/* �ޤ�m�ޡ�����Ĥ��Ƥ��ʤ� */

  data->dead_flag = ALIVE;      /* �����ޤ�Ƨ��Ǥʤ� */

  init_curses();		/* curses�ν���� */

  level_select(data);		/* �ץ쥤�����٥������ */

  allocate_field(data);		/* ����γ��� */

  set_mines(data);		/* ����Υ��å� */

  set_value_and_flag(data);	/* ���������θĿ����ե�����ɥե饰�򥻥å� */
}

/* �ܡ��ɤ��礭����M�θĿ��λ���*/
void level_select(PARAMETER *data)
{
  char ch;

  do {
    disp_level_select();
    do{
      printw("Please select level:");
      refresh();
      ch = getChar();
      printw("\n");
    } while( ch!='1' && ch!='2' && ch != '3' && ch != '4' && ch != '5');

    switch(ch) {
    case '1':
      set_values(data, 9, 9, 10);
      data->play_level = BEGINNING;
      break;
    case '2':
      set_values(data, 16, 16, 40);
      data->play_level = INTERMEDIATE;
      break;
    case '3':
      set_values(data, 30, 16, 99);
      data->play_level = ADVANCED;
      break;
    case '4':
      set_custom(data);
      data->play_level = CUSTOM;
      break;
    case '5':
      disp_record();
      break;
    default:
      printf("Error\n");
      exit(1);
      break;
    }
  } while (ch == '5');
}

/* �����Ǽ�����ä��ͤ򥻥åȤ��� */
void set_values(PARAMETER *data, int x, int y, int num)
{
  data->x_size = x;
  data->y_size = y;
  data->mines = num;
}

/* ������������������ϲ��� */
void set_custom(PARAMETER *data)
{
  int num;

  do {
    printw("�⤵ (9~24):");  refresh();
    scanw("%d", &data->y_size);
  } while (data->y_size < 9 || data->y_size > 24);

  do {
    printw("�� (9~30):");  refresh();
    scanw("%d", &data->x_size);
  } while (data->x_size < 9 || data->x_size > 30);

  num = (data->x_size-1)*(data->y_size-1);

  do{
    printw("����ο� (10~%d):", num);  refresh();
    scanw("%d", &data->mines);
  } while (data->mines < 10 || data->mines > num);
}

/* ����γ��� */
void allocate_field(PARAMETER *data)
{
  int i, j;

  data->field = (int **)malloc(sizeof(int *) * data->y_size);
  data->field_flag = (int **)malloc(sizeof(int *) * data->y_size);
  for (i = 0; i < data->y_size; i++) {
    data->field[i] = (int *)malloc(sizeof(int) * data->x_size);
    data->field_flag[i] = (int *)malloc(sizeof(int) * data->x_size);
  }

  for (i = 0; i < data->y_size; i++) {
    for (j = 0; j < data->x_size; j++) {
      data->field[i][j] = 0;
    }
  }

}

/* ����Υ��å� */
void set_mines(PARAMETER *data)
{
  int *table;
  int num, val, tmp, count = 0;
  int i;

  srand((unsigned)time(NULL));  /* ����μ�򥻥å� */

  num = (data->x_size) * (data->y_size);

  table = (int *)malloc(sizeof(int) * num); /* ���������γ��� */

  for (i = 0; i < num; i++) {
    table[i] = i;
  }

  /* ��ʣ�Τʤ��褦�˥ե�����ɤ�����򥻥å� */
  for (i = num; count < data->mines; i--) {
    tmp = rand() % i;
    val = table[tmp];
    table[tmp] = table[i-1];
    data->field[(val/(data->x_size))%(data->x_size)][val%(data->y_size)] = MINE;
    count++;
  }

}

/* ���������θĿ����ե�����ɥե饰�򥻥å� */
void set_value_and_flag(PARAMETER *data)
{
  int i, j;

  for (i = 0; i < data->y_size; i++) {
    for (j = 0; j < data->x_size; j++) {
      if (CHKFIELD(data, j, i) != MINE) {
	data->field[i][j] = check_around_mines(data, j, i);
      }
      data->field_flag[i][j] = CLOSE;
    }
  }
}

/* ���ꤷ���������뤬���뤫��ǧ���� */
int check_mine(PARAMETER *data, int x, int y, int i, int j)
{
  int tmp_x, tmp_y, ret = 0;
  
  tmp_x = x + i;
  tmp_y = y + j;
  
  if (0 <= tmp_x && tmp_x < data->x_size && 0 <= tmp_y && tmp_y < data->y_size) {
    if (CHKFIELD(data, tmp_x, tmp_y) == MINE) {
      ret = 1;
    }
  }

  return ret;
}

/* ���ꤷ�����μ���8�ս������θĿ���׻� */
int check_around_mines(PARAMETER *data, int x, int y)
{
  int count = 0;

  count += check_mine(data, x, y,-1,-1);
  count += check_mine(data, x, y, 0,-1);
  count += check_mine(data, x, y, 1,-1);
  count += check_mine(data, x, y,-1, 0);
  count += check_mine(data, x, y, 1, 0);
  count += check_mine(data, x, y,-1, 1);
  count += check_mine(data, x, y, 0, 1);
  count += check_mine(data, x, y, 1, 1);

  return count;
}

/* ����򥻥åȤ��ʤ���(�ǽ�������Ƨ����Ȥ���) */
void refresh_field(PARAMETER *data, int x, int y)
{
  int i, j, tmpx, tmpy, flag, count = 0;
  int x_index[9], y_index[9];

  srand((unsigned)time(NULL));   /* ����μ����� */

  for (j = -1; j <= 1; j++) {
    for (i = -1; i <= 1; i++) {
      x_index[count] = x + i;
      y_index[count] = y + j;
      count++;
    }
  }

  for (j = 0; j < data->y_size; j++) {
    for (i = 0; i < data->x_size; i++) {
      data->field[j][i] = 0;
    }
  }

  for (i = 0; i < data->mines; i++) {
    do {
      flag = FALSE;
      tmpx = (rand() % data->x_size);
      tmpy = (rand() % data->y_size);
      for (j = 0; j < 9; j++) {
	if (x_index[j] == tmpx && y_index[j] == tmpy) {
	  flag = TRUE;
	}
      }
    } while (CHKFIELD(data, tmpx, tmpy) == MINE || flag == TRUE);

    data->field[tmpy][tmpx] = MINE;
  }

  set_value_and_flag(data);
}

/* curses�ν���� */
void init_curses(void)
{
  initscr();
  echo();
  nonl();
  keypad(stdscr, TRUE);
  intrflush(stdscr, FALSE);
}

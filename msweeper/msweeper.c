#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include "msweeper.h"


/* �ᥤ��롼�� */
void msweeper(PARAMETER *data)
{
  time_t start, end;
  int x, y, num, oldc;

  x = y = EDGE;
  num = data->x_size * data->y_size - data->mines;

  clear();

  time(&start); 		/* �������¬���� */
  while(data->open_count != num && data->dead_flag == ALIVE){
    draw_field(data);
    draw_cursor(data, x, y, &oldc);
    key_proc(data, &x, &y, &oldc);
    cursor_range_limit(data, &x, &y);
    draw_cursor(data, x, y, &oldc);
    clear();
  }
  time(&end);			/* �������¬��λ */

  judge(data, (int)difftime(end, start));

  my_free(data);
}

/* field[y+j][x+i]��������ϰ���ʤ鳫�� */
void range_limit(PARAMETER *data, int x, int y, int i, int j)
{
  int tmp_x, tmp_y;

  tmp_x = x + i;
  tmp_y = y + j;

  if (0 <= tmp_x && tmp_x < data->x_size &&
      0 <= tmp_y && tmp_y < data->y_size) {
    if (CHKFIELDFLAG(data, tmp_x, tmp_y) != OPEN) {
      if (CHKFIELDFLAG(data, tmp_x, tmp_y) == MFLAG) {
	return;
      }
      else if (CHKFIELD(data, tmp_x, tmp_y) == MINE) {
	data->dead_flag = DEAD;
      }
      else {
	open_field(data, tmp_x, tmp_y);
      }
    }
  }
}

/* �ե�����ɤ򳫤����� */
void open_field(PARAMETER *data, int x, int y)
{
  if (CHKFIELDFLAG(data, x, y) == MFLAG) {
    return;
  }
  if (CHKFIELD(data, x, y) == MINE) {
    data->dead_flag = DEAD;
  }

  if (CHKFIELDFLAG(data, x, y) == CLOSE) {
    data->open_count++;
  }

  data->field_flag[y][x] = OPEN;

  if (CHKFIELD(data, x, y) == 0) {
    range_limit(data, x, y,-1,-1);
    range_limit(data, x, y, 0,-1);
    range_limit(data, x, y, 1,-1);
    range_limit(data, x, y,-1, 0);
    range_limit(data, x, y, 1, 0);
    range_limit(data, x, y,-1, 1);
    range_limit(data, x, y, 0, 1);
    range_limit(data, x, y, 1, 1);
  }
}

/* ���ꤷ������M�ޡ��������뤫��ǧ���� */
int check_mflag(PARAMETER *data, int x, int y, int i, int j)
{
  int tmp_x, tmp_y, val = 0;
  
  tmp_x = x + i;
  tmp_y = y + j;
  
  if (0 <= tmp_x && tmp_x < data->x_size &&
      0 <= tmp_y && tmp_y < data->y_size) {
    if (CHKFIELDFLAG(data, tmp_x, tmp_y) == MFLAG) {
      val = 1;
    }
  }

  return val;
}

/* M�ޡ����ο��ȼºݤ� M �ο������פ������μ��Ϥ�Ⱦ��ư�ǳ��� */
void agree_around_flags(PARAMETER *data, int x, int y)
{
  int count = 0;

  if (CHKFIELDFLAG(data, x, y) == MFLAG) {
    return;
  }
  if (CHKFIELD(data, x, y) == MINE) {
    data->dead_flag = DEAD;
  }

  count += check_mflag(data, x, y,-1,-1);
  count += check_mflag(data, x, y, 0,-1);
  count += check_mflag(data, x, y, 1,-1);
  count += check_mflag(data, x, y,-1, 0);
  count += check_mflag(data, x, y, 1, 0);
  count += check_mflag(data, x, y,-1, 1);
  count += check_mflag(data, x, y, 0, 1);
  count += check_mflag(data, x, y, 1, 1);

  if (CHKFIELD(data, x, y) == count) {
    range_limit(data, x, y,-1,-1);
    range_limit(data, x, y, 0,-1);
    range_limit(data, x, y, 1,-1);
    range_limit(data, x, y,-1, 0);
    range_limit(data, x, y, 1, 0);
    range_limit(data, x, y,-1, 1);
    range_limit(data, x, y, 0, 1);
    range_limit(data, x, y, 1, 1);
  }
}

/* �ե饰�򥻥åȡ��ޤ��ϥꥻ�åȤ��� */
void set_flag(PARAMETER *data, int x, int y, int flag)
{
  if (CHKFIELDFLAG(data, x, y) == CLOSE) {
    data->field_flag[y][x] = flag;
    if (flag == MFLAG) {
      data->mflag_count++;
    }
  }
  else if (CHKFIELDFLAG(data, x, y) == flag) {
    data->field_flag[y][x] = CLOSE;
    if (flag == MFLAG) {
      data->mflag_count--;
    }
  }
}

/* ��ȥ饤���뤫�Ҥͤ� */
int retry(void)
{
  char ch;

  do{
    printw( "\n³���ޤ���?(y/n)" );
    refresh();
    ch = getChar();
  } while( ch!='y' && ch!='n' );

  if(ch == 'y') {
    return 1;
  }

  return 0;
}

/* ���Ԥˤ�äƥ�å�������ɽ�� */
void judge(PARAMETER *data, int time)
{
  if (data->dead_flag == ALIVE) {
    game_clear(time);
    save_record(time, data->play_level);
  } else {
    game_over();
  }
}

/* ����γ��� */
void my_free(PARAMETER *data)
{
  int i;
  
  for (i = 0; i < data->y_size; i++) {
   free(data->field[i]);
   free(data->field_flag[i]);
  }
  free(data->field);
  free(data->field_flag);
}

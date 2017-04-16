#include <curses.h>
#include "msweeper.h"


/* カーソルの表示 */
void draw_cursor(PARAMETER *data, int x, int y, int *oldc)
{
  char tmp;

  if (CHKFIELDFLAG(data, x-EDGE, y-EDGE) == MFLAG ||
      CHKFIELDFLAG(data, x-EDGE, y-EDGE) == QFLAG) {
    tmp = flag_2_char(data->field_flag[y-EDGE][x-EDGE]);
  } else if (CHKFIELDFLAG(data, x-EDGE, y-EDGE) == OPEN) {
    if (CHKFIELD(data, x-EDGE, y-EDGE) == 0) {
      tmp = ' ';
    } else {
      tmp = data->field[y-EDGE][x-EDGE] + '0';
    }
  } else {
    tmp = '.';
  }

  move(y, x*2-EDGE);
  *oldc = inch();
  delch();
  insch(tmp);
  refresh();
}

/* フラグから文字に変換 */
char flag_2_char(int flag)
{
  char ch;

  switch(flag) {
  case MFLAG:
    ch = 'm';  break;
  case QFLAG:
    ch = '?';  break;      
  default:
    break;
  }

  return ch;
}

/* カーソルの移動できる範囲を制限 */
void cursor_range_limit(PARAMETER *data, int *x, int *y)
{
  if (*x < EDGE){
    *x = data->x_size;
  }else if (*x > data->x_size){
    *x = EDGE;
  }
  if (*y < EDGE){
    *y = data->y_size;
  }else if (*y > data->y_size){
    *y = EDGE;
  }
}

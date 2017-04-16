
#include <curses.h>
#include "msweeper.h"


/* キー処理関数 */
void key_proc(PARAMETER *data, int *x, int*y, int *oldc)
{
  int c, i_ret = 0;

  c = getch();
  delch();
  insch(*oldc);
  switch(c){
  case KEY_LEFT:
    (*x)--;  break;
  case KEY_RIGHT:
    (*x)++;  break;
  case KEY_UP:
    (*y)--;  break;
  case KEY_DOWN:
    (*y)++;  break;
  case 's':
    if (data->open_count == 0 && CHKFIELD(data, (*x)-EDGE, (*y)-EDGE) != 0) {
      refresh_field(data, (*x)-EDGE, (*y)-EDGE);
    }
    open_field(data, (*x)-EDGE, (*y)-EDGE);
    break;
  case 'a':
    if (CHKFIELDFLAG(data, (*x)-EDGE, (*y)-EDGE) == OPEN) {
      agree_around_flags(data, (*x)-EDGE, (*y)-EDGE);
    }
    break;
  case 'm':
    set_flag(data, (*x)-EDGE, (*y)-EDGE, MFLAG);
    break;
  case 'q':
    set_flag(data, (*x)-EDGE, (*y)-EDGE, QFLAG);
    break;
  }
}

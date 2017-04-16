#include <stdio.h>
#include <curses.h>
#include "msweeper.h"


/* フィールドを表示する */
void draw_field(PARAMETER *data)
{
  int i, j;

  printw("+");
  for (i = 0; i < data->x_size*2; i++) {
    printw("-");
  }
  printw("+\n");

  for (i = 0; i < data->y_size; i++) {
    printw("|");
    for (j = 0; j < data->x_size; j++) {
      if (CHKFIELDFLAG(data, j, i) == CLOSE) {
	printw(". ");
      }
      else if (CHKFIELDFLAG(data, j, i) == MFLAG) {
	printw("m ");
      }
      else if (CHKFIELDFLAG(data, j, i) == QFLAG) {
	printw("? ");
      }
      else {
	if (CHKFIELD(data, j, i) == 0) {
	  printw("  ");
	}
	else {
	  printw("%d ", data->field[i][j]);
	}
      }
    }
    printw("|\n");
  }

  printw("+");
  for (i = 0; i < data->x_size*2; i++) {
    printw("-");
  }
  printw("+\n");

  printw("      残り%d個\n", data->mines - data->mflag_count);
}

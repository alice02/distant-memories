#include <stdio.h>
#include <curses.h>
#include "msweeper.h"


void game_over(void)
{
  printw("\n失敗です．\n");
  refresh();
}

void game_clear(int time)
{
  printw("\n成功です．\n");
  printw("記録は%d秒でした．\n", time);
  refresh();
}

void see_you(void)
{
  endwin();
  printf("またね\n");
}

void disp_level_select(void)
{
    clear();
    printw("              *** M Sweeper ***\n");
    printw("----------------------------------------------\n");
    printw("* 1 → 初級:マス目の数[9x9], 地雷の数[10]   *\n");
    printw("* 2 → 中級:マス目の数[16x16], 地雷の数[40] *\n");
    printw("* 3 → 上級:マス目の数[30x16], 地雷の数[99] *\n");
    printw("* 4 → カスタム設定                         *\n");
    printw("* 5 → ハイスコアを表示                     *\n");
    printw("----------------------------------------------\n");
    refresh();
}

void opening_message(void)
{
  clear();
  printw("\n ↑↓←→  … カーソルを移動\n");
  printw("     a     … カーソル位置の周囲の点を自動的にチェック\n");
  printw("     s     … カーソル位置を安全な点としてチェック\n");
  printw("     m     … カーソル位置にMマークをつける\n");
  printw("     q     … カーソル位置に?マークをつける\n\n");

  printw("続けるには何かキーを押してください...\n");
  refresh();
  getc(stdin);
}

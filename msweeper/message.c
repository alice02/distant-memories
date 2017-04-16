#include <stdio.h>
#include <curses.h>
#include "msweeper.h"


void game_over(void)
{
  printw("\n���ԤǤ���\n");
  refresh();
}

void game_clear(int time)
{
  printw("\n�����Ǥ���\n");
  printw("��Ͽ��%d�äǤ�����\n", time);
  refresh();
}

void see_you(void)
{
  endwin();
  printf("�ޤ���\n");
}

void disp_level_select(void)
{
    clear();
    printw("              *** M Sweeper ***\n");
    printw("----------------------------------------------\n");
    printw("* 1 �� ���:�ޥ��ܤο�[9x9], ����ο�[10]   *\n");
    printw("* 2 �� ���:�ޥ��ܤο�[16x16], ����ο�[40] *\n");
    printw("* 3 �� ���:�ޥ��ܤο�[30x16], ����ο�[99] *\n");
    printw("* 4 �� ������������                         *\n");
    printw("* 5 �� �ϥ���������ɽ��                     *\n");
    printw("----------------------------------------------\n");
    refresh();
}

void opening_message(void)
{
  clear();
  printw("\n ��������  �� ����������ư\n");
  printw("     a     �� ����������֤μ��Ϥ�����ưŪ�˥����å�\n");
  printw("     s     �� ����������֤���������Ȥ��ƥ����å�\n");
  printw("     m     �� ����������֤�M�ޡ�����Ĥ���\n");
  printw("     q     �� ����������֤�?�ޡ�����Ĥ���\n\n");

  printw("³����ˤϲ��������򲡤��Ƥ�������...\n");
  refresh();
  getc(stdin);
}

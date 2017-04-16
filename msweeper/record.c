#include <stdio.h>
#include <string.h>
#include <curses.h>
#include "msweeper.h"


void disp_record(void)
{
  FILE *fp;
  SAVE_DATA record;

  clear();

  fp = fopen(".save_data", "rb");
  if(fp == NULL) {
    printw("\n�����֥ǡ������ɤ߹���ޤ���Ǥ�����\n\n");
  }
  else {
    fread(&record, sizeof(SAVE_DATA), 1, fp) ;
    fclose(fp);
    printw("\n   *** �ϥ������� ***\n");
    printw(" -----------------------\n");
    printw(" |  Level  |   Score   |\n");
    printw(" |---------------------|\n");
    printw(" |  ���   |   %4d��  |\n", record.first);
    printw(" |  ���   |   %4d��  |\n", record.second);
    printw(" |  ���   |   %4d��  |\n", record.third);
    printw(" -----------------------\n\n");
  }

  printw("³����ˤϲ��������򲡤��Ƥ�������...\n");
  refresh();
  getc(stdin);

}

/* ����������¸ */
void save_record(int time, int level)
{
  FILE *fp;
  SAVE_DATA record;

  if (level == CUSTOM) {
    return ;
  }

  fp = fopen(".save_data", "rb");
  if(fp == NULL ) {
    record.first = record.second = record.third = 9999;
  }
  else {
    fread(&record, sizeof(SAVE_DATA), 1, fp) ;
    fclose(fp);
  }
 
  fp = fopen(".save_data", "wb");
  if(fp == NULL) {
    printw("�ե�����񤭹��ߥ��顼\n");
  }
  else{
    judge_new_record(&record, time, level);
    fwrite(&record, sizeof(SAVE_DATA), 1, fp) ;
    fclose(fp);
  }
}

/* ����Ͽ��Ƚ�� */
void judge_new_record(SAVE_DATA *record, int time, int level)
{
  switch(level) {
  case BEGINNING:
    if (record->first > time) {
      printw("\n����ǤȤ��������ޤ�!! ����Ͽ�Ǥ�!!\n");
      record->first = time;
    }
    break;
  case INTERMEDIATE:
    if (record->second > time) {
      printw("\n����ǤȤ��������ޤ�!! ����Ͽ�Ǥ�!!\n");
      record->second = time;
    }
    break;
  case ADVANCED:
    if (record->second > time) {
      printw("\n����ǤȤ��������ޤ�!! ����Ͽ�Ǥ�!!\n");
      record->third = time;
    }
    break;
  }

}

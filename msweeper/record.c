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
    printw("\nセーブデータを読み込めませんでした．\n\n");
  }
  else {
    fread(&record, sizeof(SAVE_DATA), 1, fp) ;
    fclose(fp);
    printw("\n   *** ハイスコア ***\n");
    printw(" -----------------------\n");
    printw(" |  Level  |   Score   |\n");
    printw(" |---------------------|\n");
    printw(" |  初級   |   %4d秒  |\n", record.first);
    printw(" |  中級   |   %4d秒  |\n", record.second);
    printw(" |  上級   |   %4d秒  |\n", record.third);
    printw(" -----------------------\n\n");
  }

  printw("続けるには何かキーを押してください...\n");
  refresh();
  getc(stdin);

}

/* スコアの保存 */
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
    printw("ファイル書き込みエラー\n");
  }
  else{
    judge_new_record(&record, time, level);
    fwrite(&record, sizeof(SAVE_DATA), 1, fp) ;
    fclose(fp);
  }
}

/* 新記録の判定 */
void judge_new_record(SAVE_DATA *record, int time, int level)
{
  switch(level) {
  case BEGINNING:
    if (record->first > time) {
      printw("\nおめでとうございます!! 新記録です!!\n");
      record->first = time;
    }
    break;
  case INTERMEDIATE:
    if (record->second > time) {
      printw("\nおめでとうございます!! 新記録です!!\n");
      record->second = time;
    }
    break;
  case ADVANCED:
    if (record->second > time) {
      printw("\nおめでとうございます!! 新記録です!!\n");
      record->third = time;
    }
    break;
  }

}

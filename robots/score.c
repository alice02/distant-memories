#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "robots.h"


/* スコアの表示 */
void print_score(void)
{
  struct save_data data[SAVE_DATA_COUNT];
  FILE *fp;
  int i;

  fp = fopen(".save_data", "rb"); /* ファイルオープン(バイナリ読み込み) */
  if(fp == NULL) {
    printf("Failed to read a save data file.\n"); /* エラーメッセージ */
  }
  else {
    fread(data, sizeof(struct save_data), SAVE_DATA_COUNT, fp); /* .save_dataから読み込み */
    fclose(fp);

    /* スコアを表示 */
    printf("Rank Score Name                 Level\n");
    for (i = 0; i < data[0].num; i++) {
      printf("%4d %5d %-20s %5d\n", i+1, data[i].score, data[i].name, data[i].level);
    }
  }

}

/* スコアの保存 */
void save_score(int score, int level)
{
  struct save_data data[SAVE_DATA_COUNT+1];
  struct save_data tmp;
  FILE *fp;
  int num;
  int i, j;

  fp = fopen(".save_data", "rb"); /* ファイルオープン(バイナリ読み込み) */
  if(fp == NULL ) {
    printf("There is NO save data file. I create new save data file.\n"); /* エラーメッセージ */

    /* 新規セーブデータ作成 */
    fp = fopen(".save_data", "wb");
    if(fp == NULL) {
      printf("Failed to create a save data file.\n");
    }
    else{
      data[0].score = 0;
      strcat(data[0].name, "None");
      data[0].level = 0;
      data[0].num = 0;
      fwrite(data, sizeof(struct save_data), 1, fp);
      fclose(fp);
    }
  }
  else {
    fread(data, sizeof(struct save_data), SAVE_DATA_COUNT, fp); /* .save_dataから読み込み */
    fclose(fp);
  }
 

  fp = fopen(".save_data", "wb");
  if(fp == NULL) {
    printf("Failed to create a save data file.\n"); /* エラーメッセージ */
  }
  else{
    /* 過去の記録と比較するために今回の記録を一時的に保存 */
    num = data[0].num;
    data[num].score = score;
    printf("Input your name(max:20) : ");
    scanf("%20s", data[num].name);
    data[num].level = level;

    /* sort */
    for(i = 0; i < num+1; i++){
      for(j = num; j > i; j--){
	if(data[j].score > data[j-1].score){
	  tmp = data[j];
	  data[j] = data[j-1];
	  data[j-1] = tmp;
	}
      }
    }

    /* 記録の個数を更新 */
    if (num < SAVE_DATA_COUNT) {
      data[0].num = num+1;
    }

    fwrite(data, sizeof(struct save_data), num+1, fp); /* .save_dataに書き込み */
    fclose(fp);

  }

}

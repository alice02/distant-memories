#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "hanoi.h"

#define NUM 10000

void file_write(char n, char m);
void auto_hanoi(int n);
void func(int n, char from, char work, char dest);

void time_wait(int ms)
{
  int i, j;

  for (i=0; i<ms; i++) {
    for (j=0; j<NUM; j++) {
    }
  }
}

void auto_hanoi(int n)
{

  func(n, 'a', 'b', 'c');
}

void func(int n, char from, char work, char dest)
{
  if (n >= 2) {
    func(n-1, from, dest, work);
  }

  file_write(from, dest);

  if (n >= 2) {
    func(n-1, work, from, dest);
  }

}

void file_write(char n, char m)
{
 FILE *fp;

 fp = fopen("data.dat","a");
 if (fp == NULL) {
   printf("can't open file.\n");
   exit(1);
 }

  fprintf(fp,"%c %c\n", n, m);

  fclose(fp);
}


int  main(int argc, char *argv[])
{
  int  i_size;
  struct stack  ss[3];
  char  c_sel_from, c_sel_to, c_dummy;
  int  i_sel_from, i_sel_to;
  int  i_data_from,  i_data_to;
  int  i_ret_from, i_ret_to;
  int  i;
  int  i_cnt = 1;
  FILE *fp_read;

  //● 引数チェック
  if (argc-1 != 1) {
    printf("%s size\n", argv[0]);
    exit(1);
  }

  fp_read = fopen("data.dat", "r");

  i_size = atoi(argv[1]);  //● 右辺

  auto_hanoi(i_size);

  for (i = 0;  i < 3;  i++)
  {
    my_make_stack(&ss[i], i_size);  //● 第2引数
  }
  my_init_tower(ss);  //● 引数

  while (ss[2].i_sp != 0)  //● 反復条件の左辺
  {
    my_print_tower(ss);  //● 引数

    time_wait(500);

    printf("count = %d\n", i_cnt);
    fscanf(fp_read, "%c%c%c%c", &c_sel_from, &c_dummy, &c_sel_to, &c_dummy);
    printf("From = %c\n", c_sel_from);
    //    scanf("%c%c", &c_sel_from, &c_dummy);
    i_sel_from = c_sel_from - 'a';  //● 英小文字を数値に変換

    i_ret_from = my_pop(&ss[i_sel_from], &i_data_from);  //● 第2引数
    if (i_ret_from == 1)  //● 分岐条件の右辺
    {
      printf("No disk at '%c'\n", c_sel_from);
      sleep(2);
      continue;
    }


    //    fscanf(fp_read, " %c\n", &c_sel_to);
    printf("To   = %c\n", c_sel_to);
    //    scanf("%c%c", &c_sel_to, &c_dummy);
    i_sel_to = c_sel_to - 'a';  //● 英小文字を数値に変換

    i_ret_to = my_pop(&ss[i_sel_to], &i_data_to);  //● 第1引数
    if (i_ret_to == 0)  //● 分岐条件の右辺
    {
      // i_data_to を元のスタックに戻す．
      // i_data_to はpop したデータがセットされた状態になっているので，
      // 後の処理で値を参照できる．
      my_push(&ss[i_sel_to], i_data_to);  //● 引数
    }
    else
    {
      // スタックは空．データをi_size にして，どの円盤も置けるようにする．
      i_data_to = ss[i_sel_to].i_size;
    }

    if (i_data_from < i_data_to)
    {
      // 新しい位置に移す．
      my_push(&ss[i_sel_to], i_data_from);  //● 引数
      i_cnt++;  //● 値の更新
    }
    else
    {
      printf("Can't move from '%c' to '%c'.\n", c_sel_from, c_sel_to);
      sleep(2);
      // 元の位置に戻す．
      my_push(&ss[i_sel_from], i_data_from);  //● 引数
      continue;
    }
  }

  my_print_tower(ss);  //● 引数
  i_cnt--;
  printf("count = %d\n", i_cnt);
  if (i_cnt == (int)pow(2, i_size) -1)  //● pow() の引数
  {
    printf("Perfect !!\n");
  }
  else
  {
    printf("Success !\n");
  }

  for (i = 0;  i < 3;  i++)
  {
    free(ss[i].ia_stack);  //● 引数
  }

  return 0;
}

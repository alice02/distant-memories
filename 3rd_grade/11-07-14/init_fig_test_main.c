/*●●● 必要なヘッダファイルを含める ●●●*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct data
{
  char  *cp_dat;  /* 文字列を格納する領域の先頭番地を記憶する．*/
  int   i_length;  /* 文字列のサイズを格納する．*/
};

void my_init_fig(struct data  *ans);


int main(int argc, char *argv[])
{
  struct data  ans;

  srand((unsigned)time(NULL));

  /*●●● 処理内容 ●●●*/
  if (argc-1 != 1) {
    printf("%s number\n", argv[0]);
    exit(1);
  }

  ans.i_length = atoi(argv[1]);

  ans.cp_dat = (char *)malloc(sizeof(char)*(ans.i_length+1));

  my_init_fig(&ans);

  printf("%s\n", ans.cp_dat);

  return 0;
}

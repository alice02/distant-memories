#include <stdlib.h>
#include <stdio.h>

struct data
{
  char  *cp_dat;  /* 文字列を格納する領域の先頭番地を記憶する．*/
  int   i_length;  /* 文字列のサイズを格納する．*/
};

struct judge
{
  int  i_hit;
  int  i_blow;
};

void my_judge_fig(struct data  ans,
		  char  cp_input[],
                  struct judge  *hb);


int main(int argc, char *argv[])
{
  struct data  ans;
  struct judge  hb;
  char  *cp_input;

  /*●●● 処理内容 ●●●*/
  if (argc-1 != 1) {
    printf("%s number\n", argv[0]);
    exit(0);
  }

  ans.i_length = atoi(argv[1]);

  ans.cp_dat = (char *)malloc(sizeof(char)*(ans.i_length+1));
  cp_input = (char *)malloc(sizeof(char)*(ans.i_length+1));

  printf("Input answer = ");
  scanf("%s", ans.cp_dat);

  while (1) {
    printf("Intput = ");
    scanf("%s", cp_input);
    my_judge_fig(ans, cp_input, &hb);
    printf("HIT: %d  BLOW: %d\n", hb.i_hit, hb.i_blow);
  }

  return 0;
}

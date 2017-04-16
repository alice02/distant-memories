#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct data
{
  char  *cp_dat;
  int   i_length;
};

struct judge
{
  int  i_hit;
  int  i_blow;
};

void my_init_fig(struct data  *ans);

void my_judge_fig(struct data  ans,
		  char  cp_input[],
                  struct judge  *hb);


int main(int argc, char *argv[])
{
  struct data  ans;
  struct judge  hb;
  char  *cp_input;
  int  i;

  /*¡ü¡ü¡ü ½èÍýÆâÍÆ ¡ü¡ü¡ü*/
  if (argc-1 != 1) {
    printf("%s number\n", argv[0]);
    exit(1);
  }

  srand(time(NULL));

  ans.i_length = atoi(argv[1]);

  ans.cp_dat = (char *)malloc(sizeof(char)*(ans.i_length+1));
  cp_input = (char *)malloc(sizeof(char)*(ans.i_length+1));

  my_init_fig(&ans);

  printf("answer = %s\n", ans.cp_dat);

  for (i = 0; i < ans.i_length*2 && hb.i_hit != ans.i_length; i++) {
    printf("Rest:%d Please input %d letters >>>", ans.i_length*2 - i, ans.i_length);
    scanf("%s", cp_input);
    my_judge_fig(ans, cp_input, &hb);
    if (hb.i_hit != ans.i_length) {
      printf("HIT: %d  BLOW: %d\n", hb.i_hit, hb.i_blow);
    }
  }

  if (hb.i_hit == ans.i_length) {
    printf("Success !\n");
  }
  else {
    printf("The answer is %s\n", ans.cp_dat);
  }

  free(ans.cp_dat);
  free(cp_input);

  return 0;
}

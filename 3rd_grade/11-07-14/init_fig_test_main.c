/*������ ɬ�פʥإå��ե������ޤ�� ������*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct data
{
  char  *cp_dat;  /* ʸ������Ǽ�����ΰ����Ƭ���Ϥ򵭲����롥*/
  int   i_length;  /* ʸ����Υ��������Ǽ���롥*/
};

void my_init_fig(struct data  *ans);


int main(int argc, char *argv[])
{
  struct data  ans;

  srand((unsigned)time(NULL));

  /*������ �������� ������*/
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

#include <stdlib.h>

struct data
{
  char  *cp_dat;  /* ʸ������Ǽ�����ΰ����Ƭ���Ϥ򵭲����롥*/
  int   i_length;  /* ʸ����Υ��������Ǽ���롥*/
};


void my_init_fig(struct data  *ans)
{
  int i_rand;
  int i_max;
  char ca_fig[10];
  int i;

  for (i = 0;  i <= 9;  i ++)
  {
    ca_fig[i] = '0' + i;  /*������ ���� ������*/
  }

  i_max = 10;
  for (i = 0;  i < ans->i_length;  i ++)  /*������ ȿ����� ������*/
  {
    i_rand = rand() % i_max;  /*������ ���� ������*/
    ans->cp_dat[i] = ca_fig[i_rand];  /*������ ���� ������*/
    ca_fig[i_rand] = ca_fig[i_max-1];  /*������ ���ա����դȤ�index ������*/
    i_max --;  /*������ �������� ������*/
  }
  ans->cp_dat[ans->i_length] = '\0';  /*������ ���� ������*/
}

/*������ ɬ�פʥإå��ե������ޤ�� ������*/
#include <stdlib.h>

struct data
{
  char  *cp_dat;
  int   i_num;
};

void my_select(struct data ref,
	       struct data *set)
{
  int  i;
  int  i_length;
  int  i_rand;

  i_length = ref.i_num;  /*������ ���� ������*/

  for (i = 0;  i < ref.i_num;  i++)
  {
    i_rand = rand() % i_length;  /*������ ���� ������*/
    set->cp_dat[i] = ref.cp_dat[i_rand];  /*������ ���� ������*/

    /*������ ���򤷤�ʸ����Ǹ��ʸ���ǤĤ֤� ������*/
        ref.cp_dat[i_rand] = ref.cp_dat[i_length-1];
    /*������ �����ǽ���ϰϤ�̤�� ������*/
    i_length--;
  }
}

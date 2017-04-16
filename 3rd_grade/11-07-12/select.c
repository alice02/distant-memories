/*↑↑↑ 涩妥なヘッダファイルを崔める ↑↑↑*/
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

  i_length = ref.i_num;  /*↑↑↑ 宝收 ↑↑↑*/

  for (i = 0;  i < ref.i_num;  i++)
  {
    i_rand = rand() % i_length;  /*↑↑↑ 宝收 ↑↑↑*/
    set->cp_dat[i] = ref.cp_dat[i_rand];  /*↑↑↑ 宝收 ↑↑↑*/

    /*↑↑↑ 联买した矢机を呵稿の矢机でつぶす ↑↑↑*/
        ref.cp_dat[i_rand] = ref.cp_dat[i_length-1];
    /*↑↑↑ 联买材墙な认跋を教める ↑↑↑*/
    i_length--;
  }
}

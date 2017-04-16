#include <stdio.h>

void my_one_wrong(int i_data);


int main(void)
{
  int i_num;

  i_num = 0;
  printf("before: %d\n", i_num);

  my_one_wrong(i_num);
  printf("after : %d\n", i_num);

  return 0;
}


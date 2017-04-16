#include <stdio.h>

void my_one(int *ip_data);


int main(void)
{
  int i_num;

  i_num = 0;
  printf("before: %d\n", i_num);

  my_one(&i_num);
  printf("after : %d\n", i_num);

  return 0;
}


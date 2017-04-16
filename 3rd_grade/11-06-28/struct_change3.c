#include <stdio.h>

struct data{
  int i_num;
};

void my_zero(struct data *da)
{
  da -> i_num = 0;
}

int main(void)
{
  struct data da;

  da.i_num = 1;
  printf("%d\n", da.i_num);
  my_zero(&da);
  printf("%d\n", da.i_num);

  return 0;
}

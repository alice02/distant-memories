#include <stdio.h>

int main(void)
{
  int x;
  int *pt;

  x = 5;
  pt = &x;

  printf("x:%d  x_address:%p\n", x, &x);
  printf("pt:%d  pt_address:%p\n", *pt, pt);

  *pt = 7;

  printf("x:%d  x_address:%p\n", x, &x);
  printf("pt:%d  pt_address:%p\n", *pt, pt);

  return 0;
}

#include <stdio.h>

int main(void)
{
  int a;
  int *pta;
  int *ptb;

  a = 567;
  pta = &a;
  ptb = pta;

  printf("%d\n", a);
  printf("%d\n", *pta);
  printf("%d\n", *ptb);

  return 0;
}

#include <stdio.h>

int main(void)
{
  int a;
  int b;
  int *pt;

  a = 7;
  pt = &a;
  b = a+*pt;
  printf("b=%d\n",b);

  *pt = 5;
  b = a+*pt;
  printf("b=%d\n",b);

  pt = &b;
  a = 3;
  a += *pt;
  printf("a=%d\n",a);

  b = 10;
  a += *pt;
  printf("a=%d\n", a);

  a = 100;
  printf("a=%d\n", a--);
  printf("a=%d\n", a);

  a = 100;
  printf("a=%d\n", --a);
  printf("a=%d\n", a);

  return 0;
}

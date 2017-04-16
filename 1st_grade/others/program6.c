#include<stdio.h>
main(void)
{
  int a;
  int b;
  int c;
  int d;
  int e;

  a = 1;
  b = 2;
  c = 3;
  d = b;
  e = c;
  b = a;
  c = d;
  a = e;

  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("c=%d\n",c);
}

#include<stdio.h>

int function(int a)
{
  int y;

  y = a * 4;

  return y;
}

int main(void)
{
  int x;
  int y;

  x = 3;

  y = function(x);
  printf("function(%d)=%d\n",x,y);

  return 0;
}

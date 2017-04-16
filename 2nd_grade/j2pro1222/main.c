#include <stdio.h>

int func(int num);

int main(void)
{
  int x;
  int y;
  
  x = 5;
  y = func(x);
  printf("y=%d\n", y);

  return 0;
}

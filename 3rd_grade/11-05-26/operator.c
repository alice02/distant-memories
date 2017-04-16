#include <stdio.h>

int main(void)
{
  int i, j, a, b;

  i = 3;
  a = i++;

  j = 4;
  b = ++j;

  printf("a:%d  b:%d\n", a, b);

  return 0;
}

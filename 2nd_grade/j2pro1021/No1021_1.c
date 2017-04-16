#include <stdio.h>

void func(int *a, int *b)
{
  *a = 34;
  *b = 56;
}

int main(void)
{
  int a, b;

  func(&a, &b);

  printf("a = %d   b = %d\n", a, b);

  return 0;
}

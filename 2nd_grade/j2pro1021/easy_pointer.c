#include <stdio.h>

void func(int *pt)
{
  printf("func内のptのアドレスは%p\n", pt);
  printf("ptが指すアドレスに格納されている値は%d\n", *pt);

  *pt = 999;
  printf("ptが指すアドレスに格納されている値は%d\n", *pt);
}

int main(void)
{
  int a;

  a = 777;

  printf("変数aのアドレスは%p\n", &a);
  func(&a);

  printf("変数aのアドレスは%p\n", &a);
  printf("a=%d\n", a);

  return 0;
}

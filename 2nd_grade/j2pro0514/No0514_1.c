#include <stdio.h>

int nijou(int x)
{
  x = x*x;

  return x;
}

int main(void)
{
  int a,b;

  printf("ฟ๔รอกง");
  scanf("%d",&a);

  b = nijou(a);

  printf("%d\n",b);

  return 0;
}

#include <stdio.h>

int getdata(void)
{
  int num;

  printf("input number =");
  scanf("%d",&num);

  return num;
}

int main(void)
{
  int a;

  a =getdata();

  a = a *4;

  printf("a=%d\n",a);

  return 0;
}

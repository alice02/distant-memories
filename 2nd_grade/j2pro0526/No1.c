#include <stdio.h>

int wa(int a, int b)
{
  int wa;

  wa = a + b;

  return wa;
}


int main(void)
{
  int x,y,S;

  printf("���ͣ�:");
  scanf("%d",&x);
  printf("���ͣ�:");
  scanf("%d",&y);

  S = wa(x,y);

  printf("%d\n",S);

  return 0;
}


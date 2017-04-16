#include<stdio.h>

double calc(int num)
{
  return num*num*3.14;
}


int main(void)
{
  int r;

  printf("r=");
  scanf("%d", &r);

  printf("%f\n", calc(r));

  return 0;
}

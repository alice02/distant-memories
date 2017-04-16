#include <stdio.h>

void put_stars(int n)
{
  int i;

  i = n;
  while(0<i){
    printf("*");
    i--;
  }
  printf("\n");
}

int main(void)
{
  int a,b;

  printf("รอกง");
  scanf("%d",&a);

  b = a;

  while(0<b){
    put_stars(a);
    b--;
  }

  return 0;
}

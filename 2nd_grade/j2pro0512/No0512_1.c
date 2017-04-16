#include<stdio.h>

void A(int a, int b)
{
  if(a>b){
    printf("%d\n",a);
  }else{
    printf("%d\n",b);
  }
}

int main(void)
{
  int x,y;

  printf("x:");
  scanf("%d",&x);
  printf("y:");
  scanf("%d",&y);

  A(x,y);

  return 0;
}

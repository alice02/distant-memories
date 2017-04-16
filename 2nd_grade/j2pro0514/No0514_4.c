#include <stdio.h>

int wa(int n,int m)
{
  int wa=0,value=0;

  while(value<=n){
    if(value%m==0){
      wa = wa + value;
    }
    value++;
  }

  return wa;
}

int main(void)
{
  int m,n,x;

  printf("n¡§");
  scanf("%d",&n);
  printf("m¡§");
  scanf("%d",&m);

  x = wa(n , m);

  printf("%d\n",x);

  return 0;
}

#include <stdio.h>

int calc_sum(int a , int b);

int main(void)
{

  int n,m,sum;

  printf("n=");
  scanf("%d",&n);
  printf("m=");
  scanf("%d",&m);

  sum = calc_sum(n,m);

  printf("sum=%d\n",sum);

  return 0;

}


int calc_sum(int a , int b)
{

  int i;


  for (i=0; a<=b; a++){
    i = i + a;
  }
  return i;
}

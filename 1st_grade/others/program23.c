#include<stdio.h>
main(void)
{
  int i;
  int a;

  i=1;

  printf("数は?");
  scanf("%d",&a);
 
  while(i<=a){
    printf("%d\n",i);
    i=i+1;
  }
  printf("*** 最後のi=%d ***\n",i);
}

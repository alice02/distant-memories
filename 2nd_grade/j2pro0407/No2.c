#include<stdio.h>
main(void)
{

  int a,b,c;

  printf("a:");
  scanf("%d",&a);

  printf("b:");
  scanf("%d",&b);

  if(a>b){
    c=a;
  }else{
    c=b;
  }

  printf("%d\n",c);

}

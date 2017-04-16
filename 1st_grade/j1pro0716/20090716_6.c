#include<stdio.h>
main(void)
{
  int a;
  int s;

  s=0;
  a=0;

  while(s<=100){
    a=a+1; 
   s=s+a*a;
   }
  printf("1^2+2^2+...a^2が100以上になる整数aのなかで最小のaの値は%dです.\n",a);
}

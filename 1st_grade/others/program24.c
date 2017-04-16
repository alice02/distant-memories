#include<stdio.h>
main(void)
{
  int i;
  int a;
  int s;

  i=1;
  a=4;
  s=0;
 
  while(i<=a){
    s=s+i;
    i=i+1;
  }
  printf("1+2+...+%d=%d\n",a,s);
}

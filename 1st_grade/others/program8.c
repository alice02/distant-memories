#include<stdio.h>
main(void)
{
  int a;
  int b;
  int c;
 
  a = 1;
  b = 3;

  if(a>b){
    c = a;
    a = b;
    b = c;
  }

  printf("a=%d\n",a);
  printf("b=%d\n",b);
}

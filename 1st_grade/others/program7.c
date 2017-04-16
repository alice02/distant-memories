#include<stdio.h>
main(void)
{
  int a;
  int b;
  int c;
 
  a = 1;
  b = -3;

  if(a*a>=b*b){
    c = a;
  } else {
    c = b;
  }

  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("c=%d\n",c);
}

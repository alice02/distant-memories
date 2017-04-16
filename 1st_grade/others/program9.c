#include<stdio.h>
main(void)
{
  int a;
  int b;
  int c;
  int d;

  a = 1;
  b = -3;
  c = 2;
  d = 0;

  if(a>0){
    d = d+a;
  }
  if(b>0){
    d = d+b;
  }
  if(c>0){
    d = d+c;
  }

  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("c=%d\n",c);
  printf("d=%d\n",d);
}

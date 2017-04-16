#include<stdio.h>
main(void)
{
  int i;
  int a;
  int b;
  int s;

  i=1;
  s=0;
  b=1;

  printf("¿ô¤Ï?");
  scanf("%d",&a);

  while(b<=a){
    s=s+i;
    b=b+1; 
    i=b*b;
 }
  printf("1^2+2^2+...+%d^2=%d\n",a,s);
}

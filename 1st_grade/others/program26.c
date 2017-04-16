#include<stdio.h>
main(void)
{
  int i;
  int a;
  int s;

  i=1;
  s=1;

  printf("¿ô¤Ï?");
  scanf("%d",&a);

  while(i<=a){
    s=s*i;
    i=i+1;  
}
  printf("1¡ß2¡ß...¡ß%d=%d\n",a,s);
}

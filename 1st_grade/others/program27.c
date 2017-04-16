#include<stdio.h>
main(void)
{
  int i;
  int a;
  int s;

  i=0;
  s=0;

  printf("¿ô¤Ï?");
  scanf("%d",&a);

  while(a>0){
    s=s+a;
    a=a-1;  
}
  printf("%d\n",s);
}

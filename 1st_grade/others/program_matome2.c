**********(3)**********
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
**********(4)**********
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
**********(5)**********
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

















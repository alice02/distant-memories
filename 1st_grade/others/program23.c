#include<stdio.h>
main(void)
{
  int i;
  int a;

  i=1;

  printf("����?");
  scanf("%d",&a);
 
  while(i<=a){
    printf("%d\n",i);
    i=i+1;
  }
  printf("*** �Ǹ��i=%d ***\n",i);
}

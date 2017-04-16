#include<stdio.h>
main(void)
{

  int a;

  printf("Ç¯Îð:");
  scanf("%d",&a);

  if(a<=5){
    printf("0±ß\n");
  }else if(a<12){
    printf("350±ß\n");
  }else if(a>=12){
    printf("700±ß\n");
  }

}

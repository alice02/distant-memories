#include<stdio.h>
main(void)
{
  int y;

  printf("year = ");
  scanf("%d", &y);

  if(y%400==0){
    printf("閏年です!\n");
  }else if(y%100==0){
    printf("閏年ではありません!\n");
  }else if(y%4==0){
    printf("閏年です!\n");
  }else{
    printf("閏年ではありません!\n");
  }
}

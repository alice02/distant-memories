#include<stdio.h>
main(void)
{
  int d;

  d=18;

  if(d%10==2){
    printf("5%割引です!\n");
  }else if(d%10==9){
    printf("5%割引です!\n");
  }else if(20<=d && d<=29){
    printf("5%割引です!\n");
  }else{
    printf("肉の日じゃありません!\n");
  }
}

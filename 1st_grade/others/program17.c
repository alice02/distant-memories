#include<stdio.h>
main(void)
{
  int d;

  d=22;

  if(20<=d && d<=29){
    if(d==22 && d==29){
      printf("10%����Ǥ�!\n");
    }else{
      printf("5%����Ǥ�!\n");
    }
  }else if(d%10==9){
    printf("5%����Ǥ�!\n");
  }else if(d%10==2){
    printf("5%����Ǥ�!\n");
  }else{
    printf("���������㤢��ޤ���!\n");
  }
}

#include<stdio.h>
main(void)
{
  int y;

  printf("year = ");
  scanf("%d", &y);

  if(y%400==0){
    printf("��ǯ�Ǥ�!\n");
  }else if(y%100==0){
    printf("��ǯ�ǤϤ���ޤ���!\n");
  }else if(y%4==0){
    printf("��ǯ�Ǥ�!\n");
  }else{
    printf("��ǯ�ǤϤ���ޤ���!\n");
  }
}

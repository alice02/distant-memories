#include<stdio.h>
main(void)
{
  int a;

  a=1954;

  if(a<1930){
    printf("�ޤ��ϤޤäƤʤ�!\n");
  }else if(a%4!=2){
    printf("����ǯ�ǤϤʤ�!\n");
  }else if(a<=1938){
    printf("��%d�󳫺�ǯ!\n",(a-1930)/4+1);
  }else if(a<1950){
    printf("������!\n");
  }else{
    printf("��%d�󳫺�ǯ\n",(a-1950)/4+4);
  }
}

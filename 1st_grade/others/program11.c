#include<stdio.h>
main(void)
{
  int a;
  int n;

  a=1944;

  if(a<1896){
    printf("�ޤ��ϤޤäƤʤ�!\n");
  }else if(a%4!=0){
    printf("����ǯ����ʤ�!\n");
  }else{
    n=(a-1896)/4+1;
    if(a==1916){
      printf("��%d�󳫺�ͽ����ä����ɡ��Գ��Ť��ä�!\n",n);
    }else if(a==1940){
      printf("��%d�󳫺�ͽ����ä����ɡ��Գ��Ť��ä�!\n",n);
    }else if(a==1944){
      printf("��%d�󳫺�ͽ����ä����ɡ��Գ��Ť��ä�!\n",n);
    }else{
      printf("��%d�󳫺�ǯ\n",n);
    }
  }
}

**********(3)**********
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

**********(4)**********
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

**********(5)**********
#include<stdio.h>
main(void)
{
  int a;
  int m;

  m=9;

  if(m>=8){
    a=m+1;
  }else{
    a=m;
  }
  if(a%2==1){
    printf("��η�!\n");
  }else{
    printf("���η�!\n");
  }
}

**********(6)**********
#include<stdio.h>
main(void)
{
  int y;

  y=2000;

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

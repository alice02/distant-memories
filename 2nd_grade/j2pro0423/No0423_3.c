#include <stdio.h>

int main(void)

{

  int m,n;

  printf("n=");
  scanf("%d",&n);

  m=n%7;

  printf("%d�����",n);

  if(m==1){
    printf("��");
  }else if(m==2){
    printf("��");
  }else if(m==3){
    printf("��");
  }else if(m==4){
    printf("��");
  }else if(m==5){
    printf("��");
  }else if(m==6){
    printf("��");
  }else if(m==0){
    printf("��");
  }

  printf("�����Ǥ�\n");

  return 0;

}

#include <stdio.h>

void tenki_hantei(int kousui)
{
  if(kousui>=50){
    printf("��\n");
  }
  else if(kousui>=20){
    printf("�ޤ�\n");
  }
  else if(kousui<20){
    printf("����\n");
  }
}

int main(void)
{
  int x;

  printf("�߿��Ψ�����Ϥ��Ƥ���������");
  scanf("%d",&x);

  if(x>0 && x<100){
    tenki_hantei(x);
  }else{
    printf("�������ΤǤ���\n");
  }

  return 0;
}  

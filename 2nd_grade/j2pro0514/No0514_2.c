#include <stdio.h>

int pay_money(int total)
{
  int x;

  if(total>=10000){
    x = total - 3000;
  }else{
    x = total - 200;
  }

  return x;
}

int main(void)
{
  int a,b;

  printf("���㤤ʪ��׶�ۡ�");
  scanf("%d",&a);

  b = pay_money(a);

  printf("��ʧ������%d�ߥǥ�\n",b);

  return 0;
}

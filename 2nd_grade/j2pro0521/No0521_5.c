#include <stdio.h>

void cto2(int);

int main(void)
{

  int a=3;

  printf("3��2�ʿ���ɽ����...");

  cto2(a);

  printf("����Ρ�2�������...");

  a =~ a;

  a = a + 1;

  cto2(a);

  printf("�����10�ʿ���ɽ����...%d\n",a);

  return 0;
}

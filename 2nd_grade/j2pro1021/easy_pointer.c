#include <stdio.h>

void func(int *pt)
{
  printf("func���pt�Υ��ɥ쥹��%p\n", pt);
  printf("pt���ؤ����ɥ쥹�˳�Ǽ����Ƥ����ͤ�%d\n", *pt);

  *pt = 999;
  printf("pt���ؤ����ɥ쥹�˳�Ǽ����Ƥ����ͤ�%d\n", *pt);
}

int main(void)
{
  int a;

  a = 777;

  printf("�ѿ�a�Υ��ɥ쥹��%p\n", &a);
  func(&a);

  printf("�ѿ�a�Υ��ɥ쥹��%p\n", &a);
  printf("a=%d\n", a);

  return 0;
}

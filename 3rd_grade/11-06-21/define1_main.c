#include <stdio.h>
#include <stdlib.h>

#define square(x) ( x * x )

int main(int argc, char *argv[])
{
  int a, b, ans;

  if (argc-1 != 2) {
    printf("%s data1 data2\n", argv[0]);
    printf("data1 ��data2 ��ä����ͤ�2�����ޤ��ʴְ㤤�ˡ�\n");
    printf("�ǡ����η��������Ǥ���\n");
    exit(1);
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);

  ans = square(a+b);

  printf("%d\n", ans);

  return 0;
}

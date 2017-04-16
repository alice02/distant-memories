#include <stdio.h>

void cto2(int);

int main(void)
{

  int a,n,m;

  a = 0x2A;

  n = a << 2;

  m = a >> 1;

  printf("左２ビットシフト：%X(16)  %d(10)  ",n,n);
  cto2(n);

  printf("右１ビットシフト：%X(16)  %3d(10)  ",m,m);
  cto2(m);


  return 0;
}

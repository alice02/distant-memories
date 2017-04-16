#include <stdio.h>

void cto2(int);

int main(void)
{

  int a = 0xC2 , b = 0x4F , wa , sa , or , and;

  wa = a + b;

  sa = a - b;

  or = a | b;

  and = a & b;

  printf("\n");
  printf("(C2)+(4F) = %X(16) %d(10) ",wa,wa);
  cto2(wa);
  printf("\n");

  printf("(C2)-(4F) = %X(16) %d(10) ",sa,sa);
  cto2(sa);
  printf("\n");

  printf("(C2)OR(4F) = %X(16) %d(10) ",or,or);
  cto2(or);
  printf("\n");

  printf("(C2)AND(4F) = %X(16) %d(10) ",and,and);
  cto2(and);
  printf("\n");

  return 0;
}

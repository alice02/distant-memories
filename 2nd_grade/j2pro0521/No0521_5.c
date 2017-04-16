#include <stdio.h>

void cto2(int);

int main(void)
{

  int a=3;

  printf("3を2進数で表すと...");

  cto2(a);

  printf("これの、2の補数は...");

  a =~ a;

  a = a + 1;

  cto2(a);

  printf("これを10進数で表すと...%d\n",a);

  return 0;
}

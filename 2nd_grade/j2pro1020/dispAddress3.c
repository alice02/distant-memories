#include <stdio.h>

int main(void)
{
  int adt;
  int bdt;
  int *pt;

  adt = 1234;
  pt = &adt;
  bdt = *pt;

  printf("%p\n", pt);

  printf(" adt = %d\n", adt);
  printf(" *pt = %d\n", *pt);
  printf(" bdt = %d\n", bdt);

  adt = 555;
  printf(" adt = %d\n", adt);
  printf(" *pt = %d\n", *pt);
  printf(" bdt = %d\n", bdt);

  *pt = 666;
  printf(" adt = %d\n", adt);
  printf(" *pt = %d\n", *pt);
  printf(" bdt = %d\n", bdt);

  bdt = 777;
  printf(" adt = %d\n", adt);
  printf(" *pt = %d\n", *pt);
  printf(" bdt = %d\n", bdt);

  return 0;
}

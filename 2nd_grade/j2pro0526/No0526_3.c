#include <stdio.h>

int main(void)
{

  int a[7];
  int b;

  for (b=0; b<7; b++) {
    a[b] = b + 1;
    printf("a[%d]=%d\n",b,a[b]);
  }

  return 0;
}

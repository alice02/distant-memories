#include <stdio.h>

int main(void)
{
  int array[5] = {1, 2, 3, 4, 5};
  int *pt;
  int i;

  pt = &array[2];

  for (i=0; i<5; i++) {
    printf("array[%d] = %d\n", i, *(pt+i-2));
  }

  return 0;
}

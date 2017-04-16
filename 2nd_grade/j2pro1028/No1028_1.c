#include <stdio.h>

int main(void)
{
  int array[10];
  int i;
  int *pt;

  pt = array;

  for (i=0; i<10; i++) {
    printf("array[%d] = %d\n", i, array[i]);
  }

  for (i=0; i<10; i++) {
    *(pt+i) = 0;
  }

  for (i=0; i<10; i++) {
    printf("array[%d] = %d\n", i, array[i]);
  }

  return 0;
}

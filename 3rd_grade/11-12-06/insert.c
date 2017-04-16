#include <stdio.h>
#include <stdlib.h>

#define SIZE (10)
#define INSERT (4)

int main(void)
{
  int *ia_dat;
  int i;

  ia_dat = (int *)malloc(sizeof(int) * (SIZE));

  for (i = 0; i < SIZE; i++) {
    ia_dat[i] = i;
  }

  for (i = 0; i < SIZE; i++) {
    printf("ia_dat[%d] = %d\n", i, ia_dat[i]);
  }

  for (i = SIZE-1; i > INSERT +1; i--) {
    ia_dat[i] = ia_dat[i-1];
  }

  ia_dat[INSERT+1] = SIZE;

  printf("\n");

  for (i = 0; i < SIZE; i++) {
    printf("ia_dat[%d] = %d\n", i, ia_dat[i]);
  }

  return 0;
}

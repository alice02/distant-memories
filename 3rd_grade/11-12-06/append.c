#include <stdio.h>
#include <stdlib.h>

#define SIZE (10)

int main(void)
{
  int *ia_dat;
  int *ia_tmp;
  int i;

  ia_dat = (int *)malloc(sizeof(int) * (SIZE));

  for (i = 0; i < SIZE; i++) {
    ia_dat[i] = i;
  }

  for (i = 0; i < SIZE; i++) {
    printf("ia_dat[%d] = %d\n", i, ia_dat[i]);



  return 0;
}

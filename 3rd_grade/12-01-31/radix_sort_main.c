#include "radix_sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  int i;
  int i_size;
  ushort *usa_dat;

  i_size = argc - 1;
  if (i_size == 0) {
    printf("USAGE: %s num1 num2 num3 ...\n", argv[0]);
    exit(1);
  }

  usa_dat = (ushort *)malloc(sizeof(ushort) * (i_size));

  for (i = 0; i < i_size; i++) {
    usa_dat[i] = atoi(argv[i+1]);
  }

  radix_sort(usa_dat, i_size);

  for (i = 0; i < i_size; i++) {
    printf("%d ", usa_dat[i]);
  }
  printf("\n");

  return 0;
}

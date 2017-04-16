#include "bin_sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  DATA *dat;
  int i_size, MAX;
  int i;
 
  i_size = argc-2;

  if (i_size == 0) {
    printf("%s MAX num1 num2 num3 ...\n", argv[0]);
    exit(1);
  }

  dat = (DATA *)malloc(sizeof(DATA) * (i_size));

  for (i = 0; i < i_size; i++) {
    dat[i].key = atoi(argv[i+2]);
  }

  MAX = atoi(argv[1]);

  printf("The maximum range is %d.\n", MAX);
  
  bin_sort(dat, i_size, MAX);

  for (i = 0; i < i_size; i++) {
    printf("%d ", dat[i].key);
  }
  printf("\n");

  return 0;
}

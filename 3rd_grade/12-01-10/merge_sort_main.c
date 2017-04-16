#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i_size;
  int *a, *b;
  int i;

  i_size = argc-1;

  if (i_size == 0) {
    printf("USAGE: %s num1 num2 num3 ...\n", argv[0]);
    exit(1);
  }

  a = (int *)malloc(sizeof(int)*i_size);
  b = (int *)malloc(sizeof(int)*i_size);

  for (i = 0; i < i_size; i++) {
    a[i] = atoi(argv[i+1]);
  }

  merge_sort_array(a, b, 0, i_size-1);

  for (i = 0; i < i_size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}

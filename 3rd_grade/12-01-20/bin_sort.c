#include "bin_sort.h"
#include <stdlib.h>

void bin_sort(DATA a[], int n, int MAX)
{
  int i, j;
  DATA *bin;

  bin = (DATA *)malloc(sizeof(DATA) * (MAX+1));

  for (i = 0; i < MAX; i++) {
    bin[i].key = -1;
  }

  for (i = 0; i < n; i++) {
    bin[a[i].key] = a[i];
  }

  j = 0;
  for (i = 0; i <= MAX; i++) {
    if (bin[i].key != -1) {
      a[j] = bin[i];
      j++;
    }
  }

}

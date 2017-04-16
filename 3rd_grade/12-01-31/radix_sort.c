#include "radix_sort.h"
#include <stdlib.h>

void radix_sort(ushort a[],
		int n)
{
  int i, bit;
  int count[M+1];
  int *ip_index;
  ushort *b;

  b = (ushort *)malloc(sizeof(ushort) * (n));

  for (bit = 0; bit < 16; bit += 4) {

    for (i = 0; i <= M; i++) {
      count[i] = 0;
    }

    for (i = 0; i < n; i++) {
      count[(a[i]>>bit) & MASK]++;
    }

    for (i = 0; i < M; i++) {
      count[i+1] += count[i];
    }

    for (i = n-1; i >= 0; i--) {
      ip_index = &count[(a[i]>>bit) & MASK];
      (*ip_index)--;
      b[*ip_index] = a[i];
    }

    for (i = 0; i < n; i++) {
      a[i] = b[i];
    }

  }

}

#include "dist_count_sort.h"
#include <stdlib.h>

void dist_count_sort(DATA a[],
		     DATA b[],
		     int n,
		     int MAX)
{
  int i;
  int *count;

  count = (int *)malloc(sizeof(int) * (MAX+1));

  for (i = 0; i < MAX; i++) {
    count[i] = 0;
  }

  for (i = 0; i < n; i++) {
    count[a[i].key]++;
  }

  for (i = 0; i < MAX; i++) {
    count[i+1] += count[i];
  }

  for (i = n - 1; i >= 0; i--) {
    count[a[i].key]--;
    b[count[a[i].key]] = a[i];
  }

}

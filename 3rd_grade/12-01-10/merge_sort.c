void merge_sort_array(int a[],
		      int b[],
		      int low,
		      int high)
{
  int mid, i, j, k;

  if (low >= high) {
    return;
  }

  mid = (low + high) / 2;

  merge_sort_array(a, b, low, mid);

  merge_sort_array(a, b, mid + 1, high);

  for (i = low; i <= mid; i++) {
    b[i] = a[i];
  }

  for (i = mid+1, j = high; i <= high; i++, j--) {
    b[i] = a[j];
  }

  i = low;
  j = high;
  for (k = low; k <= high; k++) {
    if (b[i] <= b[j]) {
      a[k] = b[i];
      i++;
    }
    else {
      a[k] = b[j];
      j--;
    }
  }
}

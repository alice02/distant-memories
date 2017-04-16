struct goods
{
  int i_number;
  int i_price;
};

int partition(struct goods data[], int l, int r)
{
  int i, j, pivot;
  struct goods tmp;
  
  i = l-1;
  j = r;
  
  pivot = data[r].i_price;
  
  for (;;) {

    for (i++; data[i].i_price < pivot; i++) {
    }

    for (j--; i < j && pivot < data[j].i_price; j--) {
    }
    
    if (i >= j) {
      break;
    }

    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }

  tmp = data[i];
  data[i] = data[r];
  data[r] = tmp;

  return i;
}

void quick_sort(struct goods data[], int l, int r)
{
  int v;

  if (l >= r) {
    return;
  }

  v = partition(data, l, r);

  quick_sort(data, l, v-1);

  quick_sort(data, v+1, r);
}

void my_sort(struct goods data[], int i_max)
{
  quick_sort(data, 0, i_max-1);
}

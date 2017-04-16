struct goods
{
  int i_number;
  int i_price;
};

void my_sort(struct goods  data[],
	     int  i_max)
{
  int  i, j;
  struct goods  tmp;

  for (i = 1; i < i_max; i++) {
    j = i;
    while (j >= 1 && data[j-1].i_price > data[j].i_price) {
      tmp = data[j];
      data[j] = data[j-1];
      data[j-1] = tmp;
      j--;
    }
  }
}

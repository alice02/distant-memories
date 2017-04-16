struct goods
{
  int i_number;
  int i_price;
};

void my_sort(struct goods  data[],
	     int  i_max)
{
  int  i;
  int  j;
  struct goods  tmp;

  for (i = 0; i < i_max-1; i++) {
    for (j = i_max-1; j > i; j--) {
      if (data[j-1].i_price > data[j].i_price) {
	tmp = data[j];
	data[j] = data[j-1];
	data[j-1] = tmp;
      }
    }
  }

}

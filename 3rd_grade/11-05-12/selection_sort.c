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
  int  i_lowest;
  int  i_lowkey;
  struct goods  tmp;

  for (i = 0; i < i_max-1; i++) {
    i_lowest = i;
    i_lowkey = data[i].i_price;
    for (j = i+1; j < i_max; j++) {
      if (data[j].i_price < i_lowkey) {
	i_lowest = j;
	i_lowkey = data[j].i_price;
      }
      tmp = data[i];
      data[i] = data[i_lowest];
      data[i_lowest] = tmp;
    }
  }
}

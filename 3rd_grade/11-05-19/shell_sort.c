struct goods
{
  int i_number;
  int i_price;
};

void my_sort(struct goods  data[],
	     int  i_max)
{
  int  i, j, h;
  struct goods  tmp;

  for (h = 1; h < (i_max/9); h = h*3+1) 
    ;

  for (; h > 0; h /= 3) {
    for (i = h; i < i_max; i++) {
      j = i;
      while (j >= h && data[j-h].i_price > data[j].i_price) {
	tmp = data[j];
	data[j] = data[j-h];
	data[j-h] = tmp;
	j -= h;
      }
    }
  }
}

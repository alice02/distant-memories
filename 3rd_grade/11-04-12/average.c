double my_average(int i_length,
		  double da_data[])
{
  int i;
  double d_sum = 0.0;
  double d_average;

  for (i=0; i<i_length; i++) {
    d_sum += da_data[i];
  }

  d_average = d_sum / (double)i_length;

  return d_average;
}

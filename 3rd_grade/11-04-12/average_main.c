#include <stdio.h>
#include <stdlib.h>

void my_input(int i_number,
	      double da_nums[]);

double my_average(int i_length,
		  double da_data[]);


int main(int argc,
	 char *argv[])
{
  int  i_num;
  double *dp_data;
  double d_average;

  printf("How many data ? ");
  scanf("%d", &i_num);

  dp_data = (double *)malloc(sizeof(double)*i_num);

  my_input(i_num, dp_data);

  d_average = my_average(i_num, dp_data);

  printf("average = %f\n", d_average);

  free(dp_data);

  return 0;
}

#include <stdio.h>

void my_input(int i_number,
	      double da_nums[])
{
  int  i;

  for (i=0; i<i_number; i++) {
    printf("%d = ", i+1);
    scanf("%lf", &da_nums[i]);
  }
  
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NO 75

double calc_ave(int array[], int no);

int main(void)
{
  srand((unsigned)time(NULL));

  int array[NO];
  int i;

  for (i=0; i<NO; i++) {
    array[i] = (rand()%101)+100;
    printf("array[%d] = %d\n", i, array[i]);
  }

  printf("ave = %f\n", calc_ave(array, NO));

  return 0;
}

double calc_ave(int array[], int no)
{
  int sum, i;

  sum = 0;
  for (i=0; i<no; i++) {
    sum += array[i];
  }

  return (double)sum/no;
}

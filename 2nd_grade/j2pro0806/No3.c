#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calc_ave(int array[], int no);

int main(void)
{
  srand((unsigned)time(NULL));

  int array[8], i;

  for (i=0; i<8; i++) {
    array[i] = rand()%10 + 1;
    printf("array[%d] = %d\n", i, array[i]);
  }

  printf("ave = %f\n", calc_ave(array, i));

  return 0;
}

double calc_ave(int array[], int no)
{
  int sum=0, i;

  for (i=0; i<no; i++) {
    sum += array[i];
  }

  return (double)sum/no;
}

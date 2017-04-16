#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calc_ave(int array[], int no);

int main(void)
{
  srand((unsigned)time(NULL));

  int i;
  int array[8];

  for (i=0; i<8; i++) {
    array[i] = rand()%11;
    printf("array[%d] = %d\n", i, array[i]);
  }

  printf("ave = %f\n", calc_ave(array, i));

  return 0;
}

double calc_ave(int array[], int no)
{
  int ave=0, i;

  for (i=0; i<no; i++) {
    ave += array[i];
  }

  return (double)ave/no;
}

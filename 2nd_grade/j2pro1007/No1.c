#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 10

int main(void)
{
  srand((unsigned)time(NULL));

  int array[NUMBER];
  int i, sum;

  sum = 0;

  for (i=0; i<NUMBER; i++) {
    array[i] = rand()%100;
    sum += array[i];
    printf("array[%d] = %d\n", i, array[i]);
  }

  printf("ave = %f\n", (double)sum/i);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 500

int sum_of(int vc[], int no)
{
  int i,sum;

  sum = 0;

  for(i=0; i<no; i++) {
    sum += vc[i];
  }

  return sum;
}

int max_of(int vc[], int no)
{
  int i, max;

  for (i=0; i<no; i++) {
    if (i==0) {
      max = vc[i];
    }else if(vc[i]>max) {
      max = vc[i];
    }
  }

  return max;
}

int min_of(int vc[], int no)
{
  int i, min;

  for (i=0; i<no; i++) {
    if (i==0) {
      min = vc[i];
    }else if(vc[i]<min) {
      min = vc[i];
    }
  }

  return min;
}


int main(void)
{
  srand((unsigned)time(NULL));

  int array[NUMBER];
  int i;

  for (i=0; i<NUMBER; i++) {
    array[i] = rand() % 100000;
    printf("array[%d] = %d\n", i, array[i]);
  }

  printf("sum = %d\n", sum_of(array, i));

  printf("max = %d\n", max_of(array, i));

  printf("min = %d\n", min_of(array, i));

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 1000000

void initialize(int array[]);
void disp_array(int array[]);
void sort(int array[]);
void swap(int *a, int *b);

int main(void)
{
  int array[NUM];
  clock_t start, end;
  double req_time;  

  initialize(array);

  start = clock();

  qsort(array, 0, NUM-1);

  end = clock();

  req_time = (double)(end-start)/CLOCKS_PER_SEC;
  printf("req_time = %f\n", req_time);

  return 0;
}

void initialize(int array[])
{
  int i;
  
  srand(0);

  for (i=0; i<NUM; i++) {
    array[i] = rand()%100;
  }
}

void disp_array(int array[])
{
  int i;

  for (i=0; i<NUM; i++) {
    printf("%d\n", array[i]);
  }
  printf("\n");

}


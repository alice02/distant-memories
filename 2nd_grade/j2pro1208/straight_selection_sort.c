#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10000000

void initialize(int array[]);
void disp_array(int array[]);
void sort(int array[]);
void swap(int *a, int *b);
void oedasort(int *, int, int);

int main(void)
{
  int array[NUM];
  clock_t start, end;
  double req_time;  

  initialize(array);
  //  disp_array(array);

  start = clock();

  //  sort(array);
  oedasort(array, 0, NUM-1);

  end = clock();

  //  disp_array(array);

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

void sort(int array[])
{
  int i, j;
  int min_index;

  for (i=0; i<NUM-1; i++) {
    min_index = i;
    for (j=i+1; j<NUM; j++) {
      if(array[j]<array[min_index]) {
	min_index = j;
      }
    }
    swap(&array[i], &array[min_index]);
  }

}

void swap(int *a, int *b)
{
  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}

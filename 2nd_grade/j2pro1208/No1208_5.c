#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100000

void initialize(int array[]);
void disp_array(int array[]);
void bubble_sort(int array[]);
void sort(int array[]);
void swap(int *a, int *b);
void oedasort(int *, int, int);

int main(void)
{
  int array[NUM];
  clock_t start_1, start_2, start_3, end_1, end_2, end_3;
  double req_time_1, req_time_2, req_time_3;  

  initialize(array);
  //  disp_array(array);

  start_1 = clock();
  sort(array);
  end_1 = clock();

  initialize(array);

  start_2 = clock();
  bubble_sort(array);
  end_2 = clock();

  initialize(array);

  start_3 = clock();
  oedasort(array, 0, NUM-1);
  end_3 = clock();

  // disp_array(array);

  req_time_1 = (double)(end_1-start_1)/CLOCKS_PER_SEC;
  req_time_2 = (double)(end_2-start_2)/CLOCKS_PER_SEC;
  req_time_3 = (double)(end_3-start_3)/CLOCKS_PER_SEC;

  printf("単純選択ソート = %f\n", req_time_1);
  printf("バブルソート = %f\n", req_time_2);
  printf("オオエダソート = %f\n", req_time_3);

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

void bubble_sort(int array[])
{
  int i, j;

  for (i=0; i<NUM-1; i++) {
    for (j=NUM-1; i<j; j--) {
      if(array[j]<array[j-1]) {
	swap(&array[j], &array[j-1]);	
      }
    }
  }
}

void swap(int *a, int *b)
{
  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}

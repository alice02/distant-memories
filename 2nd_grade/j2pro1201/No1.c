#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100000
#define MAX 10000

void set_array_random(int array[]);
void disp_array(int array[]);
void calc_sort(int array[]);

int main(void)
{
  srand((unsigned)time(NULL));
  int array[NUM];
  int i;

  set_array_random(array);

  printf("ソート前\n");
  disp_array(array);

  calc_sort(array);

  printf("ソート後\n");
  disp_array(array);

  return 0;
}

void set_array_random(int array[])
{
  int i;

  for (i=0; i<NUM; i++) {
    array[i] = rand()%MAX;
  }

}

void disp_array(int array[])
{
  int i;

  for (i=0; i<NUM; i++) {
    printf("array[%d] = %d\n", i, array[i]);
  }

}

void calc_sort(int array[])
{
  int i, j, dummy;

  for (i=0; i<NUM; i++) {
    for (j=i+1; j<NUM; j++) {
      if (array[i]>array[j]) {
	dummy = array[i];
	array[i] = array[j];
	array[j] = dummy;
      }
    }
  }
}

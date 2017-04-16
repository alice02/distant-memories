#include <stdio.h>
#include <stdlib.h>

#define NUM 10

void initialize(int array[]);
void disp_array(int array[]);
void sort(int array[]);
void swap(int *a, int *b);

int main(void)
{
  int array[NUM];

  initialize(array);
  disp_array(array);

  sort(array);
  disp_array(array);

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
  int min_index, comp, chan;

  comp = chan = 0;

  for (i=0; i<NUM-1; i++) {
    min_index = i;
    for (j=i+1; j<NUM; j++) {
      if(array[j]<array[min_index]) {
	min_index = j;
      }
      comp++;
    }
    swap(&array[i], &array[min_index]);
    chan++;
  }

  printf("Èæ³Ó²ó¿ô:%d  ¸ò´¹²ó¿ô:%d\n", comp, chan);

}

void swap(int *a, int *b)
{
  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}

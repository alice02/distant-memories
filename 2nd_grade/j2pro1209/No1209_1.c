#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10

void disp_array(int array[], int attack[], int defence[]);
void set(int array[], int attack[], int defence[]);
void sort(int array[], int arrack[], int defence[]);
void bubble_sort(int array[], int arrack[], int defence[]);
void swap(int *a, int *b);

int main(void) 
{
  srand((unsigned)time(NULL));

  int array[NUM], attack[NUM], defence[NUM];

  set(array, attack, defence);

  disp_array(array, attack, defence);

  //sort(array, attack, defence);
  bubble_sort(array, attack, defence);

  disp_array(array, attack, defence);

}

void set(int array[], int attack[], int defence[])
{
  int i;

  for (i=0; i<NUM; i++) {
    attack[i] = rand()%100;
  }

  for (i=0; i<NUM; i++) {
    defence[i] = rand()%100;
  }

  for (i=0; i<NUM; i++) {
    array[i] = i;
  }

}

void disp_array(int array[], int attack[], int defence[])
{
  int i;

  printf("No    Attack   Defence\n");

  for (i=0; i<NUM; i++) {
    printf("[%2d]    %2d       %2d\n", array[i], attack[i], defence[i]);
  }

  printf("\n");
}

void sort(int array[], int attack[], int defence[])
{
  int i, j;
  int min_index;

  for (i=0; i<NUM-1; i++) {
    min_index = i;
    for (j=i+1; j<NUM; j++) {
      if (attack[j]<attack[min_index]) {
	min_index = j;
      }
    }
    swap(&array[i], &array[min_index]);
    swap(&attack[i], &attack[min_index]);
    swap(&defence[i], &defence[min_index]);
  }
}

void bubble_sort(int array[], int attack[], int defence[])
{
  int i, j;

  for (i=0; i<NUM-1; i++) {
    for (j=NUM-1; j>i; j--) {
      if (attack[j]<attack[j-1]) {
	swap(&array[j], &array[j-1]);
	swap(&attack[j], &attack[j-1]);
	swap(&defence[j], &defence[j-1]);
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

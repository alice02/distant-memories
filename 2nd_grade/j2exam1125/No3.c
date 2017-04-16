#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 40

void disp_array(int array[]);
void set_array(int array[]);

int main(void)
{
  srand((unsigned)time(NULL));

  int array[NUM];

  set_array(array);

  disp_array(array);

  return 0;
}

void set_array(int array[])
{
  int i;

  for (i=0; i<NUM; i++) {
    array[i] = i;
  }

}

void disp_array(int array[])
{
  int i, j, num, count=0;
  int table[7] = {6, 6, 6, 6, 6, 5, 5};

  for (i=0; i<7; i++) {
    printf("group:%d\n", i+1); 
    for (j=0; j<table[i]; j++) {
      if (i<5) {
	printf("[%d] : %d\n", j+1, array[(6*i)+j]);
      }
      else {
	printf("[%d] : %d\n", j+1, array[(5*i)+j+5]);
      }
    }
  }
}

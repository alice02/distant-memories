#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void set_random(int array[]);
void disp_array(int array[]);
void calc_two_min(int array[], int *min1, int *min2);

int main(void)
{
  int data[SIZE];
  int min1, min2;

  srand((unsigned)time(NULL));

  set_random(data);

  disp_array(data);

  calc_two_min(data, &min1, &min2);
  printf("min1=%d\n", min1);
  printf("min2=%d\n", min2);

  return 0;
}

void set_random(int array[])
{
  int i;

  for (i=0; i<SIZE; i++) {
    array[i] = rand()%10;
  }

}

void disp_array(int array[]) 
{
  int i;

  for (i=0; i<SIZE; i++) {
    printf("array[%d]=%d\n", i, array[i]);
  }

}

void calc_two_min(int array[], int *min1, int *min2)
{
  int i;

  for (i=0; i<SIZE; i++) {
    if (i==0 && array[i]!=0) {
      *min1 = *min2 = array[i];
    }
    else if (i==0 && array[i]==0) {
      *min1 = array[i];
      *min2 = array[i+1];
    }
    else {
	if (array[i] <= *min1) {
	  *min2 = *min1;
	  *min1 = array[i];
	}
	else if (array[i] <= *min2) {
	  *min2 = array[i];
	}
    }   
  }
}

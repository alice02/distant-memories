#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 100

void set_char_random(char array[]);
void disp_char(char array[]);
void calc_sort(char array[]);

int main(void)
{
  srand((unsigned)time(NULL));
  char array[NUM];
  int i;

  set_char_random(array);

  printf("ソート前\n");
  disp_char(array);

  calc_sort(array);

  printf("ソート後\n");
  disp_char(array);

  return 0;
}

void set_char_random(char array[])
{
  int i;

  for (i=0; i<NUM; i++) {
    array[i] = 'a' + rand()%26;
  }

}

void disp_char(char array[])
{
  int i;

  for (i=0; i<NUM; i++) {
    printf("array[%d] = %c\n", i, array[i]);
  }

}

void calc_sort(char array[])
{
  int i, j;
  char dummy;

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

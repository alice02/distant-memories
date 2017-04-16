#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10

void count(const int array[], int *ct_2, int *ct_3)
{
  int i;

  for (i=0; i<NUM; i++) {
    if (array[i]%2==0) {
      *ct_2 = *ct_2 + 1;
    }
    if (array[i]%3==0) {
      *ct_3 = *ct_3 + 1;
    }
  }

}

int main(void)
{
  int i;
  int vc[NUM];
  int count_2=0;
  int count_3=0;

  srand((unsigned)time(NULL));

  for(i=0; i<NUM; i++){
    vc[i] = rand()%100;
    printf("vc[%d] = %d\n", i, vc[i]);
  }

  count(vc, &count_2, &count_3);

  printf("2¤ÎÇÜ¿ô:%d\n", count_2);
  printf("3¤ÎÇÜ¿ô:%d\n", count_3);

  return 0;
}


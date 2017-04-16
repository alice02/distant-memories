#include <stdio.h>

#define NUM 3

int main(void)
{
  int i;
  double number[NUM];
  double sum;
  double average;

  for (i=0; i<NUM; i++) {
    do {
      printf("[%d] 正の値を入力してください．\n", i);
      scanf("%lf", &number[i]);
    } while (number[i]<0);
  }

  sum = 0;
  for (i=0; i<NUM; i++) {
    sum += number[i];
  }

  average = sum/NUM;

  for (i=0; i<NUM; i++) {
    printf("number[%d] = %f\n", i, number[i]);
  }
  printf("--------------------\n");
  printf("  average = %f\n", average);

  return 0;
}

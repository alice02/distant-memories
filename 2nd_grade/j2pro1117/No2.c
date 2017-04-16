#include <stdio.h>

void narabikae(int *num1, int *num2, int *num3);
void swap(int *x, int *y);

int main(void)
{
  int num1, num2, num3;

  printf("num1 = ");
  scanf("%d", &num1);
  printf("num2 = ");
  scanf("%d", &num2);
  printf("num3 = ");
  scanf("%d", &num3);

  narabikae(&num1, &num2, &num3);

  printf("\nnum1 = %d   num2 = %d   num3 = %d\n", num1, num2, num3);

  return 0;
}

void narabikae(int *num1, int *num2, int *num3)
{
  int tmp_1, tmp_2, tmp_3;

  if (*num1<*num3) {
    swap(num1, num3);
  }
  if (*num2<*num3) {
    swap(num2, num3);
  }
  if (*num1<*num2) {
    swap(num1, num2);
  }

}

void swap(int *x, int *y)
{
  int tmp_x, tmp_y;

    tmp_x = *x;
    tmp_y = *y;

    *y = tmp_x;
    *x = tmp_y;

    tmp_x = *x;
    tmp_y = *y;
    
}

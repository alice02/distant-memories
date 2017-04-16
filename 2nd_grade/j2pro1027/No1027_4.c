#include <stdio.h>

void two_num_swap(int *x, int *y);

int main(void)
{
  int x, y;

  printf("x = ");
  scanf("%d", &x);
  printf("y = ");
  scanf("%d", &y);

  two_num_swap(&x, &y);

  printf("x = %d   y = %d\n", x, y);

  return 0;
}

void two_num_swap(int *x, int *y)
{
  int k;

  if (*x<*y) {
    k = *x;
    *x = *y;
    *y = k;
  }
}

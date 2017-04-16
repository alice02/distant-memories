#include <stdio.h>

int calc_add_div(int n1, int n2, int *mul, int *div)
{
  *mul = n1 * n2;
  *div = n1/ n2;

  if (n1%n2 == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

int main(void)
{
  int num_1, num_2, mul, div, val;

  printf("num_1 = ");
  scanf("%d", &num_1);

  printf("num_2 = ");
  scanf("%d", &num_2);

  val = calc_add_div(num_1, num_2, &mul, &div);

  if (val == 0) {
    printf("Í¾¤ê:%d\n", num_1%num_2);
  }

  return 0;
}

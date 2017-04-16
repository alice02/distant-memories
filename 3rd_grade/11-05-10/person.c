#include <stdio.h>

struct person {
  int i_num;
  double d_data;
};

int main(void)
{
  struct person taro;

  printf("i_num = ");
  scanf("%d", &(taro.i_num));
  printf("d_data = ");
  scanf("%lf", &(taro.d_data));

  printf("i_num = %d\n", taro.i_num);
  printf("d_data = %f\n", taro.d_data);

  return 0;
}

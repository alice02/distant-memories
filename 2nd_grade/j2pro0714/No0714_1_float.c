#include <stdio.h>

float calc(float, float);

int main(void)
{
  float len;
  float num;

  printf("ヨウカンの長さ = ");
  scanf("%f", &len);
  printf("人数 = ");
  scanf("%f", &num);

  printf("%fcmずつ分ければよいと思います.\n", calc(len, num));

  return 0;
}

float calc(float len, float num)
{
  float ans;

  ans = len/num;

  return ans;
}

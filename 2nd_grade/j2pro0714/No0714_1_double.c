#include <stdio.h>

double calc(double, double);

int main(void)
{
  double len;
  double num;

  printf("ヨウカンの長さ = ");
  scanf("%lf", &len);
  printf("人数 = ");
  scanf("%lf", &num);

  printf("%fcmずつ分ければよいと思います.\n", calc(len, num));

  return 0;
}

double calc(double len, double num)
{
  double ans;

  ans = len/num;

  return ans;
}

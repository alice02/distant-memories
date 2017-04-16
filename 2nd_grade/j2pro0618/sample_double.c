#include <stdio.h>

int main(void)
{
  float ff  = 1000.0 / 1.125;
  double dd = 1000.0 / 1.125;
  double ans;
  double input;

  printf("ff=%.20f\n", ff);
  printf("dd=%.20f\n", dd);

  ans = 1/2;
  printf("1 ans=%f\n", ans);

  ans = 1.0/2;
  printf("2 ans=%f\n", ans);

  ans = 1.0/2.0;
  printf("3 ans=%f\n", ans);

  ans = (double)(1/2);
  printf("4 ans=%f\n", ans);

  ans = (double)1/2;
  printf("5 ans=%f\n", ans);

  printf("1 input=");
  scanf("%f", &input);
  printf("1 input=%f\n", input);

  printf("2 input=");
  scanf("%lf", &input);
  printf("2 input=%f\n", input);

  return 0;
}

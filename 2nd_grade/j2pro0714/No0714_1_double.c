#include <stdio.h>

double calc(double, double);

int main(void)
{
  double len;
  double num;

  printf("�襦�����Ĺ�� = ");
  scanf("%lf", &len);
  printf("�Ϳ� = ");
  scanf("%lf", &num);

  printf("%fcm����ʬ����Ф褤�Ȼפ��ޤ�.\n", calc(len, num));

  return 0;
}

double calc(double len, double num)
{
  double ans;

  ans = len/num;

  return ans;
}

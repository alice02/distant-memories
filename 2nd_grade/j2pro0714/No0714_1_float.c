#include <stdio.h>

float calc(float, float);

int main(void)
{
  float len;
  float num;

  printf("�襦�����Ĺ�� = ");
  scanf("%f", &len);
  printf("�Ϳ� = ");
  scanf("%f", &num);

  printf("%fcm����ʬ����Ф褤�Ȼפ��ޤ�.\n", calc(len, num));

  return 0;
}

float calc(float len, float num)
{
  float ans;

  ans = len/num;

  return ans;
}

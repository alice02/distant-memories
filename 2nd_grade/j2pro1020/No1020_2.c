#include <stdio.h>

void calc_count(int val, int *a, int *b)
{
  *a = val / 2;
  *b = val / 3;
}


int main(void)
{
  int num;
  int count_2, count_3;

  count_2 = count_3 = 0;

  printf("num = ");
  scanf("%d", &num);

  calc_count(num, &count_2, &count_3);

  printf("[%d]��2�ǳ�ä��Ȥ��θĿ���%d\n", num, count_2);
  printf("[%d]��3�ǳ�ä��Ȥ��θĿ���%d\n", num, count_3);

  return 0;
}


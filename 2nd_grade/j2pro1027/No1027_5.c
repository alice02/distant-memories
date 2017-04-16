#include <stdio.h>

int what_day(int x, int *month, int *day);

int main(void)
{
  int x, month, day;

  month = 1;
  day = 0;

  printf("x = ");
  scanf("%d", &x);

  if (what_day(x, &month, &day) == 1) {
    printf("input error!!\n");
  }
  else {
    printf("2010年%d月%d日です\n", month, day);
  }

  return 0;
}

int what_day(int x, int *month, int *day)
{
  if (x<1 || 364<x) {
    return 1;
  }
  else {
    if (x<=31) {
      *day += x;
    }
    else if (x<=58) {
      *day += x%30-1;
      *month = *month + 1;
    }
  }
}

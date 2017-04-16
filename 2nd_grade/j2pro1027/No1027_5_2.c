#include <stdio.h>

int what_day(int x, int *month, int *day);

int main(void)
{
 
  int x, month, day;

  printf("x = ");
  scanf("%d", &x);

  if (what_day(x, &month, &day) == 1){
    printf("input error!!\n");
    return 0;
  }
  else {
    printf("%d日後は2010年%d月%d日です。\n", x, month, day);
  }

  return 0;
}

int what_day(int x, int *month, int *day)
{
  int num[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int i;

  if (x<0 || 365<x) {
    return 1;
  }
  else {
    for (i=0; num[i]<x; i++) {
      x -= num[i];
    }
    *day = x;
    *month = i+1;
  }
}

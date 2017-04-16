#include <stdio.h>

int main(void)
{
  int i, num, ans[8], bit;

  printf("input number = ");
  scanf("%d", &num);

  bit = 1;
  for (i=0; i<8; i++) {
    if (num & bit) {
      ans[i] = 1;
    }
    else {
      ans[i] = 0;
    }
    bit <<= 1;
  }

  for (i=8; i>0; i--) {
    printf("%d", ans[i-1]);
  }

  printf("\n");

  return 0;
}

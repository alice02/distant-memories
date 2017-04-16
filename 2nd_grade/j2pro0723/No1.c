#include <stdio.h>

#define BitSize 8

int main(void)
{
  int num, i, bit, ans[BitSize];

  printf("num = ");
  scanf("%d", &num);

  bit = 1;
  for (i=0; i<BitSize; i++){
    if (num&bit) {
      ans[i] = 1;
    }
    else {
      ans[i] = 0;
    }
    bit <<= 1;
  }

  for (i=BitSize; i>0; i--) {
    printf("%d", ans[i-1]);
  }

  printf("\n");

  return 0;
}

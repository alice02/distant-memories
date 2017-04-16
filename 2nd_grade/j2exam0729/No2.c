#include <stdio.h>

#define BIT 3

int main(void)
{
  int num, i;
  int ans[BIT];

  do {
    printf("input number = ");
    scanf("%d", &num);
  } while(num<0 || 255<num);

  for (i=0; i<BIT; i++) {
    ans[i] = num%8;
    num /= 8;
  }

  for (i=BIT-1; 0<=i; i--) {
    printf("%d", ans[i]);
  }

  printf("\n");

  return 0;
}

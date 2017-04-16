#include <stdio.h>

int main(void)
{
  int num, i, ans[3];

  do {
    printf("num = ");
    scanf("%d", &num);
  }while(num<0 || 255<num);

  for (i=0; i<3; i++) {
    ans[i] = num%8;
    num /= 8;
  }

  for (i=3; 0<i; i--) {
    printf("%d", ans[i-1]);
  }

  printf("\n");

  return 0;
}

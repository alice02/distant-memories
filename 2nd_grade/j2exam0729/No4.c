#include <stdio.h>

int main(void)
{
  int num, i, sum=0;

  printf("num = ");
  scanf("%d", &num);

  for (i=0; num!=0; i++) {
    sum += num%10;
    num /= 10;
  }

  printf("%d\n", sum);


  return 0;
}

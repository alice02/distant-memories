#include <stdio.h>

int main(void)
{
  int num;

  do {
    printf("num = ");
    scanf("%d", &num);
  }while(num<0 || 100<num);

  printf("%d\n", num);

  return 0;
}

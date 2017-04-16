#include <stdio.h>

#define NUMBER 8 //2-10
#define BIT 8

int main(void)
{
  int i, num[BIT];
  int input;

  do{
    printf("input number = ");
    scanf("%d", &input);
  }while(input<0 || 255<input);

  for (i=0; i<BIT; i++) {
    num[i] = input%NUMBER;
    input /= NUMBER;
  }

  for (i=BIT; i>0; i--) {
      printf("%d",num[i-1]);
  }

  printf("\n");

  return 0;
}

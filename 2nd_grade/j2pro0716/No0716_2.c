#include <stdio.h>

int main(void)
{
  int i, num[8];
  int input;

  do{
    printf("input number = ");
    scanf("%d", &input);
  }while(input<0 || 255<input);

  for (i=0; i<8; i++) {
    num[i] = input%16;
    input /= 16;
  }

  for (i=8; i>0; i--) {
    if (num[i-1]>=10){
      printf("%c", 'A'+num[i-1]%10);
    }
    else {
      printf("%d",num[i-1]);
    }
  }

  printf("\n");

  return 0;
}

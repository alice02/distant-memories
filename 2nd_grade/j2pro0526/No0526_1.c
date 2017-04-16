#include <stdio.h>

int main(void)
{

  int a;
  int b;

  for (a=1; a<=9; a++) {
    for (b=1; b<=9; b++) {
      printf("%3d",a*b);
    }
	printf("\n");
  }

  return 0;
}

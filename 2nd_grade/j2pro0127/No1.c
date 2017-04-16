#include <stdio.h>

#define NUM 4

int main(void)
{
  int i, j;

  for (i=0; i<NUM; i++) {
    for (j=0; j<=i; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

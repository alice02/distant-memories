#include <stdio.h>

#define NUM 5

int main(void)
{
  int i;
  int vc[NUM] = {0, 10, 20, 30, 40};
  int *pta;
  int *ptb;

  pta = vc;

  for (i=0; i<NUM; i++) {
    printf("*(pta+%d) = %d\n", i, *(pta+i));
  }

  ptb = &vc[3];

  printf("%d\n", *(ptb-2));
  printf("%d\n", *ptb-2);

  return 0;
}

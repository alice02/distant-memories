#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned)time(NULL));

  int array[4][2];
  int i, j, val;

  for (i=0; i<4; i++) {
    for (j=0; j<2; j++) {
      val = rand()%500 + 500;
      printf("%d ", val);
    }
    printf("\n");
  }

  return 0;
}

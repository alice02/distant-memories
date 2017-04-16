#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
  int i, r;

  srand(time(NULL));

  for (i = 0; i < 10; i++)
  {
    r = rand() % 10000;
    printf("%d ", r);
  }
  printf("\n");

  return 0;
}

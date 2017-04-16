#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

  int i;
  int val;

  srand((unsigned)time(NULL));

  i = 0;
  while (i < 10) {
    val = rand();
    printf("%d\n" , val);
    i++;
  }

  return 0;
}

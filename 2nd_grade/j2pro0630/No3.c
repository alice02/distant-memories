#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

  char val;

  srand((unsigned)time(NULL));

  val = rand() % 26;

  val += 'A';

  printf("%c\n", val);

  return 0;
}

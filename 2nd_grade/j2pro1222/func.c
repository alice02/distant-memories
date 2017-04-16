#include <stdlib.h>
#include <time.h>

int func(int num)
{
  int a;

  srand((unsigned)time(NULL));

  a = num*(rand()%10);

  return a;
}

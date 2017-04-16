#include <stdio.h>

#define PI 3.141592

int main(void)
{

  double r;

  printf("r = ");
  scanf("%lf", &r);

  printf("%f\n", 2*r*PI);

  return 0;
}

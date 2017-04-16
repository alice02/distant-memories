#include <stdio.h>

double my_centi2inch(double d_centi);


int main(void)
{
  double  d_centi;
  double  d_inch;

  printf("Please input number (centi) = ");
  scanf("%lf", &d_centi);

  d_inch = my_centi2inch(d_centi);
  printf("%lf centi is equal to %lf inch.\n", d_centi, d_inch);

  return 0;
}

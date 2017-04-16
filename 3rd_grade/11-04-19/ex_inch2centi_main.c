#include <stdio.h>

double my_inch2centi(double d_inch);


int main(void)
{
  double  d_centi;
  double  d_inch;

  printf("Please input number (inch) = ");
  scanf("%lf", &d_inch);

  d_centi = my_inch2centi(d_inch);
  printf("%lf inch is equal to %lf centi.\n", d_inch, d_centi);

  return 0;
}

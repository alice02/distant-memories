#include <stdio.h>

struct person
{
  int i_num;
  double d_height;
};

void my_input(struct person  data[], int  i_max)
{
  int  i;

  for (i=0; i<i_max; i++) {
    printf("%2d : num = ", i);
    scanf("%d", &data[i].i_num);
    printf("     height = ");
    scanf("%lf", &data[i].d_height);
  }
  printf("\n");
}

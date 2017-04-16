#include <stdio.h>
#include <stdlib.h>

struct person
{
  int i_num;
  double d_height;
};

void my_input(struct person data[], int i_max);

int main(int argc, char *argv[])
{
  int  i;
  int  i_max;
  struct person  *data;

  if (argc -1 != 1)
  {
    printf("USAGE: %s int_number\n", argv[0]);
    exit(1);
  }

  i_max = atoi(argv[1]);

  data = (struct person *)malloc(sizeof(struct person)*i_max);

  my_input(data, i_max);

  for (i=0; i<i_max; i++) {
    printf("%d: %d %f\n", i, data[i].i_num, data[i].d_height);
  }

  free(data);

  return 0;
}


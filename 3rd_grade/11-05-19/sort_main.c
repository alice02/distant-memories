#include <stdio.h>
#include <stdlib.h>

struct goods
{
  int i_number;
  int i_price;
};

void my_sort(struct goods data[], int i_max);

int main(int argc, char *argv[])
{
  int i_max;
  struct goods *data;
  FILE *fp;
  int i;

  if (argc-1 != 1) {
    printf("USAGE: %s dataFile\n", argv[0]);
    exit(1);
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("ERROR: Can't read %s\n", argv[1]);
    exit(1);
  }

  fscanf(fp, "%d", &i_max);

  data = (struct goods *)malloc(sizeof(struct goods)*i_max);

  for (i=0; i<i_max; i++) {
    fscanf(fp, "%d %d", &data[i].i_number, &data[i].i_price);
  }

  my_sort(data, i_max);

  for (i=0; i<i_max; i++) {
    printf("%d %d %d\n", i, data[i].i_number, data[i].i_price);
  }

  free(data);

  return 0;
}

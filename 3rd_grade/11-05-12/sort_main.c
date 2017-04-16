#include <stdio.h>
#include <stdlib.h>

struct goods
{
  int i_number;
  int i_price;
};

int main(int argc, char *argv[])
{
  int  i_max;
  struct goods  *data;
  FILE *fr;
  int  i;

  if (argc-1 != 1) {
    printf("%s dataFile\n", argv[0]);
    exit(1);
  }

  fr = fopen(argv[1], "r");
  if (fr == NULL) {
    printf("can't open file.\n");
    exit(1);
  }

  fscanf(fr, "%d", &i_max);

  data = (struct goods*)malloc(sizeof(struct goods)*i_max);

  for (i=0; i<i_max; i++) {
    fscanf(fr, "%d %d", &data[i].i_number, &data[i].i_price);
  }

  my_sort(data, i_max);

  for (i=0; i<i_max; i++) {
    printf("%d %d %d\n", i, data[i].i_number, data[i].i_price);
  }

  fclose(fr);

  free(data);

  return 0;
}

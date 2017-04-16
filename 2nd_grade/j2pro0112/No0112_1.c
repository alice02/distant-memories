#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp_write;
  int num, i;

  fp_write = fopen("foo.dat", "w");
  if (fp_write==NULL) {
    printf("can't open file.\n");
    exit(1);
  }

  for (i=0; i<10; i++) {
    printf("num[%d] = ", i);
    scanf("%d", &num);
    fprintf(fp_write, "%d %d\n", i, num);
  }

  fclose(fp_write);

  return 0;
}

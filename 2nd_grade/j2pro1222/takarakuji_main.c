#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int takarakuji(int kumi, int no);

int main(void)
{
  int kumi, no;
  int money;
  int property;
  int i;
  FILE *fp;

  fp = fopen("takarakuji.dat","w");
  if (fp==NULL) {
    printf("can't open file.\n");
    exit(1);
  }

  property = 0;

  for (kumi=1; kumi<=100; kumi++) {
    for (no=100000; no<199999; no++) {

    property -= 300;

    money = takarakuji(kumi, no);
    property += money;

    printf("money=%d, property=%d\n", 
	   money, property);

    fprintf(fp, "%d\n", property);

    }
  }

  fclose(fp);

  return 0;
}

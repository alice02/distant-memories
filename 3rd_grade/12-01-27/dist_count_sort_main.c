#include "dist_count_sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,
	 char *argv[])
{
  DATA *dat, *ans;
  int i_size, MAX;
  int i;

  i_size = argc-2;
 
  if (i_size == 0) {
    printf("%s MAX num1 num2 num3 ...\n", argv[0]);
    exit(1);
  }

  dat = (DATA *)malloc(sizeof(DATA) * i_size);
  ans = (DATA *)malloc(sizeof(DATA) * i_size);

  for (i = 0; i < i_size; i++) {
    dat[i].key = atoi(argv[i+2]);
    dat[i].other = i;
  }

  MAX = atoi(argv[1]);

  printf("The maximum range is %d.\n", MAX);
  
  dist_count_sort(dat ,ans, i_size, MAX);

  for (i = 0; i < i_size; i++) {
    printf("%d.%d ", ans[i].key, ans[i].other);
  }
  printf("\n");


  return 0;
}

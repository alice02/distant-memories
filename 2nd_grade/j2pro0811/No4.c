#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned)time(NULL));

  int i, x, y;
  int num[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  int flag[3][3] = {{0},{0}};

  for (i=1; i<=3*3; i++) {
    do {
      x = rand()%3;
      y = rand()%3;
    } while(flag[x][y]==1);

    flag[x][y] = 1;

    printf("%d ", num[x][y]);
    if (i%3==0) {
      printf("\n");
    }
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand((unsigned)time(NULL));

  int array[3][4];
  int num, i;

  for (num=0; num<3; num++){
    for(i=0; i<4; i++){
      array[num][i] = rand() %31 +50;
      printf("%d ",array[num][i]);  
    }
    printf("\n");
  }

  return 0;
}

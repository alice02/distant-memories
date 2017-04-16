#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

  int val,i,j;
  int count[10];

  for (i=0; i<10; i++) {
    count[i] = 0;
  }

  srand((unsigned)time(NULL));

  for (i=0; i<1000; i++) {
    val = rand() % 100;
    printf("%d\n", val);
    for (j=10; j<100; j=j+10) {
      if(val<j){
	count[i]=count[i] + 1;
	printf("count[%d]=%d   %d\n", i , count[i] , j);
      }
    }
  }

  printf("counnt = %d\n", count[0]);

  return 0;
}

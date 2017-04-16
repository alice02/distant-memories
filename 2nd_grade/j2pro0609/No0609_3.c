#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  int i=0;
  int val;

  while(i<20){
    val = rand()%21;
    if(val>=10){
      printf("%d\n",val);
      i++;
    }
  }

  return 0;
}

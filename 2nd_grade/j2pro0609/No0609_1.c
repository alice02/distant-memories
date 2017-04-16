#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  int i;
  int val;



  i = 0;
  while (i < 200){
  val = rand();
  printf("%d\n" , val%5);
  i++;
  }

  return 0;
}

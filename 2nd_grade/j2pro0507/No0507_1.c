#include <stdio.h>

void message(void)
{
  printf("Have Fun With Programming!\n");
}

int main(void)
{

  int i=0;

  while(i<7){
    message();
    i++;
  }

  return 0;
}

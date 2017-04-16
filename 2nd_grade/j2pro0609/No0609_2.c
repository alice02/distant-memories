#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_dice_number();

int main(void)
{

  int n;

  srand((unsigned)time(NULL));

  n = get_dice_number();

  printf("%d\n", n);

  return 0;
}

int get_dice_number()
{

  int val=0;

  while(val==0){
    val = rand()%7;
  }

  return val;
}


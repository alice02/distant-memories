#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_dice_number(void);

int main(void)
{

  int number, i, count=0;

  srand((unsigned)time(NULL));

  for (i=0; i<100; i++) {

    number = get_dice_number();
    
    if(number==1){
      count++;
    }
    
  }
  
  printf("1は%d回出ました\n", count);

  return 0;
}

int get_dice_number(void)
{

  int val;

  val = rand() % 6;

  val++;

  return val;
}

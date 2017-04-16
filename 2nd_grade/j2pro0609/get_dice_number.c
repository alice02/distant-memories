#include <stdlib.h>
#include <time.h>

int get_dice_number()
{

  int val=0;

  srand((unsigned)time(NULL));

  while(val==0){
    val = rand()%7;
  }

  return val;

}

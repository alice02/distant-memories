#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_dice_number(void);

int main(void)
{

  int number, i;
  int count[6] = { 0 };

  srand((unsigned)time(NULL));

  for (i=0; i<10000; i++) {

    number = get_dice_number();
    
    if(number==1){
      count[0]++;
    }else if(number==2){
      count[1]++;
    }else if(number==3){
      count[2]++;
    }else if(number==4){
      count[3]++;
    }else if(number==5){
      count[4]++;
    }else if(number==6){
      count[5]++;
    }
  }
  
  printf("1は%d回出ました\n", count[0]);
  printf("2は%d回出ました\n", count[1]);
  printf("3は%d回出ました\n", count[2]);
  printf("4は%d回出ました\n", count[3]);
  printf("5は%d回出ました\n", count[4]);
  printf("6は%d回出ました\n", count[5]);

  return 0;
}

int get_dice_number(void)
{

  int val;

  val = rand() % 6;

  val++;

  return val;
}

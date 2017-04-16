#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_dice_number(void);

int main(void)
{

  int number;

  srand((unsigned)time(NULL));

  number = get_dice_number();

  printf("%d\n", number);

  return 0;
}

int get_dice_number(void)
{

  int val;

  val = rand() % 6;

  val++;

  return val;
}

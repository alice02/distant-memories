#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void set_position(int *x, int *y);

int main(void)
{
  srand((unsigned)time(NULL));

  int player_x, player_y;

  set_position(&player_x ,&player_y);

  printf("player_position:(%d,%d)\n", player_x+1, player_y+1);

  return 0;
}

void set_position(int *x, int *y)
{
  *x = rand()%8;
  *y = rand()%8;
}

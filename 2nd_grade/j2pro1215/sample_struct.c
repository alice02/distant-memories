#include <stdio.h>

struct point {
  int x;
  int y;
};

int main(void)
{
  struct point player;
  
  player.x = 2;
  player.y = 3;

  printf("player(%d,%d)\n", player.x, player.y);

  return 0;
}

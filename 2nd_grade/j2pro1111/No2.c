#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void set_player_parameter(int *hp, int *mp);

int main(void)
{
  srand((unsigned)time(NULL));

  int hp;
  int mp;
  
  set_player_parameter(&hp, &mp);
    
  printf("hp=%d\n", hp);
  printf("mp=%d\n", mp);
    
  return 0;
}

void set_player_parameter(int *hp, int *mp)
{
  *hp = rand()%50 + 51;
  *mp = rand()%50 + 51;
}

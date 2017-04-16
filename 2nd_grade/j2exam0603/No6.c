#include <stdio.h>

void cto2(unsigned char);

int main(void)
{

  int bit, base, S=0;

  while(S<255){

  printf("bit = ");
  scanf("%d", &bit);

  base = 1;
  base <<= bit;

  S |= base;

  cto2(S);

  }
  return 0;
}


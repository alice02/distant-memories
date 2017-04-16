#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 8

int main(void)
{

  int i;
  char pass[NUMBER+1];
  char table[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  srand((unsigned)time(NULL));

  for (i=0; i<NUMBER; i++) {
    pass[i] = table[rand()%64];
  }

  pass[NUMBER] = '\0';

  printf("%s\n", pass);

  return 0;
}

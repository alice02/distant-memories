#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 8

int main(void)
{

  int select, i;
  char pass[NUMBER+1];

  srand((unsigned)time(NULL));

  for (i=0; i<NUMBER; i++) {
    select = rand() % 3;
    if (select == 0) {
      pass[i] = rand() % 10 + '0';
    }else if (select == 1) {
      pass[i] = rand() % 26 + 'a';
    }else{
      pass[i] = rand() % 26 + 'A';
    }
  }

  pass[8] = '\0';

  printf("%s\n", pass);

  return 0;
}

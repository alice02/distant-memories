#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 50000

int main(void)
{
  srand((unsigned)time(NULL));

  char ch[NUMBER];
  int i, ct, val;

  ct = 0;

  for (i=0; i<NUMBER; i++) {
    val = rand()%26;
    ch[i] = val + 'a';
    printf("%c", ch[i]);
    if (ch[i-2]=='a' && ch[i-1]=='b' && ch[i]=='c') {
      ct++;
    }
  }

  printf("\nct = %d\n", ct);

  return 0;
}

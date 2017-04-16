#include <stdio.h>
#include <stdlib.h>

#define NUM 20

int main(void)
{
  char str[NUM+1], dummy;
  int i, j;

  printf("str = ");
  scanf("%s%c", str, &dummy);

  for (i=0; str[i]!='\0'; i+=2) {
    for (j=0; j<atoi(&str[i+1]); j++) {
      printf("%c", str[i]);
    }
  }

  printf("\n");

  return 0;
}

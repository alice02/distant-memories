#include <stdio.h>

int main(void)
{
  int i, j;
  char array[]= "You can't gain anything without effort.";
  int ct = 0;

  printf("%s\n", array);

  for (i=0; array[i]!='\0'; i++) {
    if (array[i]!=' ' || array[i]=='.') {
      ct++;
    }

    if (array[i]==' ' || array[i]=='.') {
      printf("%d  ", ct);
      ct = 0;
    }
  }

  printf("\n");

  return 0;
}




#include <stdio.h>

#define SIZE 5

int main(void)
{
  char ch;
  char array[SIZE+1];
  int i;

  printf("EOF=%d\n", EOF);

  i = 0;
  while (i<SIZE) {
    ch = getchar();
    if (ch==EOF) {
      break;
    }

    if(ch!='\n') {
      array[i] = ch;
      i++;
    }

  }
  array[i] = '\0';

  for (i=0; i<SIZE; i++) {
    printf("%c", array[i]);
  }
  printf("\n");

  printf("%s\n", array);

  return 0;
}

#include <stdio.h>

#define SIZE 5

int main(void)
{
  char ch, dummy;
  char array[SIZE+1];
  int i;

  for (i=0; i<SIZE; i++) {
    printf("ch[%d]=", i);
    scanf("%c%c", &ch, &dummy);
    array[i] = ch;
  }
  array[i] = '\0';

  for (i=0; i<SIZE; i++) {
    printf("array[%d]=%c\n", i, array[i]);
  }

  printf("[");
  for (i=0; i<SIZE; i++) {
    printf("%c", array[i]);
  }
  printf("]\n");

  printf("[%s]\n", array);

  return 0;
}

#include <stdio.h>

#define SIZE 5

int main(void)
{
  char ch[SIZE+1] ,dummy;
  int i;

  for (i=0; i<SIZE; i++) {
    printf("ch[%d]=", i);
    scanf("%c%c", &ch[i], &dummy);
  }

  ch[i] = '\0';

  for (i=SIZE-1; i>=0; i--) {
    printf("%c", ch[i]);
  }

  printf("\n");

  return 0;
}

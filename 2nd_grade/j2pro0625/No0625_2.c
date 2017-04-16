#include <stdio.h>

#define SIZE 4

int main(void)
{
  char ch[SIZE+1] ,dummy;
  int i, val=0 ,t;

  for (i=0; i<SIZE; i++) {
    printf("ch[%d]=", i);
    scanf("%c%c", &ch[i], &dummy);

  }

  ch[i] = '\0';

  val = atoi(ch);

  printf("%d\n", val);

  return 0;
}

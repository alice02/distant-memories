#include <stdio.h>

int main(void)
{

  char ch, dummy;

  do {
    printf("input char = ");
    scanf("%c%c", &ch, &dummy);
  } while(ch<'a' || ch>'z');

  printf("%c\n", ch);

  return 0;
}




























#include <stdio.h>

int main(void)
{

  char ch, dummy;

  printf("input char = ");
  scanf("%c%c", &ch, &dummy);

  ch -= '0';

  printf("%d\n", ch);

  return 0;
}

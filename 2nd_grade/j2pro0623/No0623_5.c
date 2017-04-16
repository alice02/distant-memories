#include <stdio.h>

int main(void)
{

  char ch, dummy;
  int m;

  printf("input char = ");
  scanf("%c%c", &ch, &dummy);
  printf("m = ");
  scanf("%d", &m);

  ch += m;

  printf("%c\n", ch);

  return 0;
}

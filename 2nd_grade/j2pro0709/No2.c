#include <stdio.h>

int main(void)
{
  char ch, dummy;

  do {
  printf("input char[A-Z] = ");
  scanf("%c%c", &ch, &dummy);
  } while (ch<'A' | 'Z'<ch);

  printf("You input character is [%c].\n", ch);

  return 0;
}

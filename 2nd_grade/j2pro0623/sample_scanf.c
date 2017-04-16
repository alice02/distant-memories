#include <stdio.h>

int main(void)
{
  char ch;
  char dummy;

  printf("input char = ");
  scanf("%c%c", &ch, &dummy);
  printf("ch    : %%d=%d, %%c=%c, %%x=%x\n", ch, ch, ch);
  printf("dummy : %%d=%d, %%c=%c, %%x=%x\n", dummy, dummy, dummy);

  return 0;
}

#include <stdio.h>

int main(void)
{
  char str[] = "morimorikuesuto";
  int i, ct=0;

  for (i=0; str[i]!='\0'; i++){
    ct++;
  }

  printf("%d文字です\n", ct);

  return 0;
}

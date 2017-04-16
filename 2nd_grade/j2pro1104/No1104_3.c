#include <stdio.h>

int my_strlen(char *str);

int main(void)
{
  char ch[] = "oeda2";

  printf("%s\n", ch);

  printf("%d\n", my_strlen(ch));

  return 0;
}

int my_strlen(char *str)
{
  int ct = 0;

  while (*(str+ct)!='\0') {
    ct++;
  }

  return ct;
}

#include <stdio.h>

int my_strlen(char str[], char ch);

int main(void)
{
  char str[] = "You can't gain anything without effort.";
  char str_2[my_strlen(str, '\0')];
  int i, len;

  len = my_strlen(str, '\0');

  for (i=len-1; 0<=i; i--) {
    str_2[len-i] = str[i];
  }

  for (i=0; i<=len; i++) {
    printf("%c", str_2[i]);
  }

  printf("\n");

  return 0;
}

int my_strlen(char str[], char ch)
{
  int ct=0;
  char a = {ch};

  while (str[ct]!=a) {
    ct++;
  }

  return ct;
}

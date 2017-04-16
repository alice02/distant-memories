#include <stdio.h>

char my_toupper(char ch);

int main(void)
{

  char s_ch, b_ch, dummy;

  printf("input char = ");
  scanf("%c%c", &s_ch, &dummy);

  b_ch =  my_toupper(s_ch);

  printf("%c\n", b_ch);

  return 0;
}


char my_toupper(char ch)
{

  if(ch>='a' && ch<='z'){ 
    ch -= 'a'-'A';
  }

  return ch;
}

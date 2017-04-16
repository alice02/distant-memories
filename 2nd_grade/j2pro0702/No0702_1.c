#include <stdio.h>

int main(void)
{
  char ciphertxt[] = "uboptijjobb";

  int i;

  for (i=0; ciphertxt[i]!='\0'; i++) {
      printf("%c", ciphertxt[i]-1);
  }
  
  printf("\n");

  return 0;
}

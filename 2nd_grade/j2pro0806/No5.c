#include <stdio.h>

int main(void)
{
  char str[] = "You can't gain anything without effort.";
  int i, j;

  for (i=0; str[i]!='\0'; i++) {
    if (str[i+1]==' ' || str[i]=='.') {
      for (j=i; str[j]!=' '; j--) {
	if (j==0) {
	  printf("%c", str[j]);
	  break;
	}
	else {
	  printf("%c", str[j]);
	}
      }
      printf(" ");
    }
  }

  printf("\n");

  return 0;
}

#include <stdio.h>

int main(void)
{
  char str[] = "You can't gain anything without effort.";
  int i, ct;

  printf("%s\n", str);

  ct = 0;
  for (i=0; str[i]!='\0'; i++) {
    if (str[i]!=' ' || str[i]=='.') {
      ct++;
      if (str[i]=='.') {
	printf("%d ", ct);
      }
    }
    else if (str[i]==' '){
      printf("%d ", ct);
      ct = 0;
    }
  }

  printf("\n");

  return 0;
}

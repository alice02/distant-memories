#include <stdio.h>

void disp_str(char *str);

int main(void)
{
  char *pt = "edamameedamameedamame";

  printf("%s\n", pt);

  disp_str(pt);

  return 0;
}

void disp_str(char *str)
{
  int i;

  for (i=0; *(str+i)!='\0'; i++) {
    if (*(str+i)=='m' && *(str+(i+1))=='a' && *(str+(i+2))=='m' && *(str+(i+3))=='e'){
      i += 3;
    }
    else {
      printf("%c", *(str+i));
    }
  }
  printf("\n");
}


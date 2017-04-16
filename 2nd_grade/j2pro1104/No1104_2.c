#include <stdio.h>

void disp_str(char *pt);

int main(void)
{
  char *pt = "edamameedamameedamame";

  disp_str(pt);

  return 0;
}

void disp_str(char *pt)
{

  printf("%s\n", pt);

}

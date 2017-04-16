#include <stdio.h>

void sukina_tabemono(void)
{
  printf("ichigo\n");
  printf("budou-pan\n");
  printf("niku\n");
  printf("\n");
}

int main(void)
{
  int i;

  i=0;
  while(i<3){
    sukina_tabemono();
    i++;
  }

  return 0;
}

#include <stdio.h>

void cto2(int);

int main(void)
{

  int  a = 0;

  while(a<=255){

    printf("%d ",a);
    printf("%X ",a);
    cto2(a);

    a++;
  }

  return 0;
}

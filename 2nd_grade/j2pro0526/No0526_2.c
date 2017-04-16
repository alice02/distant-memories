#include <stdio.h>

int main(void)
{

  int a;
  int S = 0;

  for (a=1; a<=100; a++) {
    if(a%3==0){
      S = S + a;
    }
  }

  printf("%d",S);

  return 0;
}

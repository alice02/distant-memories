#include <stdio.h>

void A(void)
{
  int a,b;

  a=1;
  while(a<=3){
    b=1;
    while(b<=a){
      printf("*");
      b++;
    }
    printf("\n");
    a++;
  }

}

int main(void)
{

  int i=0;

  while(i<3){
    A();
    i++;
  }

  return 0;
}

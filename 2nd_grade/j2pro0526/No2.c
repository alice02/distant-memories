#include <stdio.h>

void dispNumber(int x);

int main(void)
{
  int number;

  printf("number = ");
  scanf("%d", &number);

  dispNumber(number);

  return 0;
}

void dispNumber(int x)
{
  int a[20];
  int b=0,c;

  while(b<20){
    c = 0;
    while(c<x){
      if(b<20){
      a[b] = c;
      printf("%2d",a[b]);
      b++;
      c++;
      }else{
	break;
      }
    }
      printf("\n");
  }
}

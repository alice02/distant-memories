#include <stdio.h>

int main(void)
{

  int a;

  for(a=0; a<100; a++){
    if(a%5==0 && a!=0){
      printf("%d ",a);
    }
  }

  printf("\n");

  return 0;
}

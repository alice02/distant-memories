#include <stdio.h>

int main(void)
{

  int n,x;

  printf("number = ");
  scanf("%d",&n);

  for(x=0; 0<n; x++){
    printf("%d",n%10);
    n = n/10;
  }

  printf("\n");

  return 0;
}

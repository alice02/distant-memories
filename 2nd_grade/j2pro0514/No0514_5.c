#include <stdio.h>

void shuturyoku(int a);

int main(void)
{

  int n,i;

  printf("n=");
  scanf("%d",&n);

  for(i=0; i<n; i++){

  shuturyoku(n);

  }

  printf("\n");

  return 0;
}

void shuturyoku(int a)
{

  int i;

  for(i=0; i<a; i++){
    printf("%d",i%a);
  }

}

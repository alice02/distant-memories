#include <stdio.h>

int main(void)
{
  int i, j;
  int n;
  
  do {
    printf("n=");
    scanf("%d", &n);
  } while(n<0);

  i = 0;
  while(i<=n) {
    j = 0;
    while(j<n-i) {
      printf("*");
      j++;
    }
    printf("\n");
    i++;
  }

  return 0;
}

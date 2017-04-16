#include<stdio.h>
main(void)
{
  int A[10];
  int n;

  n=0;

  while(n<10){
    A[n]=n;
    n=n+1;
  }

  n=0;

  while(n<10){
    printf("%d\n",A[n]);
    n=n+1;
  }
}

#include<stdio.h>
main(void)
{
  int a[10];
  int b[10];
  int n;

  n=0;

  while(n<10){
    a[n]=n;
    b[n]=a[n];
    n=n+1;
  }

  n=0;

  while(n<10){
    printf("a[n]=%d b[n]=%d\n",a[n],b[n]);
    n=n+1;
  }
}

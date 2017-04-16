#include<stdio.h>
main(void)
{
  int a[10];
  int n;
  int c;

  n=0;

  while(n<10){
    printf("a[%d]の値を入力してください→:",n);
    scanf("%d",&a[n]);
    n=n+1;
  }

  n=0;
  c=0;

  while(c<10){
    a[9-c]=a[n];
    c=c+1;
    n=n+1;
  }

  c=0;

  while(c<10){
    printf("入れ換えた値のa[%d]=%d\n",9-c,a[9-c]);
    c=c+1;
  }
}

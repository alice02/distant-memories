#include<stdio.h>
main(void)
{

  int a[10];
  int b=0,c=1;

  while(b<10){
    a[b]=c;
    printf("array[%d]=%d\n",b,a[b]);
    c=c+2;
    b=b+1;
  }

}

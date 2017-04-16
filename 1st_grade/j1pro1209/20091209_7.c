#include<stdio.h>
main(void)
{
  int a[10];
  int b[10];
  int c;

  c=0;
  while(c<10){
    a[c]=c;
    c++;
  }

  c=0;
  while(c<10){
    b[c]=a[9-c];
    c++;
  }

  c=0;
  while(c<10){
    printf("a[%d]=%d b[%d]=%d\n",c,a[c],c,b[c]);
    c++;
  }
}




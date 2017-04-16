#include <stdio.h>

int main(void)

{

  int a[5],b;

  b = 0;
  while(b<5){
    a[b]=b;
    printf("a[%d]=%d\n",b,a[b]);
    b++;
  }

  return 0;

}

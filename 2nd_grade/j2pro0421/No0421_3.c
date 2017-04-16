#include <stdio.h>

int main(void)

{

  int a[3][5],b,c;

  b=0;
  while(b<3){
    c=0;
    while(c<5){
      a[b][c]=7;
      printf("a[%d][%d]=%d\n",b,c,a[b][c]);
      c++;
    }
    b++;
  }

  return 0;

}

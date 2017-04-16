#include<stdio.h>
main(void)
{

  int a[4][10];
  int x = 0;
  int y = 0;

  while(y<4){
    while(x<10){
      a[y][x]=(x*y);
      printf("a[%d][%d]=%d\n",y,x,a[y][x]);
      x++;
    }
    x=0;
    y++;
  }
}

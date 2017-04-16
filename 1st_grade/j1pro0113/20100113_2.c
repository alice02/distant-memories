#include<stdio.h>
main(void)
{

  int a[3][10];
  int x = 0;
  int y = 0;

  while(y<3){
    while(x<10){
      a[y][x]=0;
      printf("a[%d][%d]=%d\n",y,x,a[y][x]);
      x++;
    }
    x=0;
    y++;
  }
}

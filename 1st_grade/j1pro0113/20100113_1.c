#include<stdio.h>
main(void)
{

  int a[3][10];
  int x=0;
  int y=0;

  while(y<3){
    while(x<10){
      a[y][x]=0;
      x++;
    }
    y++;
  }
}

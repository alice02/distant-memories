#include<stdio.h>
main(void)
{

  int a[3][10][5];
  int x = 0;
  int y = 0;
  int z = 0;

  while(z<5){
    while(y<3){
      while(x<10){
	a[y][x][z]=0;
	printf("a[%d][%d][%d]=%d\n",y,x,z,a[y][x][z]);
	x++;
      }
      x=0;
      y++;
    }
    y=0;
    z++;
  }

}

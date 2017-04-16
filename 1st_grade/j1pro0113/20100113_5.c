#include<stdio.h>
main(void)
{

  int a[5][5]={ {1,0,0,0,1},{0,1,0,1,0},{0,0,1,0,0,},{0,1,0,1,0},{1,0,0,0,1} };
  int x = 0;
  int y = 0;


  while(y<5){
    while(x<5){
      if(a[x][y]==1){
	printf("*");
      }else{
	printf(" ");
      }
      x++;
    }
    printf("\n");
    x=0;
    y++;
  }
}

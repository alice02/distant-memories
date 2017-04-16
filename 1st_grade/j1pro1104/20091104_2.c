#include <stdio.h>
#include "graph.h"

main(void)
{
  double x;
  int y;
  int a;
  int b;
  int c;
  int z;
  initGraph( );

  printf("a:");
  scanf("%d",&a);
  printf("b:");
  scanf("%d",&b);
  printf("c:");
  scanf("%d",&c);

  x=-1000;
  y=1;
  z=0;

  drawLine(0,240,640,240,BLACK);
  drawLine(320,0,320,480,BLACK);


    while(x<=1000){
      z=a*x*x+b*x+c;
      fillCircle(320+(x*2),240-z,1,BLUE);
      x=x+0.01;
      y=y+1;
    }

  waitButtonPress( );
  closeGraph( );
}


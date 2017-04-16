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


  x=-1000;
  y=1;
  z=0;

  while(x<=640){
    while(y<=480){
      drawLine(0,240,640,240,BLACK);
      y=y+40;
    }
  drawLine(320,0,320,480,BLACK);
  x=x+40;
  }


    while(x<=1000){
      z=a*x*x+b*x+c;
      fillCircle(320+(x*2),240-z,1,BLUE);
      x=x+0.01;
      y=y+1;
    }

  waitButtonPress( );
  closeGraph( );
}


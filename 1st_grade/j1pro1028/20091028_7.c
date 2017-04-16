#include <stdio.h>
#include "graph.h"

main(void)
{
  int x;
  int y;
  initGraph( );

  x=20;
  y=20;

  while(y<=480){
    while(x<=640){
      drawCircle(x,y,20,RED);
      x=x+40;
    }
    y=y+40;
    x=20;
  }

  waitButtonPress( );
  closeGraph( );
}


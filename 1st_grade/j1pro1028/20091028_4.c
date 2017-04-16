#include <stdio.h>
#include "graph.h"

main(void)
{

  int r;
  initGraph( );

  r=10;

  while(r<=100){
  drawCircle(320,240,r,BLUE);
  r=r+10;
  }

  waitButtonPress( );
  closeGraph( );
}


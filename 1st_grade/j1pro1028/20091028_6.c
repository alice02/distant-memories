#include <stdio.h>
#include "graph.h"

main(void)
{

  int i;
  int s;
  initGraph( );

  i=1;
  s=0;

  while(i<=30){

  s=s+i;
  i=i+1;

  setLineWidth(4);
  drawLine(0,0+4*i,0+s,0+4*i,RED);

  }

  waitButtonPress( );
  closeGraph( );

}


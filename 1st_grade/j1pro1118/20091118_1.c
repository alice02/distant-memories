#include <stdio.h>
#include "graph.h"

main(void)
{

  int a;
  initGraph( );

  a=40;

  fillCircle(320,240,10,BLACK);
  while(a<=200){
    setLineWidth(20);
    drawCircle(320,240,a,BLACK);
    a=a+40;
  }

  waitButtonPress( );
  closeGraph( );
}


#include <stdio.h>
#include "graph.h"

main(void)
{
  int x;
  int y;
  int l;
  initGraph( );

  x=0;
  y=0;
  l=1;

  while(y<=480){
    while(x<=640){
      if(l%2==1){
      fillRectangle(0+x,0+y,40+x,40+y,BLACK);
      }else{
      fillRectangle(40+x,y,80+x,40+y,BLACK);
      }
      x=x+80;
    }
    l=l+1;
    y=y+40;
    x=0;
  }
  waitButtonPress( );
  closeGraph( );
}


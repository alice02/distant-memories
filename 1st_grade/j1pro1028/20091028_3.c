#include <stdio.h>
#include "graph.h"

main(void)
{
  int x;
  int y;
  int r;
  initGraph( );

  printf("中心座標(x,y)のxは?:");
  scanf("%d",&x);
  printf("中心座標(x,y)のyは?");
  scanf("%d",&y);  
  printf("半径は?");
  scanf("%d",&r);

  drawCircle(x-r,y,r,BLUE);
  drawCircle(x+r,y,r,RED);

  waitButtonPress( );
  closeGraph( );
}


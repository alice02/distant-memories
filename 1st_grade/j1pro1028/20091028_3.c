#include <stdio.h>
#include "graph.h"

main(void)
{
  int x;
  int y;
  int r;
  initGraph( );

  printf("�濴��ɸ(x,y)��x��?:");
  scanf("%d",&x);
  printf("�濴��ɸ(x,y)��y��?");
  scanf("%d",&y);  
  printf("Ⱦ�¤�?");
  scanf("%d",&r);

  drawCircle(x-r,y,r,BLUE);
  drawCircle(x+r,y,r,RED);

  waitButtonPress( );
  closeGraph( );
}


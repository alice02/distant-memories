#include <stdio.h>
#include "graph.h"

main(void)
{
  int a;
  initGraph( );

  printf("a¢ª");
  scanf("%d",&a);
  if(a%2==0){
    drawCircle(320,200,100,BLUE);
  }else{
    fillCircle(320,200,100,BLUE);
  }
  waitButtonPress( );
  closeGraph( );
}


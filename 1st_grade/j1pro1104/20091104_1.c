#include <stdio.h>
#include "graph.h"

main(void)
{
  int x;
  int y;
  int l;
  int a;
  initGraph( );

  printf("大きさは?:");
  scanf("%d",&a);
  x=0;
  y=0;
  l=1;

  while(y<=480){
    while(x<=640){
      if(l%2==1){
      fillRectangle(0+x,0+y,a+x,a+y,BLACK);
      }else{
      fillRectangle(a+x,y,2*a+x,a+y,BLACK);
      }
      x=x+2*a;
    }
    l=l+1;
    y=y+a;
    x=0;
  }
  waitButtonPress( );
  closeGraph( );
}


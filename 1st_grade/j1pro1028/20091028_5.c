#include <stdio.h>
#include "graph.h"

main(void)
{

  int i;
  initGraph( );

  i=1;

  while(i<=9){
    if(i==1||i==4||i==7){
      drawCircle(60*i+20,240,30,BLUE);
    }else if(i==2||i==5||i==8){
      drawCircle(60*i+20,240,30,RED);
    }else if(i==3||i==6||i==9){
      drawCircle(60*i+20,240,30,GREEN);
    }
  i=i+1;
  }

  waitButtonPress( );
  closeGraph( );
}


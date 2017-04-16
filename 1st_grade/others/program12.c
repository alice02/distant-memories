#include<stdio.h>
main(void)
{
  int a;

  a=1954;

  if(a<1930){
    printf("まだ始まってない!\n");
  }else if(a%4!=2){
    printf("開催年ではない!\n");
  }else if(a<=1938){
    printf("第%d回開催年!\n",(a-1930)/4+1);
  }else if(a<1950){
    printf("中断中!\n");
  }else{
    printf("第%d回開催年\n",(a-1950)/4+4);
  }
}

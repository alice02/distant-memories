#include<stdio.h>
main(void)
{

  int x;
  int y;
  int yoko;
  int tate;

  printf("$B2#$NBg$-$5$O(B?:");
  scanf("%d",&x);
  printf("$B=D$NBg$-$5$O(B?:");
  scanf("%d",&y);

  tate=1;

  while(tate<=y){
    yoko=1;
    while(yoko<=x){
      printf("*");
      yoko=yoko+1;
    }
    printf("\n");
    tate=tate+1;
  }
}

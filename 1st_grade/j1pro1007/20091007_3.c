#include<stdio.h>
main(void)
{

  int x;
  int y;
  int yoko;
  int tate;

  printf("横の大きさは?:");
  scanf("%d",&x);
  printf("縦の大きさは?:");
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

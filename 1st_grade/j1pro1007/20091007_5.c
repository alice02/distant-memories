#include<stdio.h>
main(void)
{
  int yoko;
  int tate;
  int x;
  tate=1;


  while(tate<=9){
    yoko=1;
    while(yoko<=9){
      printf("%3d",tate*yoko);
      yoko=yoko+1;
    }
    printf("\n");
    tate=tate+1;
  }
}

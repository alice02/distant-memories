*****(4)*****
#include<stdio.h>
main(void)
{

  int x;
  int yoko;
  int tate;

  printf("大きさはどのくらいにする?(「何×何にしますか?」ってことね):");
  scanf("%d",&x);

  tate=1;

  while(tate<=x){
    yoko=1;
    while(yoko<=x-(x-tate)){
      printf("*");
      yoko=yoko+1;
    }
    printf("\n");
    tate=tate+1;
  }
}

*****(5)*****
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

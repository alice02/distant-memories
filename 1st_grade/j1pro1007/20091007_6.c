#include<stdio.h>
main(void)
{

  int x;
  int yoko;
  int tate;

  printf("大きさはどのくらいにする?(「何×何にしますか?」ってことね):");
  scanf("%d",&x);

  tate=1;

  if(x<=0){
    printf("1以上の値を入力してくださいよ...\n");
      }else{
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
}

#include<stdio.h>
main(void)
{

  int x;
  int y;
  int yoko;
  int tate;

  printf("�����礭����?:");
  scanf("%d",&x);
  printf("�Ĥ��礭����?:");
  scanf("%d",&y);

  tate=1;

  while(tate<=y){
    yoko=1;
    while(yoko<=x){
      if(tate==yoko){
	printf("+");
      }else{
      printf("*");
      }
      yoko=yoko+1;
    }
    printf("\n");
    tate=tate+1;
  }
}

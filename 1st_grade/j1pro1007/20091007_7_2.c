#include<stdio.h>
main(void)
{

  int x;
  int yoko;
  int tate;

  printf("�礭���ϤɤΤ��餤�ˤ���?(�ֲ��߲��ˤ��ޤ���?�פäƤ��Ȥ�):");
  scanf("%d",&x);

  tate=1;

  while(tate<=x){
    yoko=1;
    while(yoko<=x-(x-tate)){
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

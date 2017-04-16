#include<stdio.h>
main(void)
{
  int a[8];
  int x,max,min,maxtime,mintime;

  x=0;

  while(x<8){
    printf("%d時の来店者数を入力してください:",x);
    scanf("%d",&a[x]);
      if(x==0){
        max=a[x];
	min=a[x];
	maxtime=x;
	mintime=x;
      }else if(a[x]>max){
	max=a[x];
	maxtime=x;
      }else if(a[x]<min){
	min=a[x];
	mintime=x;
      }
   x++;
  }

  printf("最小:%d時 %d人\n",mintime,min);
  printf("最大:%d時 %d人\n",maxtime,max);

}

#include <stdio.h>

int hanbetu(int x,int y,int z)
{
  int min;
 
  if(x<z&&x<y){
    min = x;
  }else
  if(y<x&&y<z){
    min = y;
  }else
  if(z<x&&z<y){
    min = z;
  }else
    min = x;

  return min;

}

int main(void)
{
  int a,b,c,min;

  printf("a:");
  scanf("%d",&a);
  printf("b:");
  scanf("%d",&b);
  printf("c:");
  scanf("%d",&c);

  min = hanbetu(a,b,c);

  printf("min=%d\n",min);

  return 0;
}

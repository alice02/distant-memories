#include<stdio.h>

int ruijyo(int a,int b);

int main(void)
{
  int x,y,z;

  printf("数：");
  scanf("%d",&x);
  printf("何乗致しますか？：");
  scanf("%d",&y);

  z = ruijyo(x,y);

  printf("%d\n",z);

  return 0;
}

int ruijyo(int a,int b)
{

  int c,d;
  c = a;

  for (d=1; d<b; d++) {
    a = a * c;
  }

  return a;

}

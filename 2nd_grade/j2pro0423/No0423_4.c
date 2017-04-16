#include <stdio.h>
int sosu(int a){

  int b;

  if(a<2){
    return 0;
  }else if(a==2){
    return 1;
  }

  if(a%2==0){
    return 0;
  }

  b = 3;
  while(b * b <= a){
    if(a%b == 0){
      return 0;
    }
    b++;
  }
    return 1;
}

int main(void)
{
  int n,x;

  printf("数値を入力してください：");
  scanf("%d",&n);

  x = sosu(n);

  if(x==0){
    printf("素数ではありません\n");
  }else{
    printf("素数です\n");
  }

  return 0;
}

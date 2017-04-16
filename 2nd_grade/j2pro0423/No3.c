#include <stdio.h>

int main(void)

{

  int a,b,c;

  printf("点数：");
  scanf("%d",&a);

  if(a<=100 && a>=0){
    if(a>=80){
      printf("A\n");
    }else if(a>=70){
      printf("B\n");
    }else if(a>=60){
      printf("C\n");
    }else if(a<60){
      printf("D\n");
    }
  }else{
    printf("入力値が異常ですよ。\n");
  }
    
  return 0;

}

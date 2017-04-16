#include<stdio.h>
main(void)
{
  int a;
  int m;

  m=9;

  if(m>=8){
    a=m+1;
  }else{
    a=m;
  }
  if(a%2==1){
    printf("大の月!\n");
  }else{
    printf("小の月!\n");
  }
}


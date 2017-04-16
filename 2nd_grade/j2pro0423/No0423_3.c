#include <stdio.h>

int main(void)

{

  int m,n;

  printf("n=");
  scanf("%d",&n);

  m=n%7;

  printf("%d日後は",n);

  if(m==1){
    printf("土");
  }else if(m==2){
    printf("日");
  }else if(m==3){
    printf("月");
  }else if(m==4){
    printf("火");
  }else if(m==5){
    printf("水");
  }else if(m==6){
    printf("木");
  }else if(m==0){
    printf("金");
  }

  printf("曜日です\n");

  return 0;

}

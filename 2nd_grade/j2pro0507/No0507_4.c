#include <stdio.h>

void tenki_hantei(int kousui)
{
  if(kousui>=50){
    printf("雨\n");
  }
  else if(kousui>=20){
    printf("曇り\n");
  }
  else if(kousui<20){
    printf("晴れ\n");
  }
}

int main(void)
{
  int x;

  printf("降水確率を入力してください：");
  scanf("%d",&x);

  if(x>0 && x<100){
    tenki_hantei(x);
  }else{
    printf("放送事故です！\n");
  }

  return 0;
}  

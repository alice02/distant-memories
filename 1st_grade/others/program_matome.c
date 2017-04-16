**********(3)**********
#include<stdio.h>
main(void)
{
  int a;
  int n;

  a=1944;

  if(a<1896){
    printf("まだ始まってない!\n");
  }else if(a%4!=0){
    printf("開催年じゃない!\n");
  }else{
    n=(a-1896)/4+1;
    if(a==1916){
      printf("第%d回開催予定だったけど、不開催だった!\n",n);
    }else if(a==1940){
      printf("第%d回開催予定だったけど、不開催だった!\n",n);
    }else if(a==1944){
      printf("第%d回開催予定だったけど、不開催だった!\n",n);
    }else{
      printf("第%d回開催年\n",n);
    }
  }
}

**********(4)**********
#include<stdio.h>
main(void)
{
  int a;

  a=1954;

  if(a<1930){
    printf("まだ始まってない!\n");
  }else if(a%4!=2){
    printf("開催年ではない!\n");
  }else if(a<=1938){
    printf("第%d回開催年!\n",(a-1930)/4+1);
  }else if(a<1950){
    printf("中断中!\n");
  }else{
    printf("第%d回開催年\n",(a-1950)/4+4);
  }
}

**********(5)**********
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

**********(6)**********
#include<stdio.h>
main(void)
{
  int y;

  y=2000;

  if(y%400==0){
    printf("閏年です!\n");
  }else if(y%100==0){
    printf("閏年ではありません!\n");
  }else if(y%4==0){
    printf("閏年です!\n");
  }else{
    printf("閏年ではありません!\n");
  }
}

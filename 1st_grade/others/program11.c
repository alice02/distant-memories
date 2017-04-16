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

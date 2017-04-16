#include<stdio.h>
main(void)
{
  int A[8];
  int n;
  int m;

  n=0;
  m=0;

  while(n<8){
    printf("%d時台の来店者人数を入力してください!:",n);
    scanf("%d",&A[n]);
    n=n+1;
  }

  n=0;

  while(n<8){
    printf("%d時台の来店者数は%d人です!\n",n,A[n]);
    m=m+A[n];
    n=n+1;
  }
  printf("0から7時台の合計来店者数は%dです!\n",m);
}

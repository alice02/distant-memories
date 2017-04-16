#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ransu(int a,int b);

int main(void)
{

  int n,m,i=0;
  int val;

  srand((unsigned)time(NULL));

  printf("n=");
  scanf("%d",&n);
  printf("m=");
  scanf("%d",&m);

  //  while(i<20){
    val = ransu(n,m);
    printf("%d\n",val);
    //    i++;
    //  }

  return 0;
}

int ransu(int a,int b)
{
  int val;
  int i;

  while(i<b){
    val = rand()%b;
    if(val>=a){
      printf("%d\n",val);
      i++;
    }
  }

  return val;
}

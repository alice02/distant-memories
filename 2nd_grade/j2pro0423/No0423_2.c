#include <stdio.h>

int main(void)

{

  int a,b,n;

  printf("n=");
  scanf("%d",&n);

  a=0;
  while(a<n){
    b=1;
    while(b<=n){
      if(b==n-a){
	printf("*");
      }else{
	printf(" ");
      }
      b++;
    }
    printf("\n");
    a++;
  }


  return 0;

}

#include <stdio.h>

int main(void)

{

  int a,S;

  a=123;
  S=0;

  while(a<=456){
     S=S+a;
     a++;
   }

  printf("%d\n",S);

  return 0;

}

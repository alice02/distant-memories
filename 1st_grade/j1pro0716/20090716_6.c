#include<stdio.h>
main(void)
{
  int a;
  int s;

  s=0;
  a=0;

  while(s<=100){
    a=a+1; 
   s=s+a*a;
   }
  printf("1^2+2^2+...a^2$B$,(B100$B0J>e$K$J$k@0?t(Ba$B$N$J$+$G:G>.$N(Ba$B$NCM$O(B%d$B$G$9(B.\n",a);
}

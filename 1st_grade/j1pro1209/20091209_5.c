#include<stdio.h>
main(void)
{
  int A[8];
  int n;
  int m;

  n=0;
  m=0;

  while(n<8){
    printf("%d$B;~Bf$NMhE9<T?M?t$rF~NO$7$F$/$@$5$$(B!:",n);
    scanf("%d",&A[n]);
    n=n+1;
  }

  n=0;

  while(n<8){
    printf("%d$B;~Bf$NMhE9<T?t$O(B%d$B?M$G$9(B!\n",n,A[n]);
    m=m+A[n];
    n=n+1;
  }
  printf("0$B$+$i(B7$B;~Bf$N9g7WMhE9<T?t$O(B%d$B$G$9(B!\n",m);
}

#include <stdio.h>

int main(void)
{

  int a[6],i,j;

  for (i=0; i<6; i++){
    printf("a[%d]=",i);
    scanf("%d",&a[i]);
  }

  j=0;
  for (i=6; i>0; i--){
    printf("a[%d]=%d\n",j,i);
    j++;
  }

  return 0;
}

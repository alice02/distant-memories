#include<stdio.h>
main(void)
{

  int a,b,c;

  printf("�礭����");
  scanf("%d",&a);

  b=1;
  while(b<=a){
    c=1;
    while(c<=a-(a-b)){
      printf("*");
      c++;
    }
    printf("\n");
    b++;
  }

}

#include <stdio.h>

int main(void)

{

  int a[9][9],b,c,d;


  printf("    ");

  d=1;
  while(d<=9){
    printf("%3d",d);
    d++;
  }

  printf("\n");
  printf("   ----------------------------\n");


  b=1;
  while(b<=9){
    c=1;
    printf("%d กร",b);
    while(c<=9){
      printf("%3d",b*c);
      c++;
    }
    b++;
    printf("\n");
  }

  return 0;

}

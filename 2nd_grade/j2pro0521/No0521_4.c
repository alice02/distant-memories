#include <stdio.h>

int main(void)
{

  char a=1;
  unsigned char b=1;
  int c=1;
  


  printf("\n正側にオーバーフローさせます\n");

  while(c<=500){
      printf("char:%4d , unsigned char:%4d , int:%4d\n",a,b,c);
      a++;
      b++;
      c++;
  }

  a = 0;
  b = 0;
  c = 0;

  printf("負側にオーバーフローさせます\n");
  while(c>=-500){
    printf("char:%4d , unsigned char:%4d , int:%4d\n",a,b,c);
    a--;
    b--;
    c--;   
  }


  return 0;

}

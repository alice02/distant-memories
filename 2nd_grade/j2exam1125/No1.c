#include <stdio.h>

int func(int *x);

int main(void)
{
  int num;
  int array[5];
  int *pt;
  int i;

  pt = &num;
  *pt = 8;
  printf("%d\n", num);
  
  for (i=0; i<5; i++) {
    array[i] = i*10;
  }
  
  pt = array;
  printf("%d\n", *(pt+1));
  printf("%d\n", *pt+1);
  
  num = func(&array[2]);
  printf("%d\n", num);

  return 0;
}

int func(int *x)
{
  int y;
  
  y = *x+1;

  return y;
}

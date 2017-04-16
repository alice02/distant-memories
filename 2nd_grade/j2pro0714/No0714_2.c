#include <stdio.h>

int calc(int kyori);

int main(void)
{
  int kyori;

  printf("µ÷Î¥(km) = ");
  scanf("%d", &kyori);

  printf("%d²ó\n", calc(kyori));

  return 0;
}

int calc(int kyori)
{
  double i;
  int ct=0;

  i=0.000001; 

  while(i<=kyori){
    printf("%fkm\n", i);
    ct++;
    i*=2;
  }

  return ct;
}

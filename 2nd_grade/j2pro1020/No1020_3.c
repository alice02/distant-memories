#include <stdio.h>

int main(void)
{

  int a, b, c;
  char d, e, f;
  double g, h, i;

  printf("int:\n");
  printf("a : %p\n", &a);
  printf("b : %p\n", &b);
  printf("c : %p\n", &c);

  printf("char:\n");
  printf("d : %p\n", &d);
  printf("e : %p\n", &e);
  printf("f : %p\n", &f);


  printf("double:\n");
  printf("g : %p\n", &g);
  printf("h : %p\n", &h);
  printf("i : %p\n", &i);

  return 0;
}

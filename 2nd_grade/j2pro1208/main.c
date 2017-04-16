#include <stdio.h>

void func(int num);

int main(void)
{
  int n;

  printf("input number=");
  scanf("%d", &n);
  
  func(n);

  return 0;
}

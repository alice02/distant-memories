#include <stdio.h>

void nanabai(int number)
{
  int ans;

  ans = number *7;
  printf("ans = %d\n",ans);
}

int main(void)
{
  int x;

  printf("x = ");
  scanf("%d",&x);

  nanabai(x);

  return 0;
}

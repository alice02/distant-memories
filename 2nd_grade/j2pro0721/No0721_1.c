#include <stdio.h>

int rui(int num);

int main(void)
{
  char str[] = "00001010";
  int i, S=0;

  for (i=0; str[i]!='\0'; i++) {
    str[i] -= '0';
    if (str[i]==1){
      S += rui(7-i);
    }
  }
  
  printf("%d\n", S);

  return 0;
}

int rui(int num)
{
  int ans=1, i;

  for (i=0; i<num; i++) {
    ans *= 2;
  }

  return ans;
}

#include <stdio.h>

int rui(int num);

int main(void)
{
  char str[] = "00001101";
  int i, S=0;
  int ans[8];

  for (i=0; str[i]!='\0'; i++) {
    str[i] -= '0';
    if (str[i]==1) {
      if (i==7) {
	S += 1;
      }
      else {
	S += rui(7-i);
      }
    }
  }
  
  for (i=0; i<8; i++) {
    ans[i] = S%16;
    S /= 16;
  }

  for (i=8; i>0; i--) {
    if (ans[i-1]>=10){
      printf("%c", 'A'+ans[i-1]%10);
    }
    else {
      printf("%d",ans[i-1]);
    }
  }

  printf("\n");

  return 0;
}

int rui(int num)
{
  int ans=2, i;

  for (i=1; i<num; i++) {
    ans *= 2;
  }

  return ans;
}


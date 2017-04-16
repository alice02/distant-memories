#include <stdio.h>
#include <string.h>

#define BitSize 8

int main(void)
{

  int i, k=1 ,ans=0, bit=1, ans_2[BitSize];
  char dummy, num[8];

  printf("num(16) = ");
  scanf("%s%c", num, &dummy);

  for (i=strlen(num)-1; 0<=i; i--) {
    if(num[i]>='a' && num[i]<='f') {
      num[i] -= 'a'-'A';
    }

    if (num[i]>='A' && num[i]<='F') {
      ans += (num[i]-'A'+10)*k;
    }
    else if(num[i]>='0' && num[i]<='9'){
      ans += (num[i]-'0')*k;
    }
    else {
      printf("input error!!\n");
      return 1;
    }
    k *= 16;
  }

  for (i=0; i<BitSize; i++){
    if (ans&bit) {
      ans_2[i] = 1;
    }
    else {
      ans_2[i] = 0;
    }
    bit <<= 1;
  }

  for (i=BitSize; i>0; i--) {
    printf("%d", ans_2[i-1]);
  }

  printf("\n");

  return 0;
}

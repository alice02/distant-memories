#include <stdio.h>
#include <string.h>

int main(void)
{
  int i, k=1 ,ans=0;
  char dummy, num[8];

  printf("num(16) = ");
  scanf("%s%c", num, &dummy);

  for (i=strlen(num)-1; i>=0; i--) {
    if ('A'<=num[i]) {
      ans += (num[i]-'A'+10)*k;
    }
    else {
      ans += (num[i]-'0')*k;
    }
    k *= 16;
  }

  printf("%d\n", ans);

  return 0;
}


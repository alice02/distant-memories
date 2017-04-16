#include <stdio.h>

#define NUMBER 5

int main(void)
{
  char ch[NUMBER];
  int i, flag, dummy;

  for (i=0; i<NUMBER; i++) {
    flag = 1;
    do {
      printf("ch[%d] = ", i);
      scanf("%c%c", &ch[i], &dummy);
      if ('A'<=ch[i] && ch[i]<='Z') {
	flag = 0;
      }
    } while(flag == 1);
  }

  for (i=0; i<NUMBER; i++) {
    printf("%c", ch[i]-'A'+'a');
  }

  printf("\n");

  return 0;
}

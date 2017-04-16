#include<stdio.h>

int main(void)
{
  char ch[3], dummy;
  int i, flag;

  for (i=0; i<3; i++) {
    flag = 1;
    do {
      printf("ch[%d] = ", i);
      scanf("%c%c", &ch[i], &dummy);

      if (ch[i]>='a' && ch[i]<='z') {
	flag = 0;
      }
      else if (ch[i]>='0' && ch[i]<='9') {
	flag = 0;
      }
      else if (ch[i]>='A' && ch[i]<='Z'){
	flag = 0;
      }
    } while(flag==1);
  }

  for (i=2; 0<=i; i--) {
    if (ch[i]>='a' && ch[i]<='z') {
      ch[i] = ch[i] - 'a' + 'A';
    }
    printf("%c", ch[i]);
  }
  printf("\n");

  return 0;
}

#include <stdio.h>

int main(void)
{

  int num;

  printf("num = ");
  scanf("%d", &num);

  num %= 26;

  if(num<0){
    num += 'z' + 1;
  }else{
    num += 'a';
  }

  printf("%c\n", num);

  return 0;
}


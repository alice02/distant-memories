#include <stdio.h>

void cto2(unsigned char);
void scto2(char);

int main(void)
{
  int number;

  do {
  printf("number = ");
  scanf("%d", &number);
  } while (number<-128 || 127<number);

  scto2(number);

  return 0;
}

void scto2(char number)
{
  cto2(number);
}

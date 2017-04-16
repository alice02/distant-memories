#include <stdio.h>
#include <string.h>

void disp_str(const char str[]);
void cut_space(char str[]);

int main(void)
{
  char str[] = "Have Fan with Programming!";

  disp_str(str);
  
  cut_space(str);
  
  disp_str(str);

  return 0;
}

void disp_str(const char str[])
{
  int i;

  printf("[");
  for (i=0; str[i]!='\0'; i++) {
    printf("%c", str[i]);
  }
  printf("]\n");

}

void cut_space(char str[])
{
  int i, ct=0;

  for (i=0; str[i]!='\0'; i++) {
    if (str[i+ct]==' ') {
      ct++;
    }
    str[i] = str[i+ct];
    if (str[i+ct]=='\0') {
      break;
    }
  }
}

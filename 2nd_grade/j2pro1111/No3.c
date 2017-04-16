#include <stdio.h>

#define SIZE 20

int my_strcmp(const char *s1, const char *s2);

int main(void)
{
  char s1[SIZE];
  char s2[SIZE];
  
  printf("s1 = ");
  scanf("%s", &s1);
  printf("s2 = ");
  scanf("%s", &s2);

  if (my_strcmp(s1, s2) == 0) {
    printf("等しいです。\n");
  }
  else {
    printf("等しくないです。\n");
  }

  return 0;
}

int my_strcmp(const char *s1, const char *s2)
{
  int i;

  for (i=0; *(s1+i)!='\0'||*(s2+i)!='\0'; i++) {
    if (*(s1+i)!=*(s2+i)) {
      return 1;
    }
  }
  return 0;
}

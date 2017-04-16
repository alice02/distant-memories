#include <stdio.h>

int my_strlen(const char str[]);
void disp_str(const char str[]);
void disp_reverse_str(const char str[]);
void my_strcpy(char s1[], const char s2[]);

/*
 *   文字列の長さを返す（'\0'は文字数に含まない）
 */
int my_strlen(const char str[])
{
  int i;

  i = 0;
  while(str[i]!='\0') {
    i++;
  }

  return i;
}

/*
 *   受け取った文字列を標準出力
 */
void disp_str(const char str[])
{
  int i;

  for (i=0; str[i]!='\0'; i++) {
    printf("%c", str[i]);
  }
  printf("\n");

}

/*
 *   受け取った文字列を逆順にして標準出力
 */
void disp_reverse_str(const char str[])
{
  int i;
  int num;

  num = my_strlen(str);
  printf("num=%d\n", num);

  for (i=num-1; 0<=i; i--) {
    printf("%c", str[i]);
  }
  printf("\n");

}

/*
 *   受け取った文字列を逆順にして標準出力
 */
void my_strcpy(char s1[], const char s2[])
{
  int i;

  for (i=0; s2[i]!='\0'; i++) {
    s1[i] = s2[i];
  }
  s1[i] = '\0';

}

/*
 *   メイン関数
 */
int main(void)
{
  char keyword[] = "Kisarazu";
  char new_str[100];

  printf("%s\n", keyword);

  disp_str(keyword);

  disp_reverse_str(keyword);
  
  my_strcpy(new_str, keyword);
  
  disp_str(new_str);

  return 0;
}

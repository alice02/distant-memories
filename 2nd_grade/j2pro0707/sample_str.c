#include <stdio.h>

int my_strlen(const char str[]);
void disp_str(const char str[]);
void disp_reverse_str(const char str[]);
void my_strcpy(char s1[], const char s2[]);

/*
 *   ʸ�����Ĺ�����֤���'\0'��ʸ�����˴ޤޤʤ���
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
 *   ������ä�ʸ�����ɸ�����
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
 *   ������ä�ʸ�����ս�ˤ���ɸ�����
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
 *   ������ä�ʸ�����ս�ˤ���ɸ�����
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
 *   �ᥤ��ؿ�
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

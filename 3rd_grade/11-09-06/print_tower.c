#include <stdio.h>
#include "stack.h"

void  my_print_tower(struct stack  *ss)
{
  int  i, j;

  // ���̥��ꥢ
  printf("\33[2J");

  //����������֤򡢹⤵0���ܡ���0���ܤ˰�ư
  printf("\033[%d;%dH" ,0,0);


  for (i = 0;  i < ss->i_size;  i++)  //�� ȿ�����
  {
    for (j = 0;  j < 3;  j++)
    {
      if (i >=  ss[j].i_sp)  //�� ʬ�����
      {
	printf("%2d ", ss[j].ia_stack[i]);  //�� ��2����
      }
      else
      {
	printf("   ");
      }
    }
    printf("\n");
  }

  printf("--------\n");
  printf(" a  b  c\n");
}


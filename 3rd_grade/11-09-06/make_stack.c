#include <stdlib.h>
#include "stack.h"

void  my_make_stack(struct stack  *ss,
		    int  i_size)
{
  //  int  i;

  ss->i_size = i_size;  //�� ����
  ss->i_sp = i_size;  //�� ����
  ss->ia_stack = (int *)malloc(sizeof(int)*i_size);  //�� ����
}

#include "stack.h"

void  my_init_tower(struct stack  *ss)
{
  int  i;

  // �礭�����פ����˥����å����Ѥࡥ
  for (i = ss->i_size-1; i >= 0;  i--)  //�� �������ȿ�����
  {
    my_push(ss, i);  //�� ����
  }
}

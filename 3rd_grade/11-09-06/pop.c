#include "stack.h"

// ���Υ����å��ϡ������ź�����礭���ΰ褫�龮���������˸����ä�
// �ǡ������Ѥ�Ǥ�����
// �����å��ݥ��󥿤ϡ��ǽ顤�����å����ΰ賰��ؤ��Ƥ��롥
int  my_pop(struct stack  *ss,
	    int  *ip_num)
{
  int  i_ret;

  if (ss->i_sp == ss->i_size)  //�� ʬ�����
  {
    // �����å��϶���
    i_ret = 1;  //�� ����
  }
  else
  {
    *ip_num = ss->ia_stack[ss->i_sp];  //�� ����
    (ss->i_sp)++;  //�� �ͤι���
    i_ret = 0;  //�� ����
  }

  return i_ret;  //�� �����
}

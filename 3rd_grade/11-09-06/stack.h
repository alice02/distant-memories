// ��¤�Τ����

struct stack
{
  int  i_size;  // �����å��Υ�����
  int  i_sp;  // �����å��ݥ���
  int  *ia_stack;  // �ǡ������Ǽ�����ΰ����Ƭ����
};


// �ؿ��ץ�ȥ��������

void  my_make_stack(struct stack  *ss,
		    int  i_size);

int  my_push(struct stack  *ss,
	     int  i_num);

int  my_pop(struct stack  *ss,
	    int  *ip_num);

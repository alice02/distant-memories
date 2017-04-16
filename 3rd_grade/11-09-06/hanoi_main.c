#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "hanoi.h"

int  main(int argc, char *argv[])
{
  int  i_size;
  struct stack  ss[3];
  char  c_sel_from, c_sel_to, c_dummy;
  int  i_sel_from, i_sel_to;
  int  i_data_from,  i_data_to;
  int  i_ret_from, i_ret_to;
  int  i;
  int  i_cnt = 1;

  //�� ���������å�
  if (argc-1 != 1) {
    printf("%s size\n", argv[0]);
    exit(1);
  }

  i_size = atoi(argv[1]);  //�� ����
  for (i = 0;  i < 3;  i++)
  {
    my_make_stack(&ss[i], i_size);  //�� ��2����
  }
  my_init_tower(ss);  //�� ����

  while (ss[2].i_sp != 0)  //�� ȿ�����κ���
  {
    my_print_tower(ss);  //�� ����

    printf("count = %d\n", i_cnt);
    printf("From = ");
    scanf("%c%c", &c_sel_from, &c_dummy);
    i_sel_from = c_sel_from - 'a';  //�� �Ѿ�ʸ������ͤ��Ѵ�

    i_ret_from = my_pop(&ss[i_sel_from], &i_data_from);  //�� ��2����
    if (i_ret_from == 1)  //�� ʬ�����α���
    {
      printf("No disk at '%c'\n", c_sel_from);
      sleep(2);
      continue;
    }

    printf("To   = ");
    scanf("%c%c", &c_sel_to, &c_dummy);
    i_sel_to = c_sel_to - 'a';  //�� �Ѿ�ʸ������ͤ��Ѵ�

    i_ret_to = my_pop(&ss[i_sel_to], &i_data_to);  //�� ��1����
    if (i_ret_to == 0)  //�� ʬ�����α���
    {
      // i_data_to �򸵤Υ����å����᤹��
      // i_data_to ��pop �����ǡ��������åȤ��줿���֤ˤʤäƤ���Τǡ�
      // ��ν������ͤ򻲾ȤǤ��롥
      my_push(&ss[i_sel_to], i_data_to);  //�� ����
    }
    else
    {
      // �����å��϶����ǡ�����i_size �ˤ��ơ��ɤα��פ��֤���褦�ˤ��롥
      i_data_to = ss[i_sel_to].i_size;
    }

    if (i_data_from < i_data_to)
    {
      // ���������֤˰ܤ���
      my_push(&ss[i_sel_to], i_data_from);  //�� ����
      i_cnt++;  //�� �ͤι���
    }
    else
    {
      printf("Can't move from '%c' to '%c'.\n", c_sel_from, c_sel_to);
      sleep(2);
      // ���ΰ��֤��᤹��
      my_push(&ss[i_sel_from], i_data_from);  //�� ����
      continue;
    }
  }

  my_print_tower(ss);  //�� ����
  i_cnt--;
  printf("count = %d\n", i_cnt);
  if (i_cnt == (int)pow(2, i_size) -1)  //�� pow() �ΰ���
  {
    printf("Perfect !!\n");
  }
  else
  {
    printf("Success !\n");
  }

  for (i = 0;  i < 3;  i++)
  {
    free(ss[i].ia_stack);  //�� ����
  }

  return 0;
}

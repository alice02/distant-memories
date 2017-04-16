#include <stdio.h>
#include <stdlib.h>
#include "list_d.h"

void my_insert_d(struct list *header)
{
  struct list *p;  // �ɲä��륻���ľ���Υ��������
  struct list *x;  // ����������
  int i_search;    // �ܤ��ǡ�������
  int i_insert;    // ��������ǡ�������

  printf("Search number = ");
  scanf("%d", &i_search);

  for (p = header->next;
       p->next != header && p->i_data != i_search;
       p = p->next);

  if (p->next == header) {
    printf("No data %d\n", i_search);
  }
  else {
    x = (struct list *)malloc(sizeof(struct list));

    if (x == NULL) {
      printf("ERROR: memory full.\n");
      exit(1);
    }

    printf("Insert number = ");
    scanf("%d", &i_insert);

    x->i_data = i_insert;

    x->prev = p;
    x->next = p->next;
    p->next->prev = x;
    p->next = x;
  }

}

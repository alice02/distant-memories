#include <stdio.h>
#include <stdlib.h>
#include "list_d.h"

void my_insert_d(struct list *header)
{
  struct list *p;  // 追加するセルの直前のセルの番地
  struct list *x;  // 新しいセル
  int i_search;    // 捜すデータの値
  int i_insert;    // 挿入するデータの値

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

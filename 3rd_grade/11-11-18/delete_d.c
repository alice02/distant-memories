#include <stdio.h>
#include <stdlib.h>
#include "list_d.h"

void my_delete_d(struct list *header)
{
  struct list *p;
  int i_search;

  printf("Delete number = ");
  scanf("%d", &i_search);

  p = header->next;
  while (p != header) {
    if (p->i_data == i_search) {
      p->prev->next = p->next;
      p->next->prev = p->prev;

      free(p);
      break;
    }
    p = p->next;

    if (p->next == header) {
      printf("No data %d\n", i_search);
    }
  }
}

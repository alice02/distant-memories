#include "list.h"
#include <stdio.h>

void my_print_list(struct list *header)
{
  struct list *now;

  now = header->next;

  while (now != NULL)
  {
    printf("%d ", now->i_data);
    now = now->next;
  }
  printf("\n");
}

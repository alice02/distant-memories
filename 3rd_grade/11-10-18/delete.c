#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void my_delete(struct list *x,
	       int i_num)
{
  struct list *now;
  struct list *delete;

  now = x;

  while (now->next != NULL && (now->next)->i_data != i_num)
  {
    now = now->next;
  }

  if (now->next == NULL)
  {
    printf("%d is NOT found.\n", i_num);
  }
  else {
    delete = now->next;
    now->next = delete->next;
    free(delete);
  }
}

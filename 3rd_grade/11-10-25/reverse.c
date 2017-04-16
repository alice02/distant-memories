#include "list.h"
#include <stdlib.h>

struct list *my_reverse(struct list *x)
{
  struct list *now, *old, *tmp;

  old = NULL;

  for (now = x->next; now != NULL; now = tmp) {
    tmp = now->next;
    now->next = old;
    old = now;
  }

  return old;
}

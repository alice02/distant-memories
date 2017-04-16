#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct list *my_append(struct list *x,
		       int i_num)
{
  struct list *p;

  p = (struct list *)malloc(sizeof(struct list));
  if (p == NULL) {
    printf("error\n" );
    exit(1);
  }

  p->i_data = i_num;

  p->next = x->next;
  x->next = p;

  return p;
}

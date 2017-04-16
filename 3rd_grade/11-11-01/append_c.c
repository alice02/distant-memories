#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *my_append(struct list *ptr,
		       int i_num)
{
  struct list *p;

  p = (struct list *)malloc(sizeof(struct list));

  if (p == NULL) {
    printf("ERROR: memory full.\n");
    exit(1);
  }

  p->i_data = i_num;

  if (ptr->next == NULL) {
    ptr->next = p;
    p->next = p;
  }
  else {
    p->next = ptr->next;
    ptr->next = p;
  }

  return p;
}

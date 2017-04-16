#include "merge_sort_list.h"

struct node *merge_list(struct node *a, struct node *b)
{
  struct node head, *p;

  p = &head;

  while (a != NULL && b != NULL) {
    if (a->value <= b->value) {
      p->next = a;
      p = a;
      a = a->next;
    }
    else {
      p->next = b;
      p = b;
      b = b->next;
    }
  }

  if (a == NULL) {
    p->next = b;
  }
  else {
    p->next = a;
  }

  return head.next;
}

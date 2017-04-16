#include "merge_sort_list.h"

struct node *merge_sort_list(struct node *x)
{
  struct node *a, *b, *p;

  if (x == NULL || x->next == NULL) {
    return x;
  }

  a = x;

  b = x->next;
  if (b != NULL) {
    b = b->next;
  }

  while (b != NULL) {
    a = a->next;
    b = b->next;
    if (b != NULL) {
      b = b->next;
    }
  }

  p = a->next;
  a->next = NULL;

  return merge_list(merge_sort_list(x), merge_sort_list(p));
}

#include <stdlib.h>

struct node
{
  int value;
  struct node *next;
};

struct node *merge_list(struct node *a, struct node *b);

struct node *merge_sort_list(struct node *x);

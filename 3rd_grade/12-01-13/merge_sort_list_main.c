#include "merge_sort_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  struct node head, *p, *new;
  int i_size;
  int i;

  i_size = argc-1;
  if (i_size == 0) {
    printf("USAGE: %s num1 num2 num3 ...\n", argv[0]);
    exit(1);
  }

  p = &head;
  for (i = 0; i < i_size; i++) {
    new = (struct node *)malloc(sizeof(struct node));
    new->value = atoi(argv[i+1]);
    p->next = new;
    p = new;
  }
  p->next = NULL;

  p = merge_sort_list(head.next);

  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("\n");

  return 0;
}

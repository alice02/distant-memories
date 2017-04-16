#include <stdio.h>
#include <stdlib.h>
#include "list_d.h"

struct list *my_append(struct list *header,
		       int i_num)
{
  struct list *p;
  struct list *tail;

  p = (struct list *)malloc(sizeof(struct list));
  tail = (struct list *)malloc(sizeof(struct list));

  if (p == NULL || tail == NULL) {
    printf("ERROR: memory full.\n");
    exit(1);
  }

  p->i_data = i_num;


  if (header->next == NULL) {
    header->next = p;
    header->prev = p;
    p->next = header;
    p->prev = header;
  }
  else {
    tail = header->prev;
    tail->next = p;
    p->next = header;
    p->prev = tail;
    header->prev = p;
  }

  return p;
}

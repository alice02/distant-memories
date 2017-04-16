#include "list.h"
#include <stdio.h>

#define LOOP (3)

void my_print_list(struct list *header)
{
  struct list *now;
  int i;

  if (header->next != NULL) {

    for (i = 0; i < LOOP; i++) {
      now = header->next;
      do {
	printf("%d ", now->i_data);
	now = now->next;
      } while (now != header->next);

      if (i < LOOP-1) {
	printf(": ");
      }
    }
    printf("\n");

  }

}

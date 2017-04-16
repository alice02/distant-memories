#include <stdio.h>
#include "list_d.h"

void my_print_list_d(struct list *ptr,
		     int i_switch)
{
  struct list *now;

  switch (i_switch) {
  case 0:
    for (now = ptr->next; now != ptr; now = now->next) {
      printf("%d ", now->i_data);
    }
    printf("\n");
    break;

  case 1:
    for (now = ptr->prev; now != ptr; now = now->prev) {
      printf("%d ", now->i_data);
    }
    printf("\n");
    break;

  default :
    break;
  }
}

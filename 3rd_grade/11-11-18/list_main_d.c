#include <stdio.h>
#include "list_d.h"

void my_delete_d(struct list *header);

int main(void)
{
  struct list header;
  struct list *last;
  int i_data;
  int i_switch;

  header.next = &header;
  header.prev = &header;

  printf("Input number = ");
  scanf("%d", &i_data);

  while (i_data > 0) {
    my_append(&header, i_data);
    printf("Input number = ");
    scanf("%d", &i_data);
  }

  my_print_list_d(&header, 0);
  my_print_list_d(&header, 1);

  my_insert_d(&header);

  my_print_list_d(&header, 0);
  my_print_list_d(&header, 1);

  my_delete_d(&header);

  my_print_list_d(&header, 0);
  my_print_list_d(&header, 1);

  return 0;
}

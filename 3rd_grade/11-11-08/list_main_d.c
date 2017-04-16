#include <stdio.h>
#include "list_d.h"

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
  printf("\n");
  my_print_list_d(&header, 1);

  return 0;
}

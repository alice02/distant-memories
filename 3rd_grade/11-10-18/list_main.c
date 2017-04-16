#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  struct list header;
  struct list *last;
  int i_data;

  header.next = NULL;
  last = &header;

  printf("Input number = ");
  scanf("%d", &i_data);

  while(i_data > 0) {
    last = my_append(last, i_data);
    printf("Input number = ");
    scanf("%d", &i_data);
  }

  my_print_list(&header);

  printf("Input delete data = ");
  scanf("%d", &i_data);

  my_delete(&header, i_data);

  my_print_list(&header);

  return 0;
}

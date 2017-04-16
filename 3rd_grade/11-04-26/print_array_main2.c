#include <stdio.h>
#include <string.h>

void my_print_array(char  ca_data[]);


int main(void)
{
  char  ca_array[255];

  strcpy(ca_array, "Kisarazu");

  my_print_array(ca_array);

  return 0;
}

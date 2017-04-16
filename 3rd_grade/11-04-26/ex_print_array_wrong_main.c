#include <stdio.h>

void my_print_array(char  ca_data[]);


int main(void)
{
  char  ca_array[255];

  ca_array = "Kisarazu";
  my_print_array(ca_array);

  return 0;
}

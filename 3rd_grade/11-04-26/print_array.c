#include <stdio.h>

void my_print_array(char  ca_data[])
{
  int  i;

  for (i=0; ca_data[i]!='\0'; i++) {
    printf("%c", ca_data[i]);
  }

  printf("\n");

}

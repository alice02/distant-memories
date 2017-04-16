#include <stdlib.h>
#include <stdio.h>

int my_string2int(char  ca_string[]);


int main(int argc,  char *argv[])
{
  int  i_ans;

  if (argc -1 != 2)
  {
    printf("USAGE: %s int_number int number\n", argv[0]);
    exit(1);
  }

  i_ans = my_string2int(argv[1]) + my_string2int(argv[2]);
  printf("%d\n", i_ans);

  return 0;
}

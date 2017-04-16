#include "string_search.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i;
  int i_ret;

  if (argc - 1 < 2) {
    printf("USAGE: %s text pattern\n", argv[0]);
    exit(-1);
  }

  i_ret = string_search(argv[1], argv[2]);

  if (i_ret == -1) {
    printf("\"%s\" dose NOT exist in \"%s\"\n", argv[2], argv[1]);
  }
  else {
    printf("%s\n", argv[1]);
    for (i = 0; i < i_ret; i++) {
      printf(" ");
    }
    printf("%s\n", argv[2]);
  }

  return i_ret;
}

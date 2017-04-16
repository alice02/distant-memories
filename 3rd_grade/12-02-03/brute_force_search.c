#include "string_search.h"
#include <string.h>

int string_search(char text[],
		  char pattern[])
{
  int i, j;
  int i_ret;
  int text_len, pat_len;

  i = 0;
  j = 0;

  text_len = strlen(text);
  pat_len = strlen(pattern);

  while (i < text_len && j < pat_len) {

    if (text[i] == pattern[j]) {
      i++;
      j++;
    }
    else {
      i = i - j + 1;
      j = 0;
    }
  }

  if (j == pat_len) {
    i_ret = i - j;
  }
  else {
    i_ret = -1;
  }

  return i_ret;
}

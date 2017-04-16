#include "string_search.h"
#include <string.h>

#define max(a,b)  ((a) > (b) ? a : b)

typedef unsigned char  uchar;

int string_search(char text[],
		  char pattern[])
{
  int skip[256];
  int i, j;
  int pat_len, text_len;

  pat_len = strlen(pattern);
  text_len = strlen(text);

  for (i = 0; i < 256; i++) {
    skip[(uchar)i] = pat_len;
  }

  for (i = 0; i < pat_len - 1; i++) {
    skip[(uchar)pattern[i]] = pat_len - i - 1;
  }

  i = pat_len - 1;

  while (i < text_len) {
    j = pat_len - 1;

    while (text[i] == pattern[j]) {
      if (j == 0) {
	return i;
      }
      i--;
      j--;
    }

    i +=  max(skip[(uchar)text[i]], pat_len - j);
  }

  return -1;
}

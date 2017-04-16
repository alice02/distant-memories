#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 235881	/* 辞書ファイルの行数 */

int main(void)
{
  int count = 0, i;
  char tmp[45];
  FILE *fp;

  fp = fopen("words", "r");
  if (fp == NULL) {
    printf("error\n");
    exit(1);
  }

  for (i = 0; i < WORD_SIZE; i++) {
    fscanf(fp, "%s", tmp);
    if (count < strlen(tmp)) {
      count = strlen(tmp);
    }
  }

  printf("%d\n", count);

  fclose(fp);

  return 0;
}

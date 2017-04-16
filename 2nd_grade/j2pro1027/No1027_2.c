#include <stdio.h>

int main(void)
{
  int no;
  int *point;

  point = &no;
  *point = 4649;

  printf("   no = %d,  %p\n", no, &no);
  printf("point = %d,  %p\n", *point, point);

  return 0;
}

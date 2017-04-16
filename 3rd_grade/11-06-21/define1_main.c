#include <stdio.h>
#include <stdlib.h>

#define square(x) ( x * x )

int main(int argc, char *argv[])
{
  int a, b, ans;

  if (argc-1 != 2) {
    printf("%s data1 data2\n", argv[0]);
    printf("data1 とdata2 を加えた値の2乗を求めます（間違い）．\n");
    printf("データの型は整数です．\n");
    exit(1);
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);

  ans = square(a+b);

  printf("%d\n", ans);

  return 0;
}

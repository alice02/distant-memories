#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void set_array(int *a, int *b, int num);
void disp_array(int *a, int *b, int num);
void array_copy(int *a, const int *b, int num);

int main(void)
{
  srand((unsigned)time(NULL));

  int num;

  printf("num = ");
  scanf("%d", &num);

  int a[num];
  int b[num];

  set_array(a, b, num);
  disp_array(a, b, num);
  array_copy(a, b, num);
  disp_array(a, b, num);

  return 0;
}

void disp_array(int *a, int *b, int num)
{
  int i;

  for (i=0; i<num; i++) {
    printf("a[%d] = %d", i, a[i]);
    printf("    b[%d] = %d\n", i, b[i]);
  }
  printf("\n");

}

void set_array(int *a, int *b, int num)
{
  int i;

  for (i=0; i<num; i++) {
    a[i] = rand() % 100;
    b[i] = rand() % 100;
  }

}

void array_copy(int *a, const int *b, int num)
{
  int i;

  for (i=0; i<num; i++) {
    *(a+i) = *(b+i);
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 5

int min_of(const int vc[], int no)
{
  int i;
  int min = vc[0];

  for (i=1; i<no; i++) {
    if (vc[i] < min){
      min = vc[i];
    }
  }

  return min;
}

int main(void)
{
  int i;
  int eng[NUMBER];
  int mat[NUMBER];
  int min_e, min_m;

  srand((unsigned)time(NULL));

  for (i=0; i<NUMBER; i++) {
    eng[i] = rand() % 101;
    mat[i] = rand() % 101;
    printf("[%d] �Ѹ졧%d\n",i+1 ,eng[i]);
    printf("    ���ء�%d\n", mat[i]);
   }

  min_e = min_of(eng, NUMBER);
  min_m = min_of(mat, NUMBER);

  printf("�Ѹ�κ�������%d\n", min_e);
  printf("���ؤκ�������%d\n", min_m);

  return 0;
}

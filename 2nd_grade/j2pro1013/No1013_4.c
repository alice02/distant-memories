#include <stdio.h>

void disp_matrix(int ma_a[][3], int ma_b[][3]);

int main(void)
{
  int ma_a[3][3] = {{1,4,3},{5,-3,4},{1,2,3}};
  int ma_b[3][3] = {{-1,6,3},{0,5,4},{-1,-2,-3}};

  disp_matrix(ma_a, ma_b);
  
  return 0;
}

void disp_matrix(int ma_a[][3], int ma_b[][3])
{
  int i, j;

  printf("a:\n");

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      printf("%3d", ma_a[i][j]);
    }
    printf("\n");
  }

  printf("\nb:\n");

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      printf("%3d", ma_b[i][j]);
    }
    printf("\n");
  }


}


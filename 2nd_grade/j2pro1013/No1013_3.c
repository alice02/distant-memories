#include <stdio.h>

void calc_and_disp_matrix(int a[][2], int b[][2]);

int main(void)
{
  int ma_a[2][2] = {{1,4},{5,-3}};
  int ma_b[2][2] = {{-1,6},{0,5}};

  calc_and_disp_matrix(ma_a, ma_b);
  
  return 0;
}

void calc_and_disp_matrix(int a[][2], int b[][2])
{
  int i, j;
  int array[2][2];

  for (i=0; i<2; i++) {
    for (j=0; j<2; j++) {
      array[i][j] = a[i][j] + b[i][j];
    }
  }

  for (i=0; i<2; i++) {
    for (j=0; j<2; j++) {
      printf("%3d", array[i][j]);
    }
    printf("\n");
  }
}


#include <stdio.h>

void set_matrix(int ma[][9]);
void disp_matrix(int ma[][9]);

int main(void)
{
  int ma[9][9];

  set_matrix(ma);
  
  disp_matrix(ma);

  return 0;
}

void set_matrix(int m[][9])
{
  int i, j;

  for (i=0; i<9; i++) {
    for (j=0; j<9; j++) {
      m[i][j] = (i+1) * (j+1);
    }
  }
}

void disp_matrix(int m[][9])
{
  int i, j;

  for (i=0; i<9; i++) {
    for (j=0; j<9; j++) {
      printf("%3d ", m[i][j]);
    }
    printf("\n");
  }    
  printf("\n");
}

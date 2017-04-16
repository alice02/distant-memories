#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 40

void set_point(int point[], int no);
void disp_point(const int point[], int no);
double calc_average(const int point[], int no);

int main(void)
{
  int point[NUMBER];
  double average;

  srand((unsigned)time(NULL));

  set_point(point, NUMBER);

  disp_point(point, NUMBER);

  average = calc_average(point, NUMBER);
  printf("average=%f\n", average);

  return 0;
}

void set_point(int point[], int no)
{
  int i;
  
  for (i=0; i<no; i++) {
    point[i] = rand()%101;
  }

}

void disp_point(const int point[], int no)
{
  int i;
  
  for (i=0; i<no; i++) {
    printf("[%2d] = %3d\n", i, point[i]);
  }

}

double calc_average(const int point[], int no)
{
  int i;
  double ave=0;
  for (i=0; i<no; i++) {
    ave += point[i];
  }

  return ave/no;
}

#include <stdio.h>

#define NUM 5

struct para {
  int no;
  double height;
  double weight;
};

void input(struct para data[]);
void disp(struct para data[]);

int main(void)
{
  struct para data[NUM];

  input(data);

  disp(data);

  return 0;
}

void input(struct para data[])
{
  int i;

  for (i=0; i<NUM; i++) {
    data[i].no = i;
    printf("data[%d]:\n", data[i].no);
    printf("height = ");
    scanf("%lf", &data[i].height);
    printf("weight = ");
    scanf("%lf", &data[i].weight);
  }

  printf("\n");

}

void disp(struct para data[])
{
  int i;

  for (i=0; i<NUM; i++) {
    printf("data[%d]: height = %f , weight = %f\n", data[i].no, data[i].height, data[i].weight);
  }

}

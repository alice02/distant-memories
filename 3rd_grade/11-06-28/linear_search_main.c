#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM  10

struct table
{
  int  i_num;
  int  ia_data[NUM];
};

int my_linear_search(struct table  ta,
		     int  i_key);

void my_sort(struct table  *ta,
	     int  i_max);

void my_print_array(struct table  ta,
		    int  i_num)
{
  int  i;

  for (i = 0;  i < i_num;  i++)
  {
    printf("%d ", ta.ia_data[i]);
  }
  printf("\n");
}


int main(int argc, char *argv[])
{
  int  i;
  int  i_key;
  int  i_ret;
  struct table  ta;

  srand((unsigned)time(NULL));

  if (argc-1 != 1) {
    printf("%s number\n", argv[0]);
    exit(1);
  }

  i_key = atoi(argv[1]);

  for (i = 0; i < NUM; i++) {
    ta.ia_data[i] = rand()%20;
  }

  my_print_array(ta, NUM);

  my_sort(&ta, NUM);

  my_print_array(ta, NUM);

  i_ret = my_linear_search(ta, i_key);

  if (i_ret == 1) {
    printf("%d  is not found !\n", i_key);
    return 1;
  }

  printf("%d is found!\n", i_key);

  return 0;
}

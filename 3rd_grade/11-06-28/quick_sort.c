#include <stdio.h>

#define NUM  10

struct table
{
  int  i_num;
  int  ia_data[NUM];
};


int partition(struct table  *ta,
	      int  l,
	      int  r)
{
  int  i, j, pivot;
  int  i_tmp;

  i = l-1;
  j = r;

  pivot = ta -> ia_data[r];
  
  for (;;) {

    for (i++; ta -> ia_data[i] < pivot; i++) {
    }

    for (j--; i < j && pivot < ta -> ia_data[j]; j--) {
    }
    
    if (i >= j) {
      break;
    }

    i_tmp = ta -> ia_data[i];
    ta -> ia_data[i] = ta -> ia_data[j];
    ta -> ia_data[j] = i_tmp;
  }

  i_tmp = ta -> ia_data[i];
  ta -> ia_data[i] = ta -> ia_data[r];
  ta -> ia_data[r] = i_tmp;

  return i;
}


/* 実際にクイックソートを行う関数 */
void quick_sort_1(struct table  *ta,
		  int  l,
		  int  r)
{
  int  v;

  if (l >= r){
    return;
  }

  v = partition(ta, l, r);

  quick_sort_1(ta, l, v-1);

  quick_sort_1(ta, v+1, r);
}

void my_sort(struct table  *ta,
	     int  i_max)
{
  quick_sort_1(ta, 0, i_max -1);
}

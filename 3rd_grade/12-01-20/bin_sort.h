typedef struct
{
  int key;
  int other;
} DATA;

void bin_sort(DATA a[],
	      int n,		/* データの個数 */
	      int MAX);		/* 値域の最大値 */

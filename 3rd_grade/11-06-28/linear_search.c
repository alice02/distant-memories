#define NUM  10

struct table
{
  int  i_num;
  int  ia_data[NUM];
};

int my_linear_search(struct table  ta,
		     int  i_key)
{
  int  i;
  int  i_flag = 1;

  for (i = 0; i < ta.i_num; i++) {
    if (ta.ia_data[i] == i_key) {
      i_flag = 0;
      return i_flag; 
    }
  }

  return i_flag;
}

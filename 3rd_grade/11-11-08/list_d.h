struct list
{
  struct list  *next;
  struct list  *prev;
  int  i_data;
};


struct list  *my_append(struct list  *x,
			int  i_num);

void my_print_list_d(struct list  *header,
		     int  i_switch);  // 0: forward,  1: backward

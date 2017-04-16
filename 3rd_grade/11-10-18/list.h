struct list
{
  struct list *next;
  int i_data;
};

struct list *my_append(struct list *x,
		       int i_num);

void my_print_list(struct list *header);

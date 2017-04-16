struct node
{
  struct node  *left;
  struct node  *right;
  char         label;
};


void
preorder(struct node  *p);

void
inorder(struct node  *p);

void
postorder(struct node  *p);



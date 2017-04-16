#include <stdio.h>
#include "tree.h"

void preorder(struct node *p)
{
  if (p == NULL) {
    return ;
  }
  printf("%c\n", p->label);
  preorder(p->left);
  preorder(p->right);
}

void inorder(struct node *p)
{
  if (p == NULL) {
    return ;
  }
  preorder(p->left);
  printf("%c\n", p->label);
  preorder(p->right);
}

void postorder(struct node *p)
{
  if (p == NULL) {
    return ;
  }
  preorder(p->left);
  preorder(p->right);
  printf("%c\n", p->label);
}

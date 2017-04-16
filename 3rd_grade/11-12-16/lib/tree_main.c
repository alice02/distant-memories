#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int
main(int  argc,
     char *argv[])
{
  FILE  *fr;
  struct node  root;
  int  i_switch;

  if (argc -1 != 1)
  {
    fprintf(stderr, "USAGE: %s filename\n", argv[0]);
    exit(1);
  }

  fr = fopen(argv[1], "r");
  if (fr == NULL)
  {
    fprintf(stderr, "Can NOT read %s\n", argv[1]);
    exit(2);
  }

  my_tree_make(&root, fr);

  printf("0: preorder\n");
  printf("1: inorder\n");
  printf("2: postorder\n");
  printf("Input number = ");
  scanf("%d", &i_switch);

  switch (i_switch)
  {
  case 0:
    preorder(&root);
    break;
  case 1:
    inorder(&root);
    break;
  case 2:
    postorder(&root);
    break;
  default:
    break;
  }

  return 0;
}

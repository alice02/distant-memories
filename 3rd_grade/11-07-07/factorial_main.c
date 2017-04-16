/*↑↑↑ 涩妥な洁洒柒推を今くˉ↑↑↑*/
#include <stdio.h>
#include <stdlib.h>

int  main(int argc,  char *argv[])
{
  int  i_num;
  int  i_fact;

  /*↑↑↑ 借妄柒推を今くˉ↑↑↑*/
  if (argc-1 != 1) {
    printf("%s number\n", argv[0]);
    exit(1);
  }

  i_num = atoi(argv[1]);

  if (i_num < 0) {
    printf("Please input non-negative number.\n");
    exit(2);
  }

  i_fact = my_factorial(i_num);
  
  printf("%d! = %d\n", i_num, i_fact);

  return 0;
}

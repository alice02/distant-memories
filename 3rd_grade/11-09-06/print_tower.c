#include <stdio.h>
#include "stack.h"

void  my_print_tower(struct stack  *ss)
{
  int  i, j;

  // ²èÌÌ¥¯¥ê¥¢
  printf("\33[2J");

  //¥«¡¼¥½¥ë°ÌÃÖ¤ò¡¢¹â¤µ0¹ÔÌÜ¡¢²£0¹ÔÌÜ¤Ë°ÜÆ°
  printf("\033[%d;%dH" ,0,0);


  for (i = 0;  i < ss->i_size;  i++)  //¡ü È¿Éü¾ò·ï
  {
    for (j = 0;  j < 3;  j++)
    {
      if (i >=  ss[j].i_sp)  //¡ü Ê¬´ô¾ò·ï
      {
	printf("%2d ", ss[j].ia_stack[i]);  //¡ü Âè2°ú¿ô
      }
      else
      {
	printf("   ");
      }
    }
    printf("\n");
  }

  printf("--------\n");
  printf(" a  b  c\n");
}


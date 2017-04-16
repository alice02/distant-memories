#include <stdio.h>

typedef long  ELEM;

#define QUEUE_SIZE      /*¡ü¡ü¡ü ÄêµÁ ¡ü¡ü¡ü*/
#define next(a)      /*¡ü¡ü¡ü ÄêµÁ ¡ü¡ü¡ü*/

int  dequeue(ELEM  queue[],
	     int  *front,
	     int  rear,
	     ELEM *x);

void  enqueue(ELEM  queue[],
	      int  front,
	      int  *rear,
	      ELEM  x);


int  main(void)
{
  ELEM  queue[QUEUE_SIZE];
  ELEM  input, output;
  int   i_op;
  int   i_ret;
  int   front;
  int   rear;
  int   i;

  init(&front, &rear);

  while (1)
  {
    printf("queue = ");
    for ( )    /*¡ü¡ü¡ü ½é´ü²½¡¤È¿Éü¾ò·ï¡¤¹¹¿·½èÍý ¡ü¡ü¡ü*/
    {
      printf("%ld ", queue[i]);
    }
    printf("\n");

    printf("Operation (0:enqueue, 1:dequeue, 2:end) = ");
    scanf( );  /*¡ü¡ü¡ü °ú¿ô ¡ü¡ü¡ü*/
    if (i_op == 0 )
    {
      printf("Input data = ");
      scanf("%ld", );
      enqueue( );  /*¡ü¡ü¡ü °ú¿ô ¡ü¡ü¡ü*/
    }
    else if (i_op == 1)
    {
      i_ret = dequeue( );  /*¡ü¡ü¡ü °ú¿ô ¡ü¡ü¡ü*/
      if ( )  /*¡ü¡ü¡ü Ê¬´ô¾ò·ï ¡ü¡ü¡ü*/
      {
	printf("Extracted data = %d\n", output);
      }
    }
    else if (i_op == 2)
    {
      break;
    }
  }

  return 0;
}

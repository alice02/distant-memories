#include <stdio.h>

typedef long  ELEM;

#define QUEUE_SIZE 5     /*¡ü¡ü¡ü ÄêµÁ ¡ü¡ü¡ü*/
#define next(a) (((a) + 1) % QUEUE_SIZE)     /*¡ü¡ü¡ü ÄêµÁ ¡ü¡ü¡ü*/

int  dequeue(ELEM  queue[],
	     int  *front,
	     int  rear,
	     ELEM *x);

void  enqueue(ELEM  queue[],
	      int  front,
	      int  *rear,
	      ELEM  x);

void init(int *front,
          int *rear);

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
    for (i = front; i != rear; i=next(i))
    {
      printf("%ld ", queue[i]);
    }
    printf("\n");

    printf("Operation (0:enqueue, 1:dequeue, 2:end) = ");
    scanf("%d", &i_op);  /*¡ü¡ü¡ü °ú¿ô ¡ü¡ü¡ü*/
    if (i_op == 0 )
    {
      printf("Input data = ");
      scanf("%ld", &input);
      enqueue(queue, front, &rear, input);  /*¡ü¡ü¡ü °ú¿ô ¡ü¡ü¡ü*/
    }
    else if (i_op == 1)
    {
      i_ret = dequeue(queue, &front, rear, &output);  /*¡ü¡ü¡ü °ú¿ô ¡ü¡ü¡ü*/
      if (i_ret == 0)  /*¡ü¡ü¡ü Ê¬´ô¾ò·ï ¡ü¡ü¡ü*/
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

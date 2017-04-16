#include <stdio.h>

typedef long  ELEM;

#define QUEUE_SIZE      /*������ ��� ������*/
#define next(a)      /*������ ��� ������*/

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
    for ( )    /*������ �������ȿ������������ ������*/
    {
      printf("%ld ", queue[i]);
    }
    printf("\n");

    printf("Operation (0:enqueue, 1:dequeue, 2:end) = ");
    scanf( );  /*������ ���� ������*/
    if (i_op == 0 )
    {
      printf("Input data = ");
      scanf("%ld", );
      enqueue( );  /*������ ���� ������*/
    }
    else if (i_op == 1)
    {
      i_ret = dequeue( );  /*������ ���� ������*/
      if ( )  /*������ ʬ����� ������*/
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

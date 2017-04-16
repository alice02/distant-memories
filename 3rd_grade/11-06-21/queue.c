#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long  ELEM;

#define QUEUE_SIZE 5   /*������ ��� ������*/
#define next(a) (((a) + 1) % QUEUE_SIZE)   /*������ ��� ������*/


void error(char *s)
{
  /*������ ���� ������*/
  fprintf(stderr, s);
}

void init(int *front,
	  int *rear)
{
  /*������ ���� ������*/
  *front = *rear = 0;
}

void enqueue(ELEM  queue[],
	     int  front,
	     int  *rear,
	     ELEM  x)
{
  if (next(*rear) == front)  /*������ ʬ����� ������*/
  {
    error("�Ԥ����󤬥ե�ʤΤ����Ǥ�������ޤ���\n");
  }
  else
  {
    /*������ ���� ������*/
    queue[*rear] = x;
    *rear = next(*rear);
  }
}

int dequeue(ELEM  queue[],
	    int  *front,
	    int  rear,
	    ELEM *x)
{
  int  i_ret = 0;

  if (*front == rear)  /*������ ʬ����� ������*/
  {
    error("�Ԥ����󤬶��ʤΤ����Ǥ���Ф��ޤ���\n");
    i_ret = 1;   /*������ ���� ������*/
  }
  else
  {
    /*������ ���� ������*/
    *x = queue[*front];
    *front = next(*front);
    i_ret = 0;
  }

  return i_ret;  /*������ ����� ������*/
}

int  empty(int  front,
	   int  rear)
{
  return front == rear;
}

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long  ELEM;

#define QUEUE_SIZE    /*������ ��� ������*/
#define next(a)    /*������ ��� ������*/


void error(char *s)
{
  /*������ ���� ������*/

}

void init(int *front,
	  int *rear)
{
  /*������ ���� ������*/

}

void enqueue(ELEM  queue[],
	     int  front,
	     int  *rear,
	     ELEM  x)
{
  int  i;

  if ( )  /*������ ʬ����� ������*/
  {
    error("�Ԥ����󤬥ե�ʤΤ����Ǥ�������ޤ���\n");
  }
  else
  {
    /*������ ���� ������*/
  }
}

int dequeue(ELEM  queue[],
	    int  *front,
	    int  rear,
	    ELEM *x)
{
  int  i_ret = 0;

  if ( )  /*������ ʬ����� ������*/
  {
    error("�Ԥ����󤬶��ʤΤ����Ǥ���Ф��ޤ���\n");
    i_ret = ;   /*������ ���� ������*/
  }
  else
  {
    /*������ ���� ������*/

  }

  return ;  /*������ ����� ������*/
}

int  empty(int  front,
	   int  rear)
{
  return front == rear;
}

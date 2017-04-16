#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long  ELEM;

#define QUEUE_SIZE 5   /*¡ü¡ü¡ü ÄêµÁ ¡ü¡ü¡ü*/
#define next(a) (((a) + 1) % QUEUE_SIZE)   /*¡ü¡ü¡ü ÄêµÁ ¡ü¡ü¡ü*/


void error(char *s)
{
  /*¡ü¡ü¡ü ½èÍý ¡ü¡ü¡ü*/
  fprintf(stderr, s);
}

void init(int *front,
	  int *rear)
{
  /*¡ü¡ü¡ü ½èÍý ¡ü¡ü¡ü*/
  *front = *rear = 0;
}

void enqueue(ELEM  queue[],
	     int  front,
	     int  *rear,
	     ELEM  x)
{
  if (next(*rear) == front)  /*¡ü¡ü¡ü Ê¬´ô¾ò·ï ¡ü¡ü¡ü*/
  {
    error("ÂÔ¤Á¹ÔÎó¤¬¥Õ¥ë¤Ê¤Î¤ÇÍ×ÁÇ¤òÆþ¤ì¤é¤ì¤Þ¤»¤ó\n");
  }
  else
  {
    /*¡ü¡ü¡ü ½èÍý ¡ü¡ü¡ü*/
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

  if (*front == rear)  /*¡ü¡ü¡ü Ê¬´ô¾ò·ï ¡ü¡ü¡ü*/
  {
    error("ÂÔ¤Á¹ÔÎó¤¬¶õ¤Ê¤Î¤ÇÍ×ÁÇ¤ò¼è¤ê½Ð¤»¤Þ¤»¤ó\n");
    i_ret = 1;   /*¡ü¡ü¡ü ±¦ÊÕ ¡ü¡ü¡ü*/
  }
  else
  {
    /*¡ü¡ü¡ü ½èÍý ¡ü¡ü¡ü*/
    *x = queue[*front];
    *front = next(*front);
    i_ret = 0;
  }

  return i_ret;  /*¡ü¡ü¡ü Ìá¤êÃÍ ¡ü¡ü¡ü*/
}

int  empty(int  front,
	   int  rear)
{
  return front == rear;
}

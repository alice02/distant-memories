#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef long  ELEM;

#define QUEUE_SIZE    /*●●● 定義 ●●●*/
#define next(a)    /*●●● 定義 ●●●*/


void error(char *s)
{
  /*●●● 処理 ●●●*/

}

void init(int *front,
	  int *rear)
{
  /*●●● 処理 ●●●*/

}

void enqueue(ELEM  queue[],
	     int  front,
	     int  *rear,
	     ELEM  x)
{
  int  i;

  if ( )  /*●●● 分岐条件 ●●●*/
  {
    error("待ち行列がフルなので要素を入れられません\n");
  }
  else
  {
    /*●●● 処理 ●●●*/
  }
}

int dequeue(ELEM  queue[],
	    int  *front,
	    int  rear,
	    ELEM *x)
{
  int  i_ret = 0;

  if ( )  /*●●● 分岐条件 ●●●*/
  {
    error("待ち行列が空なので要素を取り出せません\n");
    i_ret = ;   /*●●● 右辺 ●●●*/
  }
  else
  {
    /*●●● 処理 ●●●*/

  }

  return ;  /*●●● 戻り値 ●●●*/
}

int  empty(int  front,
	   int  rear)
{
  return front == rear;
}

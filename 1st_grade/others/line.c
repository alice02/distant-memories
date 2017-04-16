/* 繰返しと条件判定を用いて,たくさんの線を引くプログラムの例 */

#include	"graph.h"

/*
□□ 色一覧 □□
BLACK		BLUE		BROWN		GOLD		GRAY
GREEN		LIGHTBLUE	LIGHTGRAY	LIGHTGREEN	PINK
PURPLE		RED		VIOLET		WHITE		YELLOW

□□ 命令一覧 □□
waitButtonPress		drawPoint		drawCircle
fillCircle		drawEllipse		fillEllipse
drawTriangle		fillTriangle		drawRectangle
fillRectangle		drawLine		setLineWidth
floodFill		drawString

while (   ) {    }
if (   ) {   } else {   }

*/

/*
	点 (0,0) から点 (x,480) へ線を引く.
	ただし,x は最初 0 で 30,60,90,…,640 と,640 まで 30 ずつ
	大きくなってゆく.
	つまり線は
 
		(0,0)から(0,480)
		(0,0)から(30,480)
		(0,0)から(60,480)
		…
		(0,0)から(640,480)

	のように何本も引かれる.
	線の色は最初の半分(x が 320 未満の間)は紫,
	残りの半分(x が 320 より大きな値のとき)は黄色とする.
*/

main (void)
{
  int x;			/* 整数の変数vx を使うことを宣言する */

  initGraph ();

  /* 前準備として x を 0 にする */
  x = 0;
  while (x <= 640)
    {
      if (x < 320)
	{
	  drawLine (0, 0, x, 480, YELLOW);
	}
      else
	{
	  drawLine (0, 0, x, 480, PURPLE);
	}
      x = x + 30;		/* x に 30 を加えて次の x を準備する */
    }

  /* マウスのボタンが押されるのを待つ */
  waitButtonPress ();

  closeGraph ();
}

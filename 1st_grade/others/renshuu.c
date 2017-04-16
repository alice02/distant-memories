/* プログラムの作成手順の練習 */
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

main (void)
{
	/* 準備 */
	initGraph ();

	waitButtonPress ();

	/* 中心(320,240)，半径200の青い円を描いてみよう */ 

	waitButtonPress ();

	/* 後始末 */
	closeGraph ();
}

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
  initGraph ();

  fillRectangle (0, 0, 640, 380, LIGHTBLUE);	/* 空   */
  fillTriangle (100, 340, 400, 340, 280, 480, GRAY);	/* 船体 */
  fillRectangle (0, 380, 640, 480, BLUE);	/* 海   */
  fillTriangle (190, 140, 350, 280, 190, 340, WHITE);	/* 帆   */
  fillCircle (490, 90, 60, YELLOW);	/* 太陽 */

  /* マウスのボタンが押されるのを待つ */
  waitButtonPress ();

  closeGraph ();
}

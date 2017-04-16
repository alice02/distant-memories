/* プログラムの例 ----- ハローキティー その 1 */

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

  /* 背景 */
  floodFill (320, 240, BLACK, LIGHTBLUE);
  waitButtonPress ();

  /* 頭 */
  fillEllipse (320, 240, 240, 180, WHITE);

  /* 耳 */
  fillEllipse (480, 140, 60, 80, WHITE);
  fillEllipse (160, 140, 60, 80, WHITE);
  waitButtonPress ();

  /* 目 */
  fillEllipse (200, 300, 15, 20, BLACK);
  fillEllipse (440, 300, 15, 20, BLACK);
  waitButtonPress ();

  /* 鼻 */
  fillEllipse (320, 340, 10, 14, YELLOW);
  setLineWidth (2);
  waitButtonPress ();

  /* ひげ */
  drawLine (125, 300, 40, 305, BLACK);
  drawLine (130, 320, 50, 330, BLACK);
  drawLine (140, 340, 40, 355, BLACK);

  drawLine (515, 300, 600, 305, BLACK);
  drawLine (510, 320, 590, 330, BLACK);
  drawLine (500, 340, 600, 355, BLACK);
  waitButtonPress ();

  /* リボン */
  fillTriangle (480, 160, 430, 70, 380, 160, RED);
  fillTriangle (480, 160, 530, 250, 580, 160, RED);
  fillCircle (480, 160, 20, RED);
  waitButtonPress ();

  closeGraph ();
}

/* プログラム例 ---- ドラえもん */

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

  /* マウスのボタンが押されるのを待つ */
  waitButtonPress ();


  setLineWidth (3);

  /* 口 */
  drawEllipse (320, 320, 140, 60, BLACK);
  fillRectangle (175, 250, 475, 330, WHITE);
  waitButtonPress ();

  /* 顔の外側 */
  drawEllipse (320, 240, 200, 180, BLACK);
  waitButtonPress ();

  /* 顔の内側 */
  drawEllipse (320, 280, 180, 140, BLACK);
  waitButtonPress ();

  /* 青い部分を塗る */
  floodFill (320, 70, BLACK, BLUE);
  waitButtonPress ();

  /* 目 */
  fillEllipse (270, 160, 50, 80, WHITE);
  fillEllipse (370, 160, 50, 80, WHITE);
  drawEllipse (270, 160, 50, 80, BLACK);
  drawEllipse (370, 160, 50, 80, BLACK);
  waitButtonPress ();

  /* 黒目 */
  fillCircle (300, 190, 10, BLACK);
  waitButtonPress ();
  fillCircle (340, 190, 10, BLACK);
  waitButtonPress ();

  /* 鼻 */
  fillCircle (320, 235, 20, RED);
  waitButtonPress ();

  /* 鼻の下 */
  drawLine (320, 255, 320, 340, BLACK);

  /* ひげ */
  drawLine (270, 270, 170, 255, BLACK);
  drawLine (270, 285, 160, 285, BLACK);
  drawLine (270, 300, 170, 315, BLACK);

  drawLine (370, 270, 470, 255, BLACK);
  drawLine (370, 285, 460, 285, BLACK);
  drawLine (370, 300, 470, 315, BLACK);

  waitButtonPress ();

  closeGraph ();
}

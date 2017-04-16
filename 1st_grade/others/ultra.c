/* グラフィックプログラムの例 ----- ウルトラマン */
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

	/***** ここから *****/

  /* 顔，目，目玉… を順番に描いていきます */
  kao ();
  me ();
  medama ();
  hana ();
  kuchi ();
  mimi ();

  /* 最後に ultra man と表示します */
  title ();

  /* マウスのボタンが押されるのを待つ */
  waitButtonPress ();

	/***** ここまで *****/

  closeGraph ();
}

kao (void)
{
  drawEllipse (320, 190, 120, 150, VIOLET);
  floodFill (320, 190, VIOLET, WHITE);
}

me (void)
{
  drawEllipse (255, 160, 40, 25, VIOLET);
  drawEllipse (385, 160, 40, 25, VIOLET);
  floodFill (270, 150, VIOLET, YELLOW);
  floodFill (380, 160, VIOLET, YELLOW);
}

medama (void)
{
  drawCircle (270, 170, 5, VIOLET);
  drawCircle (370, 170, 5, VIOLET);
  floodFill (270, 170, VIOLET, RED);
  floodFill (370, 170, VIOLET, RED);
}

hana (void)
{
  drawLine (320, 10, 340, 43, VIOLET);
  drawLine (320, 10, 300, 43, VIOLET);
  drawLine (340, 43, 320, 250, VIOLET);
  drawLine (300, 43, 320, 250, VIOLET);
  floodFill (320, 20, VIOLET, WHITE);
}

kuchi (void)
{
  drawLine (280, 260, 360, 260, VIOLET);
  drawLine (360, 260, 350, 290, VIOLET);
  drawLine (350, 290, 290, 290, VIOLET);
  drawLine (290, 290, 280, 260, VIOLET);
  floodFill (300, 270, VIOLET, GRAY);
}

mimi (void)
{
  drawLine (175, 160, 175, 220, VIOLET);
  drawLine (175, 220, 203, 225, VIOLET);
  drawLine (175, 160, 203, 155, VIOLET);
  drawLine (465, 160, 465, 220, VIOLET);
  drawLine (465, 220, 437, 225, VIOLET);
  drawLine (465, 160, 437, 155, VIOLET);
  floodFill (180, 200, VIOLET, WHITE);
  floodFill (460, 200, VIOLET, WHITE);
}

title (void)
{
  drawString (240, 400, "ultra man", GOLD);
}

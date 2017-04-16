/* 各関数の使い方の例を示します */
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

  /* 中心=(80,80)，半径=75，色=黒の円を描く */
  drawCircle (80, 80, 75, BLACK);
  waitButtonPress ();

  /* 中心=(240,80)，半径=75，色=青で円を塗りつぶす */
  fillCircle (240, 80, 75, BLUE);
  waitButtonPress ();

  /* 中心=(400,80)，X 径=75，Y 径=50，色=茶の楕円を描く */
  drawEllipse (400, 80, 75, 50, BROWN);
  waitButtonPress ();

  /* 中心=(560,80)，X 径=50，Y 径=75，色=金の楕円を描く */
  fillEllipse (560, 80, 50, 75, GOLD);
  waitButtonPress ();

  /* (5,165) と (155,315) を結ぶ，色=灰の線を描く */
  drawLine (5, 165, 155, 315, GRAY);
  waitButtonPress ();

  /* (240,165)，(165,315)，（315,315) を頂点とする，色=緑の三角形を描く */
  drawTriangle (240, 165, 165, 315, 315, 315, GREEN);
  waitButtonPress ();

  /* (400,165)，(325,315)，（475,315) を頂点とする三角形を */
  /* 色=ライトブルーで塗りつぶす                                                   */
  fillTriangle (400, 165, 325, 315, 475, 315, LIGHTBLUE);
  waitButtonPress ();

  /* (485,180)，(635,300）を頂点とする，色=ライトグレーの長方形を描く */
  drawRectangle (485, 180, 635, 300, LIGHTGRAY);
  waitButtonPress ();

  /* (20,325)，(140,475）を頂点とする長方形を     */
  /* 色=ライトグリーンで塗りつぶす                */
  fillRectangle (20, 325, 140, 475, LIGHTGREEN);
  waitButtonPress ();

  /* 四角形と円を，色=ピンクで描いておいて... */
  drawRectangle (180, 340, 300, 460, PINK);
  waitButtonPress ();
  drawCircle (240, 400, 70, PINK);
  waitButtonPress ();

  /* 二つの図形に囲まれた領域を，色=紫で塗りつぶす */
  floodFill (240, 400, PINK, PURPLE);
  waitButtonPress ();

  /* 太さ 2 の線を描く */
  setLineWidth (2);
  drawLine (325, 360, 475, 360, RED);
  waitButtonPress ();

  /* 太さ 4 の線を描く */
  setLineWidth (4);
  drawLine (325, 400, 475, 400, VIOLET);
  waitButtonPress ();

  /* 太さ 8 の線を描く */
  setLineWidth (8);
  drawLine (325, 440, 475, 440, YELLOW);
  waitButtonPress ();

  /* 左上の座標=(535,410) の位置に，色=黒で END の文字を描く */
  /* 表示したい文字を "" で囲むことに注意！                  */
  drawString (535, 410, "END", BLACK);
  waitButtonPress ();

  closeGraph ();
}

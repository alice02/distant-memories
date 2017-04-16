/* プログラム例---でたらめに円を描く */

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
  int x, y, r, c, i;		/* これらの変数を使うことを宣言する */

  initGraph ();

  i = 0;			/* 下準備 */
  /* { } で囲まれた部分の処理を 200 回繰り返す */
  while (i < 200)
    {
      x = rand () % 640;	/* x 座標に 0〜639 のでたらめな数を代入 */
      y = rand () % 480;	/* y 座標に 0〜479 のでたらめな数を代入 */
      r = rand () % 60;		/* 半径 r に 0〜60 のでたらめな数を代入 */
      c = rand () % (15);	/* 色 cに 0〜15 のでたらめな数を代入    */
      fillCircle (x, y, r, c);	/* 円を描く                             */
      flush ();			/* 画面を最新の状態に書き換える         */
      usleep (50000);		/* 50000 マイクロ秒=0.05 秒待つ         */
      i = i + 1;
    }

  /* マウスのボタンが押されるのを待つ */
  waitButtonPress ();

  closeGraph ();
}

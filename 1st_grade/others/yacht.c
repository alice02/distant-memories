#include	"graph.h"

/*
���� ������ ����
BLACK		BLUE		BROWN		GOLD		GRAY
GREEN		LIGHTBLUE	LIGHTGRAY	LIGHTGREEN	PINK
PURPLE		RED		VIOLET		WHITE		YELLOW

���� ̿����� ����
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

  fillRectangle (0, 0, 640, 380, LIGHTBLUE);	/* ��   */
  fillTriangle (100, 340, 400, 340, 280, 480, GRAY);	/* ���� */
  fillRectangle (0, 380, 640, 480, BLUE);	/* ��   */
  fillTriangle (190, 140, 350, 280, 190, 340, WHITE);	/* ��   */
  fillCircle (490, 90, 60, YELLOW);	/* ���� */

  /* �ޥ����Υܥ��󤬲������Τ��Ԥ� */
  waitButtonPress ();

  closeGraph ();
}

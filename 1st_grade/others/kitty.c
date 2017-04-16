/* �ץ������� ----- �ϥ����ƥ��� ���� 1 */

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

  /* �ط� */
  floodFill (320, 240, BLACK, LIGHTBLUE);
  waitButtonPress ();

  /* Ƭ */
  fillEllipse (320, 240, 240, 180, WHITE);

  /* �� */
  fillEllipse (480, 140, 60, 80, WHITE);
  fillEllipse (160, 140, 60, 80, WHITE);
  waitButtonPress ();

  /* �� */
  fillEllipse (200, 300, 15, 20, BLACK);
  fillEllipse (440, 300, 15, 20, BLACK);
  waitButtonPress ();

  /* ɡ */
  fillEllipse (320, 340, 10, 14, YELLOW);
  setLineWidth (2);
  waitButtonPress ();

  /* �Ҥ� */
  drawLine (125, 300, 40, 305, BLACK);
  drawLine (130, 320, 50, 330, BLACK);
  drawLine (140, 340, 40, 355, BLACK);

  drawLine (515, 300, 600, 305, BLACK);
  drawLine (510, 320, 590, 330, BLACK);
  drawLine (500, 340, 600, 355, BLACK);
  waitButtonPress ();

  /* ��ܥ� */
  fillTriangle (480, 160, 430, 70, 380, 160, RED);
  fillTriangle (480, 160, 530, 250, 580, 160, RED);
  fillCircle (480, 160, 20, RED);
  waitButtonPress ();

  closeGraph ();
}

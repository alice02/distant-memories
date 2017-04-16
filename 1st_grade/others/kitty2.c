/* �ץ������� ----- �ϥ����ƥ��� ���� 2 */

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
  fillEllipse (320, 250, 230, 160, WHITE);

  /* �� */
  fillTriangle (130, 40, 90, 250, 250, 92, WHITE);
  fillTriangle (530, 40, 530, 250, 390, 92, WHITE);
  waitButtonPress ();

  /* �� */
  fillEllipse (200, 290, 15, 20, BLACK);
  fillEllipse (195, 282, 8, 6, WHITE);
  fillEllipse (440, 290, 15, 20, BLACK);
  fillEllipse (435, 282, 8, 6, WHITE);
  waitButtonPress ();

  /* ɡ */
  fillEllipse (320, 330, 24, 15, YELLOW);
  fillEllipse (315, 322, 9, 6, WHITE);
  waitButtonPress ();

  /* �Ҥ� */
  drawLine (125, 280, 40, 275, BLACK);
  drawLine (130, 300, 50, 305, BLACK);
  drawLine (140, 320, 40, 335, BLACK);

  drawLine (515, 280, 600, 275, BLACK);
  drawLine (510, 300, 590, 305, BLACK);
  drawLine (500, 320, 600, 335, BLACK);
  waitButtonPress ();

  /* ��ܥ� */
  fillTriangle (465, 160, 415, 70, 365, 160, RED);
  fillTriangle (465, 160, 515, 250, 565, 160, RED);
  fillCircle (465, 160, 20, RED);
  waitButtonPress ();

  closeGraph ();
}

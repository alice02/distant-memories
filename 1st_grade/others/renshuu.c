/* �ץ����κ����������� */
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
	/* ���� */
	initGraph ();

	waitButtonPress ();

	/* �濴(320,240)��Ⱦ��200���Ĥ��ߤ������Ƥߤ褦 */ 

	waitButtonPress ();

	/* ����� */
	closeGraph ();
}

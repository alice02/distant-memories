/* �ץ������---�Ǥ����˱ߤ����� */

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
  int x, y, r, c, i;		/* �������ѿ���Ȥ����Ȥ�������� */

  initGraph ();

  i = 0;			/* ������ */
  /* { } �ǰϤޤ줿��ʬ�ν����� 200 �󷫤��֤� */
  while (i < 200)
    {
      x = rand () % 640;	/* x ��ɸ�� 0��639 �ΤǤ����ʿ������� */
      y = rand () % 480;	/* y ��ɸ�� 0��479 �ΤǤ����ʿ������� */
      r = rand () % 60;		/* Ⱦ�� r �� 0��60 �ΤǤ����ʿ������� */
      c = rand () % (15);	/* �� c�� 0��15 �ΤǤ����ʿ�������    */
      fillCircle (x, y, r, c);	/* �ߤ�����                             */
      flush ();			/* ���̤�ǿ��ξ��֤˽񤭴�����         */
      usleep (50000);		/* 50000 �ޥ�������=0.05 ���Ԥ�         */
      i = i + 1;
    }

  /* �ޥ����Υܥ��󤬲������Τ��Ԥ� */
  waitButtonPress ();

  closeGraph ();
}

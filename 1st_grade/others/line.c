/* ���֤��Ⱦ��Ƚ����Ѥ���,�����������������ץ������� */

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

/*
	�� (0,0) ������ (x,480) ���������.
	������,x �Ϻǽ� 0 �� 30,60,90,��,640 ��,640 �ޤ� 30 ����
	�礭���ʤäƤ椯.
	�Ĥޤ�����
 
		(0,0)����(0,480)
		(0,0)����(30,480)
		(0,0)����(60,480)
		��
		(0,0)����(640,480)

	�Τ褦�˲��ܤ�������.
	���ο��Ϻǽ��Ⱦʬ(x �� 320 ̤���δ�)�ϻ�,
	�Ĥ��Ⱦʬ(x �� 320 ����礭���ͤΤȤ�)�ϲ����Ȥ���.
*/

main (void)
{
  int x;			/* �������ѿ�vx ��Ȥ����Ȥ�������� */

  initGraph ();

  /* �������Ȥ��� x �� 0 �ˤ��� */
  x = 0;
  while (x <= 640)
    {
      if (x < 320)
	{
	  drawLine (0, 0, x, 480, YELLOW);
	}
      else
	{
	  drawLine (0, 0, x, 480, PURPLE);
	}
      x = x + 30;		/* x �� 30 ��ä��Ƽ��� x ��������� */
    }

  /* �ޥ����Υܥ��󤬲������Τ��Ԥ� */
  waitButtonPress ();

  closeGraph ();
}

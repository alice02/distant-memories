/* �ƴؿ��λȤ�������򼨤��ޤ� */
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

  /* �ޥ����Υܥ��󤬲������Τ��Ԥ� */
  waitButtonPress ();

  /* �濴=(80,80)��Ⱦ��=75����=���αߤ����� */
  drawCircle (80, 80, 75, BLACK);
  waitButtonPress ();

  /* �濴=(240,80)��Ⱦ��=75����=�ĤǱߤ��ɤ�Ĥ֤� */
  fillCircle (240, 80, 75, BLUE);
  waitButtonPress ();

  /* �濴=(400,80)��X ��=75��Y ��=50����=����ʱߤ����� */
  drawEllipse (400, 80, 75, 50, BROWN);
  waitButtonPress ();

  /* �濴=(560,80)��X ��=50��Y ��=75����=����ʱߤ����� */
  fillEllipse (560, 80, 50, 75, GOLD);
  waitButtonPress ();

  /* (5,165) �� (155,315) ���֡���=������������ */
  drawLine (5, 165, 155, 315, GRAY);
  waitButtonPress ();

  /* (240,165)��(165,315)����315,315) ��ĺ���Ȥ��롤��=�Фλ��ѷ������� */
  drawTriangle (240, 165, 165, 315, 315, 315, GREEN);
  waitButtonPress ();

  /* (400,165)��(325,315)����475,315) ��ĺ���Ȥ��뻰�ѷ��� */
  /* ��=�饤�ȥ֥롼���ɤ�Ĥ֤�                                                   */
  fillTriangle (400, 165, 325, 315, 475, 315, LIGHTBLUE);
  waitButtonPress ();

  /* (485,180)��(635,300�ˤ�ĺ���Ȥ��롤��=�饤�ȥ��졼��Ĺ���������� */
  drawRectangle (485, 180, 635, 300, LIGHTGRAY);
  waitButtonPress ();

  /* (20,325)��(140,475�ˤ�ĺ���Ȥ���Ĺ������     */
  /* ��=�饤�ȥ��꡼����ɤ�Ĥ֤�                */
  fillRectangle (20, 325, 140, 475, LIGHTGREEN);
  waitButtonPress ();

  /* �ͳѷ��ȱߤ򡤿�=�ԥ󥯤������Ƥ�����... */
  drawRectangle (180, 340, 300, 460, PINK);
  waitButtonPress ();
  drawCircle (240, 400, 70, PINK);
  waitButtonPress ();

  /* ��Ĥο޷��˰Ϥޤ줿�ΰ�򡤿�=����ɤ�Ĥ֤� */
  floodFill (240, 400, PINK, PURPLE);
  waitButtonPress ();

  /* ���� 2 ���������� */
  setLineWidth (2);
  drawLine (325, 360, 475, 360, RED);
  waitButtonPress ();

  /* ���� 4 ���������� */
  setLineWidth (4);
  drawLine (325, 400, 475, 400, VIOLET);
  waitButtonPress ();

  /* ���� 8 ���������� */
  setLineWidth (8);
  drawLine (325, 440, 475, 440, YELLOW);
  waitButtonPress ();

  /* ����κ�ɸ=(535,410) �ΰ��֤ˡ���=���� END ��ʸ�������� */
  /* ɽ��������ʸ���� "" �ǰϤळ�Ȥ���ա�                  */
  drawString (535, 410, "END", BLACK);
  waitButtonPress ();

  closeGraph ();
}

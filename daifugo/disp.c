/*
  FILE NAME: disp.c

  DESCRIPTION:
  ����ɽ���˴ؤ���ؿ�
*/


#include "daifugo.h"


// �����ץ˥󥰥�å�����
void opening(void)
{
  printf(CLEAR_DISPLAY);
  printf("\n\n");

  printf(BOLD);
  printf("               ****************************************\n");
  printf("               *                                      *\n");
  printf("               *             ");
  printf("��  ��  ��");
  printf("               *\n");
  printf("               *                                      *\n");
  printf("               ****************************************\n");
  printf(CLEAR_ATTRIBUTE);

  printf("\n\n");
  printf("���������򲡤��ȥ�������!!\n");
  getchar();
}



// �ե�����ɤ�ɽ��
void disp_field(PLAYER_DATA *player, CARD_DATA *field, int num, int turn, int field_status)
{
  int i;
  char word[PLAYER_NUM][10];

  // player[?].rank�ˤ�äơ�ɽ�����볬������
  for (i = 0; i < PLAYER_NUM; i++) {
    if (player[i].status == END) {
      switch (player[i].new_rank) {
      case HEIMIN:
		strcpy(word[i], "  ʿ̱  ");
		break;
      case DAIFUGO:
		strcpy(word[i], " ���ٹ� ");
		break;
      case FUGO:
		strcpy(word[i], "  �ٹ�  ");
		break;
      case HINMIN:
		strcpy(word[i], "  ��̱  ");
		break;
      case DAIHINMIN:
		strcpy(word[i], " ����̱ ");
		break;
      }
    }
    else {
      switch (player[i].old_rank) {
      case HEIMIN:
		strcpy(word[i], "  ʿ̱  ");
		break;
      case DAIFUGO:
		strcpy(word[i], " ���ٹ� ");
		break;
      case FUGO:
		strcpy(word[i], "  �ٹ�  ");
		break;
      case HINMIN:
		strcpy(word[i], "  ��̱  ");
		break;
      case DAIHINMIN:
		strcpy(word[i], " ����̱ ");
		break;
      }
    }
  }
  printf("\n");


  // �������鲼�ϥե�����ɤξ��ɽ��������Ĥ˴ؤ��뵭��
  // (�����襨�������ץ������󥹤����Ѥˤ����...)

  /* ����ɽ�� */
  printf("\x1b[1A");
  printf("\x1b[6C");
  for (i = 0; i < turn; i++) {
    printf("\x1b[17C");
  }
  printf("��");
  printf("\x1b[500C");
  printf("\n");

  printf("+------------+   +------------+   +------------+   +------------+\n");
  printf("|            |   |            |   |            |   |            |\n");
  printf("|  PLAYER-0  |   |  PLAYER-1  |   |  PLAYER-2  |   |  PLAYER-3  |\n");
  printf("|            |   |            |   |            |   |            |\n");
  printf("| |��|       |   | |��|       |   | |��|       |   | |��|       |\n");
  printf("| |  | �� %2d |   | |  | �� %2d |   | |  | �� %2d |   | |  | �� %2d |\n", player->card_num, (player+1)->card_num, (player+2)->card_num, (player+3)->card_num);
  printf("|  ��        |   |  ��        |   |  ��        |   |  ��        |\n");
  printf("|  ");
  if (player[0].status == END) {
    printf(RED);
  }
  printf("%s", word[0]);
  printf(DEFAULT_COLOR);
  printf("  |   |  ");
  if (player[1].status == END) {
    printf(RED);
  }
  printf("%s", word[1]);
  printf(DEFAULT_COLOR);
  printf("  |   |  ");
  if (player[2].status == END) {
    printf(RED);
  }
  printf("%s", word[2]);
  printf(DEFAULT_COLOR);
  printf("  |   |  ");
  if (player[3].status == END) {
    printf(RED);
  }
  printf("%s", word[3]);
  printf(DEFAULT_COLOR);
  printf("  |\n");
  printf("+------------+   +------------+   +------------+   +------------+\n");


  if (field_status == KAKUMEI) {
	printf(RED);
	printf(HANTEN);
	printf("                         ��̿�ʤ�����                            \n");
	printf(CLEAR_ATTRIBUTE);
	printf(DEFAULT_COLOR);
  }
  else {
	printf("\n");
  }

  //   ---------------------------
  //   *  PLAYER-? :             *   ��ɽ��
  //   ---------------------------

  printf(BLUE);
  printf("                   ---------------------------\n");
  printf("                   *  PLAYER-%d :             *\n", turn);
  printf("                   ---------------------------\n\n");
  printf(DEFAULT_COLOR);


  // �ե�����ɤ�ɽ��

  printf("\x1b[20C");
  for (i = 0; i < num; i++) {
    printf("+---+  ");
  }
  printf("\n");

  printf("\x1b[20C");
  for (i = 0; i < num; i++) {
	if (field[i].i_mark == 0) {
	  printf("|");
	  printf(BOLD);
	  printf("%c", field[i].c_mark);
	  printf(CLEAR_ATTRIBUTE);
	  printf("  |  ");
	}
	else {
	  printf("|%c  |  ",  field[i].c_mark);
	}
  }
  printf("\n");

  printf("\x1b[20C");
  for (i = 0; i < num; i++) {
	if (field[i].i_mark == 0) {
	  printf("|");
	  printf(BOLD);
	  printf("%3c",  field[i].c_num[0]);
	  printf(CLEAR_ATTRIBUTE);
	  printf("|  ");
	}else {
	  if(field[i].c_num[1] == '0'){
		printf("|%3s|  ",  field[i].c_num);
	  }
	  else{
		printf("|%3c|  ",  field[i].c_num[0]);
	  }
	}
  }
  printf("\n");

  printf("\x1b[20C");
  for (i = 0; i < num; i++) {
    printf("+---+  ");
  }
  printf("\n");

}



/// �����μ껥��ɽ��(�����С�����)
void disp_card_all(PLAYER_DATA *player)
{
  int i, j;

  for (i = 0; i < PLAYER_NUM; i++) {
    printf("player[%d]: \n", i);

    for (j = 0; j < player[i].card_num; j++) {
      printf(" %2d   ", j+1);
    }
    printf("\n");

    for (j = 0; j < player[i].card_num; j++) {
      printf("+---+ ");
    }
    printf("\n");

    for (j = 0; j < player[i].card_num; j++) {
      printf("|%c  | ",  player[i].card[j].c_mark);
    }
    printf("\n");

    /*    for (j = 0; j < player[i].card_num; j++) {
      printf("|   | ");
    }
    printf("\n");
    */
    for (j = 0; j < player[i].card_num; j++) {
      if(player[i].card[j].c_num[1] == '0'){
	printf("|%3s| ",  player[i].card[j].c_num);
      }
      else{
	printf("|%3c| ",  player[i].card[j].c_num[0]);
      }
    }
    printf("\n");

    for (j = 0; j < player[i].card_num; j++) {
      printf("+---+ ");
    }
    printf("\n");
  }
}



/* ��ʬ�μ껥����ɽ��(���饤����ȸ���) */
void disp_my_card(PLAYER_DATA *player)
{
  int i, j;

  printf("\n\n���������������������������� YOUR CARDS ����������������������������\n");
  printf("[A][D][SPACE]:����  [ENTER]:����   (��:�������򤷤ʤ��ȥѥ�)\n\n");

  for (j = 0; j < player->card_num; j++) {
    printf("+---+ ");
  }
  printf("\n");

  for (j = 0; j < player->card_num; j++) {
	if (player->card[j].i_mark == 0) {
	  printf("|");
	  printf(BOLD);
	  printf("%c", player->card[j].c_mark);
	  printf(CLEAR_ATTRIBUTE);
	  printf("  | ");
	}
	else if (player->card[j].i_mark == 3 || player->card[j].i_mark == 2) {
	  printf("|");
	  printf(RED);
	  printf("%c", player->card[j].c_mark);
	  printf(DEFAULT_COLOR);
	  printf("  | ");
	}
	else {
	  printf("|%c  | ",  player->card[j].c_mark);
	}
  }
  printf("\n");

  for (j = 0; j < player->card_num; j++) {
	if (player->card[j].i_mark == 0) {
	  printf("|");
	  printf(BOLD);
	  printf("%3c",  player->card[j].c_num[0]);
	  printf(CLEAR_ATTRIBUTE);
	  printf("| ");
	}
	else if (player->card[j].i_mark == 3 || player->card[j].i_mark == 2) {
	  if(player->card[j].c_num[1] == '0'){
		printf("|");
		printf(RED);
		printf("%3s", player->card[j].c_num);
		printf(DEFAULT_COLOR);
		printf("| ");
	  }
	  else{
		printf("|");
		printf(RED);
		printf("%3c", player->card[j].c_num[0]);
		printf(DEFAULT_COLOR);
		printf("| ");
	  }
	}
	else {
	  if(player->card[j].c_num[1] == '0'){
		printf("|%3s| ",  player->card[j].c_num);
	  }
	  else{
		printf("|%3c| ",  player->card[j].c_num[0]);
	  }
	}
  }
  printf("\n");

  for (j = 0; j < player->card_num; j++) {
    printf("+---+ ");
  }
  printf("\n");

}



// ����η�̤�ɽ��
void disp_result(PLAYER_DATA *player)
{
  int i, j;
  char *rank[] =  {"���ٹ�", " �ٹ� ", " ��̱ ", "����̱"};
  char *point[] = {"  +2  ", "  +1  ", "  +0  ", "  -1  "};
  int pointer[PLAYER_NUM];


  // player[?].rank�ˤ�ä�ɽ������ʸ��������
  for (i = 0; i < PLAYER_NUM; i++) {
    switch (player[i].new_rank) {
    case DAIFUGO:
      pointer[i] = 0;
      break;
    case FUGO:
      pointer[i] = 1;
      break;
    case HINMIN:
      pointer[i] = 2;
      break;
    case DAIHINMIN:
      pointer[i] = 3;
      break;
    }
  }

  // �ֽ�λ�����ץ�å�������500[ms]ɽ��
  printf("\n\n��λ����\n\n");
  usleep(500000);


  // ��̤�ɽ��
  printf(CLEAR_DISPLAY);
  printf("����������������������������   ���   ����������������������������\n\n");
  printf("+------------+   +------------+   +------------+   +------------+\n");
  printf("|            |   |            |   |            |   |            |\n");
  printf("|  PLAYER-0  |   |  PLAYER-1  |   |  PLAYER-2  |   |  PLAYER-3  |\n");
  printf("|            |   |            |   |            |   |            |\n");
  printf("|   %s   |   |   %s   |   |   %s   |   |   %s   |\n", rank[pointer[0]], rank[pointer[1]], rank[pointer[2]], rank[pointer[3]]);
  printf("|   %s   |   |   %s   |   |   %s   |   |   %s   |\n", point[pointer[0]], point[pointer[1]], point[pointer[2]], point[pointer[3]]);
  printf("|            |   |            |   |            |   |            |\n");
  printf("|  �߷�:%2dP  |   |  �߷�:%2dP  |   |  �߷�:%2dP  |   |  �߷�:%2dP  |\n", player[0].point, player[1].point, player[2].point, player[3].point);
  printf("|            |   |            |   |            |   |            |\n");
  printf("+------------+   +------------+   +------------+   +------------+\n\n");
  printf("������������������������������������������������������������������\n\n");

  // 3�ôַ�̤�ɽ�����Ƥ���
  sleep(3);

  printf(CLEAR_DISPLAY);
}



// "ALL Players PASS!!!"��ɽ��
void disp_all_pass_message(void)
{
  /* ����������֤��碌�� */
  printf("\x1b[16A");
  printf("\x1b[22C");
  printf(MAGENTA);
  printf("All Players PASS!!!");
  printf(DEFAULT_COLOR);
  fflush(NULL);
  sleep(1);
}



// "PASS"��ɽ��
void disp_pass_message(void)
{
  /* ����������֤��碌�� */
  printf("\x1b[16A");
  printf("\x1b[1000D");
  printf("\x1b[33C");
  printf(BLUE);  /* �Ĥˤ��� */
  printf("PASS");
  printf(DEFAULT_COLOR);   /* �ǥե���ȥ��顼���᤹ */
  fflush(NULL);
  sleep(1);	   /* 1[s]ɽ�����Ƥ��� */
}



// "8�ڤ�!!"��ɽ��
void disp_yagiri_message(void)
{
  /* ����������֤��碌�� */
  printf("\x1b[16A");
  printf("\x1b[1000D");
  printf("\x1b[33C");
  printf(CYAN);		   /* ������ˤ��� */
  printf("8�ڤ�!!");
  printf(DEFAULT_COLOR);   /* �ǥե���ȥ��顼���᤹ */
  fflush(NULL);
  sleep(1);	   /* 1[s]ɽ�����Ƥ��� */
}



// "��̿!!!"��ɽ��
void disp_kakumei_message(void)
{
  /* ����������֤��碌�� */
  printf("\x1b[16A");
  printf("\x1b[1000D");
  printf("\x1b[33C");
  printf(CYAN);		   /* ������ˤ��� */
  printf("��̿!!!");
  printf(DEFAULT_COLOR);   /* �ǥե���ȥ��顼���᤹ */
  fflush(NULL);
  sleep(1);	   /* 1[s]ɽ�����Ƥ��� */
}

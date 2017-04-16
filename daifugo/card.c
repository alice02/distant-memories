/*
  FILE NAME: card.c

  DESCRIPTION:
  ���������˴ؤ���ؿ�
*/


#include "daifugo.h"


// �����ɤ�ʬ�ۤ���
void distribute_card(PLAYER_DATA *player)
{
  CARD_DATA card[MAX_CARD_NUM];   	// �����ɤΥǡ��� 
  char c_mark_table[] = {'S', 'H', 'D', 'C', 'J'};
  int i_mark_table[] =  { 1 ,  2 ,  3 ,  4 ,  0 };
  char c_num_table[][3] = {"A ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "Q ", "K "};
  int i_num_table[] =     { 2  ,  1  ,  13 ,  12 ,  11 ,  10 ,  9  ,  8  ,  7  ,  6  ,  5  ,  4  ,  3  };
  int rand_table[PLAYER_NUM];
  int rand_table_card[MAX_CARD_NUM];
  int i, j, count;
  int tmp1, tmp2, val1, val2;

  // ����μ�����
  srand((unsigned)time(NULL));

  for (i = 0; i < MAX_CARD_NUM; i++) {
	// �����ɤ򥻥å�
    card[i].c_mark = c_mark_table[i/MAX_MARK_NUM];
    card[i].i_mark = i_mark_table[i/MAX_MARK_NUM];
    if (i < MAX_CARD_NUM - 2) {
      strcpy(card[i].c_num, c_num_table[i%MAX_MARK_NUM]);
      card[i].i_num = i_num_table[i%MAX_MARK_NUM];
    }
    // ���硼���������̤�
    else {
      strcpy(card[i].c_num, "K ");
      card[i].i_num = 0;
    }

	// ��å����åץơ��֥�ν����
    rand_table_card[i] = i;
  }

  // �ץ쥤�䤬������Ƥ��륫���ɤ����������
  for (i = 0; i < PLAYER_NUM; i++) {
    player[i].card_num = 0;
  }

  // ��������¤��ؤ���
  j = MAX_CARD_NUM;
  count = 0;
  while (count < MAX_CARD_NUM) {
    // ��å����åץơ��֥�ν����
    for (i = 0; i < PLAYER_NUM; i++) {
      rand_table[i] = i;
    }
    // ��ʣ��̵���褦�˥�������¤��ؤ�
    for (i = PLAYER_NUM; i > 0 && count < MAX_CARD_NUM; i--) {
      tmp1 = rand() % i;
      val1 = rand_table[tmp1];
      tmp2 = rand() % j;
      val2 = rand_table_card[tmp2];
      // �������3����äƤ�ͤ�Ф��Ƥ���
      if (card[val2].c_mark == 'D' && strcmp(card[val2].c_num, "3 ") == 0) {
		player[val1].rule_flag = DIA3;
      }
      player[val1].card[player[val1].card_num] = card[val2];
      player[val1].card_num++;
      rand_table[tmp1] = rand_table[i-1];
      rand_table_card[tmp2] = rand_table_card[j-1];
      count++;
      j--;
    }
  }

}



// �����ɤ򥽡��Ȥ���(3��2,(JK)��S��H��D��C) 
void sort_card(PLAYER_DATA *player, int no)
{
  CARD_DATA card_tmp;
  int i, j, k;

  // ���٤ƤΥץ쥤��μ껥�򥽡��� 
  if (no == ALL_PLAYERS) {
    for (i = 0; i < PLAYER_NUM; i++) {
      for(j = 0; j < player[i].card_num-1; j++){
		for(k = player[i].card_num-1; k > j; k--) {
		  if(player[i].card[k].i_mark < player[i].card[k-1].i_mark){
			card_tmp = player[i].card[k];
			player[i].card[k] = player[i].card[k-1];
			player[i].card[k-1] = card_tmp;
		  }
		  if(player[i].card[k].i_num > player[i].card[k-1].i_num){
			card_tmp = player[i].card[k];
			player[i].card[k] = player[i].card[k-1];
			player[i].card[k-1] = card_tmp;
		  }
		}
      }
    }
  }
  // ���ꤷ���ץ쥤��μ껥�򥽡��� 
  else {
    for(j = 0; j < player[no].card_num-1; j++){
      for(k = player[no].card_num-1; k > j; k--) {
		if(player[no].card[k].i_mark < player[no].card[k-1].i_mark){
		  card_tmp = player[no].card[k];
		  player[no].card[k] = player[no].card[k-1];
		  player[no].card[k-1] = card_tmp;
		}
		if(player[no].card[k].i_num > player[no].card[k-1].i_num){
		  card_tmp = player[no].card[k];
		  player[no].card[k] = player[no].card[k-1];
		  player[no].card[k-1] = card_tmp;
		}
      }
    }

  }

}



// �����ɤ����򤵤��� 
int select_card(PLAYER_DATA *player, CARD_DATA select[])
{
  int pointer[MAX_PLAYER_CARD] = {FALSE};	// ���ͤϤ����˰��Ū�˳�Ǽ����� 
  char ch;
  int position_x;
  int count, num, flag;
  int i, j;

  flag = FALSE;
  count = 0;
  position_x = 1;


  // ɽ���ν���� 
  printf("\x1b[2000D");
  printf("\x1b[K");
  printf("\x1b[5A");
  printf("\x1b[2000D");
  printf("\x1b[K");
  printf("\x1b[5B");
  printf("\x1b[2000D");


  printf(" ��");		// ����ɽ�� 
  printf("\x1b[1000C");		// �����������ֱ���(1000�Ϥ���ޤ������ʤ���) 

  do {
    ch = getChar();
    switch(ch) {
    case 'd':      // ���򱦤�ư���� 
      if (position_x < player->card_num) {
		printf("\x1b[2000D");	// �����������ֺ��� 
		printf("\x1b[K");	// ��Ժ�� 
		// ���ֹ�碌 
		for (i = 1; i <= position_x; i++) {
		  printf("      ");
		}
		printf(" ��");
		printf("\x1b[1000C");	// �����������ֱ��� 
		position_x++;		// �ݥ������+1 
      }
      break;

    case 'a':      // ���򺸤�ư���� 
      if (position_x > 1) {
		printf("\x1b[2000D");	// �����������ֺ��� 
		printf("\x1b[K");	// ��Ժ�� 
		// ���ֹ�碌 
		for (i = 1; i < position_x-1; i++) {
		  printf("      ");
		}
		printf(" ��");
		printf("\x1b[1000C");	// �����������ֱ��� 
		position_x--;		// �ݥ������-1 
      }
      break;

    case ' ':        // ���ΤȤ���Υ����ɤ����� 
      if (pointer[position_x-1] == FALSE) {
		pointer[position_x-1] = TRUE; // ����Ĥ��� 
		count++;
      }
      else {
		pointer[position_x-1] = FALSE; // ����ä� 
		count--;
      }
      printf("\x1b[5A");
      printf("\x1b[2000D");
      printf("\x1b[K");
      for (i = 0; i < player->card_num; i++) {
		if (pointer[i] == TRUE) {
		  printf(" ��");
		}
		else {
		  printf("   ");
		}
		printf("   ");
      }
      // ��������ΰ��ֹ�碌 
      printf("\x1b[5B");
      printf("\x1b[1000C");
      break;

    case '\n':	      // ����λ 
      flag = TRUE;
      break;

    default:
      break;
    }
  } while(flag == FALSE);


  // ���򤷤������ɤ򥳥ԡ� 
  num = 0;
  for (i = 0; i < player->card_num; i++) {
    if (pointer[i] == TRUE) {
      select[num] = player->card[i];
      num++;
    }
  }

  return count;
}



// �ե�����ɤ˽Ф��������ɤ�껥������ 
void delete_used_card(PLAYER_DATA *player, CARD_DATA select[])
{
  int i, j, k;

  for (i = 0; select[i].i_mark != EMPTY; i++) {
    for (j = 0; j < player->card_num; j++) {
      if (player->card[j].c_mark == select[i].c_mark
		  && strcmp(player->card[j].c_num, select[i].c_num) == 0) {
		// �����ǤŤĤ��餷�Ƥ��� 
		for (k = j; k < player->card_num - 1; k++) {
		  player->card[k] = player->card[k+1];
		}
		// ������Υ���������򸺤餹 
		(player->card_num)--;
      }
    }
  }

}



// �����ɸ� 
/*
void change_card(PLAYER_DATA *player, int player_no)
{
  
  CARD_DATA select[MAX_FIELD_CARD+1] = { EMPTY };     // ���򤷤������� 
  int num, No;

  printf("player_no = %d\n",player_no);
  switch(player[player_no].rank) {
  case DAIFUGO:
    printf("3\n");
    No = get_rank_to_playerNo(player, DAIHINMIN);
    printf("4\n");
    do {
      printf(CLEAR_DISPLAY);
      printf("���פʥ����ɤ��硢����̱(PLAYER-%d)���Ϥ��Ƥ���������", No);
      disp_my_card(&player[player_no]); // �ץ쥤��μ껥��ɽ�� 
      init_select_card(select);
      num = select_card(&player[player_no], select); // �����ɤ����򤵤��� 
    } while (num != 2);
    send_card(&player[No], select);
    delete_used_card(&player[player_no], select); // �껥������ 
    break;
  case FUGO:
    No = get_rank_to_playerNo(player, HINMIN);
    do {
      printf(CLEAR_DISPLAY);
      printf("���פʥ����ɤ��硢��̱(PLAYER-%d)���Ϥ��Ƥ���������", No);
      disp_my_card(&player[player_no]); // �ץ쥤��μ껥��ɽ�� 
      init_select_card(select);
      num = select_card(&player[player_no], select); // �����ɤ����򤵤��� 
      printf("\n");
    } while (num != 1);
    send_card(&player[No], select);
    delete_used_card(&player[player_no], select); // �껥������ 
    break;
  case HINMIN:
    No = get_rank_to_playerNo(player, FUGO);
    init_select_card(select);
    printf("���ֶ��������ɤ��硢�ٹ�(PLAYER-%d)���Ϥ��ޤ���", No);
    disp_my_card(&player[player_no]); // �ץ쥤��μ껥��ɽ�� 
    select[0] = player[player_no].card[player[player_no].card_num-1];
    send_card(&player[No], select);
    delete_used_card(&player[player_no], select); // �껥������ 
    fflush(NULL);
    sleep(1);
    printf(CLEAR_DISPLAY);
    disp_my_card(&player[player_no]); // �ץ쥤��μ껥��ɽ�� 
    fflush(NULL);
    sleep(1);
    break;
  case DAIHINMIN:
    No = get_rank_to_playerNo(player, DAIFUGO);
    init_select_card(select);
    printf("�夫���˶��������ɤ��硢���ٹ�(PLAYER-%d)���Ϥ��ޤ���", No);
    disp_my_card(&player[player_no]); // �ץ쥤��μ껥��ɽ�� 
    select[0] = player[player_no].card[player[player_no].card_num-1];
    select[1] = player[player_no].card[player[player_no].card_num-2];
    send_card(&player[No], select);
    delete_used_card(&player[player_no], select); // �껥������ 
    fflush(NULL);
    sleep(1);
    printf(CLEAR_DISPLAY);
    disp_my_card(&player[player_no]); // �ץ쥤��μ껥��ɽ�� 
    fflush(NULL);
    sleep(1);
    break;
  }
  sort_card(player, No);		// �������ޡ����ǥ����� 
  printf(CLEAR_DISPLAY);

}
*/



// ���ꤷ���ץ쥤��˥����ɤ����� 
void send_card(PLAYER_DATA *player, CARD_DATA *select)
{
  int i;

  for (i = 0; select[i].i_mark != EMPTY; i++) {
    player->card[player->card_num] = select[i];
    player->card_num++;
  }

}



// �����ɥǡ����ν���� 
void init_card_data(CARD_DATA data[])
{
  int i;

  for (i = 0; i < MAX_FIELD_CARD+1; i++) {
    data[i].i_mark = EMPTY;
  }
}



// ���򤷤������ɤν����
void init_select_card(CARD_DATA *select)
{
  int i;

  for (i = 0; i < MAX_FIELD_CARD+1; i++) {
    select[i].i_mark = EMPTY;
  }

}

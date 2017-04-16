/*
  FILE NAME: daifugo_server.c

  DESCRIPTION:
  ������μ��פʽ����򤹤�ؿ�(�����С��ץ����)
*/


#include "daifugo.h"


int main(void)
{
  PLAYER_DATA player[PLAYER_NUM];	// �ץ쥤��Υǡ���
  int max_point = 0;   // �ݥ���Ȥκ�����
  int game_count = 1;  // ���������ܤ�
  int i;

  // �ͥåȥ����Ϣ
  int s[SOCK_MAX + 1]; // array of socket descriptors
  fd_set readfds;

  // �ͥåȥ�������
  network_init_server(s, &readfds);

  // �������褿�ʳ��ǥ��饤����Ȥ�4����³����Ƥ���Τǡ������೫�Ϥ򥯥饤����Ȥ�������
  for (i = 0; i < PLAYER_NUM; i++) {
    if (s[i+1] != UNUSED) {
      send(s[i+1], "START", sizeof(char)*1024,0);
    }
  }


  while (max_point < POINT) { //POINT��ã�����齪λ
    // �����
    initialization(player, game_count, s);

    // �ᥤ��롼��
    game(player, game_count, s, &readfds);

    // �ݥ���Ȥ�׻�
    max_point = calc_point(player);

    // ��̤�ɽ��
    disp_result(player);
	// ��̤򥯥饤����Ȥ�����
	send_control_data(s, RESULT);
    for (i = 0; i < PLAYER_NUM; i++) {
      if (s[i+1] != UNUSED) {
		send(s[i+1], player, sizeof(PLAYER_DATA)*(PLAYER_NUM), 0);
      }
    }

    // ������������
    game_count++;

    // ����point�򥯥饤����Ȥ�����
    for (i = 0; i < PLAYER_NUM; i++) {
      if (s[i+1] != UNUSED) {
		send(s[i+1], &max_point, sizeof(int),0);
      }
    }

  }


  return 0;
}



// �����
void initialization(PLAYER_DATA *player, int count, int s[])
{
  int i;

  // �Ƽ�ե饰(����)�ν����
  for (i = 0; i < PLAYER_NUM; i++) {
    player[i].status = PLAYING;
    player[i].pass = FALSE;
    player[i].rule_flag = FALSE;
  }

  distribute_card(player);	// �����ɤ�ʬ��

  sort_card(player, ALL_PLAYERS); // �������ޡ����ǥ�����

  if (count == 1) {
    for (i = 0; i < PLAYER_NUM; i++) {
      player[i].new_rank = HEIMIN;    // �ǽ�Ϥߤ��ʿ̱
      player[i].point = 0;
    }
	// ���饤����Ȥ˥ץ쥤�䡼�ֹ�(PLAYER-?��������)
    for (i = 0; i < PLAYER_NUM; i++) {
      if (s[i+1] != UNUSED) {
		send(s[i+1], &i, sizeof(int),0);
      }
    }
  }

}



/* �ݥ���Ȥ�׻� */
int calc_point(PLAYER_DATA *player)
{
  int i, num;

  // player[?].rank�ˤ�äƥݥ���Ȥ����
  num = player[0].point;
  for (i = 0; i < PLAYER_NUM; i++) {
    switch(player[i].new_rank) {
    case DAIFUGO:
      /* +2 */
      player[i].point += 2;
      break;
    case FUGO:
      /* +1 */
      player[i].point += 1;
      break;
    case HINMIN:
      /* +0 */
      break;
    case DAIHINMIN:
      /* -1 */
      player[i].point -= 1;
      break;
    }
    /* ����Υݥ���Ȥ򵭲� */
    if (num < player[i].point) {
      num = player[i].point;
    }
  }

  return num;
}



// ï���饲����򳫻Ϥ��뤫����
int set_first_player(PLAYER_DATA *player, int game_count, int s[])
{
  int i, turn = 0;
  char str[256];

  // �ǽ�ϥ�����Σ�����äƤ���ͤ���
  if (game_count == 1) {
    for (i = 0; i < PLAYER_NUM; i++) {
      if (player[i].rule_flag == DIA3) {
	turn = i;
	player[i].rule_flag = FALSE;
	printf("PLAYER-%d���������3����äƤ��ޤ���PLAYER-%d���饲���೫�Ϥ򤷤ޤ���\n", i, i);
	sprintf(str, "PLAYER-%d���������3����äƤ��ޤ���PLAYER-%d���饲���೫�Ϥ򤷤ޤ���\n", i, i); // str[]�˥��ԡ�
      }
    }
  }
  else {
    // ���ʤ�����̱����
    for (i = 0; i < PLAYER_NUM; i++) {
      if (player[i].new_rank == DAIHINMIN) {
	turn = i;
	printf("PLAYER-%d������̱�Ǥ���PLAYER-%d���饲���೫�Ϥ򤷤ޤ���\n", i, i);
	sprintf(str, "PLAYER-%d������̱�Ǥ���PLAYER-%d���饲���೫�Ϥ򤷤ޤ���\n", i, i); // str[]�˥��ԡ�
      }
    }
  }

  // ���饤����Ȥ˥�å�����(str�����äƤ�)������
  for (i = 0; i < PLAYER_NUM; i++) {
    if (s[i+1] != UNUSED) {
      send(s[i+1], str, sizeof(str),0);
    }
  }

  // 2�ô�ɽ�����Ƥ���
  sleep(2);

  return turn;
}



// ���ٹ�Υᥤ��롼��
void game(PLAYER_DATA *player, int game_count, int s[], fd_set *readfds)
{
  CARD_DATA field[MAX_FIELD_CARD+1] = { EMPTY };      /* �ե�����ɡʾ�� */
  CARD_DATA select_card[MAX_FIELD_CARD+1] = { EMPTY };     /* �ץ쥤�䤬���򤷤������� */
  int foul_play_count;
  int select_card_num, old_num;	  /* ���򤷤������ɤ���� */
  int turn;	          /* ï�Υ�����(0:PLAYER-0, 1:PLAYER-1, ...) */
  int player_count;	  /* �ץ쥤���Ƥ���ͤοͿ� */
  int field_status;	  /* �ե�����ɤξ��� */
  int input_status;	  /* ���򤷤������ɤ���˽Ф��뤫��Ƚ���̤��Ǽ */
  int last_win_player;	  /* ���Υ�����ǺǸ�ˤ����ä��ץ쥤�� */
  int ignore_pass;	  /* �ѥ��ե饰��̵�뤹��ե饰 */
  int miyako_ochi_flag;
  int last_put_player;
  int i;
  int control_data;
  int recv_flag;
  int n;
  int last_pass_player;


  /* ����� */
  select_card_num = old_num = 0;  /* �ǽ�ϰ�������򤵤�Ƥ��ʤ�(��˽ФƤ��ʤ�) */
  foul_play_count = 0;
  last_win_player = NOBODY;	/* �ޤ�ï�⤢���äƤʤ�(�Ϥ������) */
  ignore_pass = FALSE;	/* �ޤ��ѥ��ե饰��̵�뤷�ʤ� */
  miyako_ochi_flag = FALSE;
  field_status = ORDINARY;
  last_put_player = NOBODY;
  player_count = PLAYER_NUM;
  turn = set_first_player(player, game_count, s); /* ï���饲���ॹ�����Ȥ����� */


  // ����γ������¸���Ƥ���
  for (i = 0; i < PLAYER_NUM; i++) {
    player[i].old_rank = player[i].new_rank;
    player[i].new_rank = HEIMIN;
  }


  /* �Ǹ�ΰ�ͤˤʤ�ޤǥ롼�� */
  while (player_count != 1) {
    printf(CLEAR_DISPLAY);	/* ���̥��ꥢ */

    init_card_data(select_card);	/* ���򤷤������ɤν���� */

    // �ե�����ɤ�ɽ�����뤿��Υǡ����򥯥饤����Ȥ�����
	send_control_data(s, FIELD_DATA);
    for (i = 0; i < PLAYER_NUM; i++) {
      if (s[i+1] != UNUSED) {
		send(s[i+1], &select_card_num, sizeof(int),0);
		send(s[i+1], &turn, sizeof(int),0);
		send(s[i+1], &field_status, sizeof(int),0);
		send(s[i+1], player, sizeof(PLAYER_DATA)*(PLAYER_NUM),0);
		send(s[i+1], field, sizeof(CARD_DATA)*(MAX_FIELD_CARD+1),0);
      }
    }

    disp_field(player, field, select_card_num, turn, field_status); /* �ե������(��)��ɽ�� */

    disp_card_all(player); /* �ץ쥤��μ껥��ɽ�� */

    /* �ե�����ɤ˥����ɤ�Ф����Ͱʳ��Υץ쥤���������ѥ���������ή�� */
    if (last_put_player == turn && ignore_pass == FALSE) {
      last_pass_player = NOBODY;
      last_put_player = NOBODY;
      // disp_all_pass_message();	  /* �����ѥ�������å�������ɽ�� */
      init_card_data(field);      /* �ե�����ɤν���� */
      init_pass_flag(player);     /* �ѥ��ե饰�ν���� */
      select_card_num = old_num = 0;	  /* �ե�����ɤ˥����ɤ�̵�� */

	  // ���饤����Ȥ��������ѥ��������Ȥ�������
	  send_control_data(s, ALL_PASS);

    }
    else {
      if (player[turn].pass == TRUE) {
		// disp_pass_message();
		last_pass_player = turn;

		// ���饤����Ȥ˥ѥ��������Ȥ�������
		send_control_data(s, PASS);

      }
      else {
		/* ���ʤϤ��ä� */
		old_num = select_card_num;      /* 1�����Υ�����˾�˽Ф��������ɤ�������ݻ����Ƥ��� */

		do {
		  // ���饤����Ȥ˥����ɤ����򤵤���
		  send_control_data(s, SELECT_CARD);
		  for (i = 0; i < PLAYER_NUM; i++) {
			if (s[i+1] != UNUSED) {
			  send(s[i+1], &turn, sizeof(int) ,0);
			}
		  }

		  /* ���򤷤������ɤν���� */
		  init_select_card(select_card);

		  // ���饤����Ȥ������򤷤������ɤ��������
		  do {
			/// from [mserver.c]
			for (i = 0; i < PLAYER_NUM+1; i++) {
			  if (s[i] != UNUSED) {
				FD_SET(s[i], readfds);
			  }
			}

			if ((n=select(FD_SETSIZE, readfds, NULL, NULL, NULL)) == -1) {
			  perror("select");
			}
			for (i = 0; i < PLAYER_NUM; i++) {
			  if (s[i+1] != UNUSED) {
				if (FD_ISSET(s[i+1], readfds)) {
				  recv(s[i+1], &select_card_num, sizeof(int),0);
				  recv(s[i+1], select_card, sizeof(CARD_DATA)*(MAX_FIELD_CARD+1),0);
				  recv_flag = TRUE;
				}
			  }
			}
		  } while(recv_flag == FALSE);

		  /* ���⥫���ɤ����򤷤ʤ��ȥѥ� */
		  if (select_card_num == 0) {
			if (old_num == 0) {
			  input_status = ERROR;
			}
			else {
			  select_card_num = old_num;
			  player[turn].pass = TRUE;
			  // disp_pass_message();
			  last_pass_player = turn;

			  // ���饤����Ȥ˥ѥ���å�������ɽ��������
			  send_control_data(s, PASS);

			  break;
			}
		  }
		  /* �ѥ�����ʤ��ʤ����򤷤������ɤ���˽Ф��뤫�����å� */
		  else {
			input_status = check_input(field, select_card, select_card_num, old_num);
		  }
		} while (input_status == ERROR);


		/* �ѥ�����ʤ��Ȥ� */
		if (player[turn].pass == FALSE) {
		  /* �ե�����ɤ˥����ɤ�Ф� */
		  for (i = 0; i < MAX_FIELD_CARD; i++) {
			field[i] = select_card[i];
		  }

		  delete_used_card(&player[turn], select_card); /* �Ф��������ɤ�껥������ */

		  // printf("select card num = %d\n", select_card_num);
		  if (select_card_num >= 4) {   // �ե�����ɤ�4��ʾ奫���ɤ��Ф����̿
		    kakumei(player, field_status);

			if (field_status == ORDINARY) {
			  field_status = KAKUMEI;
			}
			else {
			  field_status = ORDINARY;
			}

			// ���饤����Ȥ˳�̿��å�������ɽ��������
			send_control_data(s, KAKUMEI_MSG);
			for (i = 0; i < PLAYER_NUM; i++) {
			  if (s[i+1] != UNUSED) {
				send(s[i+1], player, sizeof(PLAYER_DATA)*(PLAYER_NUM),0);
				send(s[i+1], field, sizeof(CARD_DATA)*(MAX_FIELD_CARD+1),0);
				send(s[i+1], &select_card_num, sizeof(int),0);
				send(s[i+1], &turn, sizeof(int),0);
				send(s[i+1], &field_status, sizeof(int),0);
			  }
			}

			//			disp_kakumei_message(); // ��̿!!!��å�������ɽ��

			// �껥�򥽡��Ȥ��ʤ���
			sort_card(player, ALL_PLAYERS);
		  }

		  /* 8�ڤ� */
		  if (yagiri(field) == TRUE) {
			printf(CLEAR_DISPLAY);	/* ���̥��ꥢ */
			disp_field(player, field, select_card_num, turn, field_status); /* �ե������(��)��ɽ�� */
			disp_my_card(&player[turn]); /* �ץ쥤��μ껥��ɽ�� */
			// disp_yagiri_message(); /* ��å�������ɽ�� */

			// ���饤����Ȥ˥ѥ���å�������ɽ��������
			send_control_data(s, YAGIRI);
			for (i = 0; i < PLAYER_NUM; i++) {
			  if (s[i+1] != UNUSED) {
				send(s[i+1], player, sizeof(PLAYER_DATA)*(PLAYER_NUM),0);
				send(s[i+1], field, sizeof(CARD_DATA)*(MAX_FIELD_CARD+1),0);
				send(s[i+1], &select_card_num, sizeof(int),0);
				send(s[i+1], &turn, sizeof(int),0);
				send(s[i+1], &field_status, sizeof(int),0);
			  }
			}

			select_card_num = old_num = 0;

			/* ���ʳ��Ǥ�����Ǥʤ���Ф��οͤΥ����� */
			/* (8�ڤ�夬���ȿ§�����ɤ͡�) */
			if (player[turn].card_num != 0) {
			  init_card_data(field); /* �ե�����ɥ��ꥢ */
			  continue;
			}
		  }

		  /* �����ä��ͤ�������*/
		  if (player[turn].card_num == 0) {
			/* ������ν��� */
			if (player_count == PLAYER_NUM && game_count != 1 && player[turn].old_rank != DAIFUGO) {
			  player[get_rank_to_playerNo_old(player, DAIFUGO)].new_rank = DAIHINMIN; /* ������ʤΤ�����̱ */
			  player[get_rank_to_playerNo_old(player, DAIFUGO)].status = END;
			  player[get_rank_to_playerNo_old(player, DAIFUGO)].rule_flag = MIYAKO_OCHI;
			  player[get_rank_to_playerNo_old(player, DAIFUGO)].card_num = 0;
			  player[turn].new_rank = DAIFUGO;
			  miyako_ochi_flag = TRUE;
			  player_count--;	/* �ץ쥤�Ϳ��򹹿� */
			}

			/* ȿ§�����ꤷ�Ƥ��ʤ�����ǧ */
			if (check_foul_play(field, field_status, select_card_num) == TRUE) {
			  foul_play_count++;
			  player[turn].rule_flag = FOUL_PLAY;
			}

			judge_rank(player, turn, player_count, foul_play_count, miyako_ochi_flag);
			player[turn].status = END; /* ���Υץ쥤��ξ��֤򤢤�����֤ˤ��� */
			player_count--;		/* �ץ쥤�Ϳ��򹹿� */
			last_win_player = turn;	   /* �Ǹ�ˤ����ä��ץ쥤��򤽤οͤˤ��� */
		  }


		  if (player[turn].status == END) {
			last_put_player = set_next_turn(player, turn);
			ignore_pass = TRUE;
		  }
		  else {
			last_put_player = turn;
		  }

		}

		if (player[turn].status != END) {
		  ignore_pass = FALSE;
		}


      }

      if (player_count != 0) {
		turn = set_next_turn(player, turn); /* ���οͤΥ�����ˤ��� */
      }

    }
  }

  /* �Ǹ�ΰ�ͤγ����Ƚ�� */
  judge_rank(player, turn, player_count, foul_play_count, miyako_ochi_flag);

}



/* ���οͤΥ�����ˤ��� */
int set_next_turn(PLAYER_DATA *player, int turn)
{
  int i;

  /* �Ǹ�οͤʤ�ǽ�οͤ� */
  if (turn == PLAYER_NUM-1) {
    turn = 0;
  }
  /* ����ʳ��ϼ��οͤ� */
  else {
    turn++;
  }

  /* �����ä��ҤȤϥ����å� */
  if (player[turn].status == END) {
    turn = set_next_turn(player, turn);
  }

  return turn;
}



/* �����Ƚ�� */
void judge_rank(PLAYER_DATA *player, int turn, int count, int foul_play_count, int miyako_ochi)
{
  int num;
  int i;

  /* ȿ§������ν��� */
  if (player[turn].rule_flag == FOUL_PLAY) {
    switch (foul_play_count) {
    case 1:
      /* �����������Ƥ���ץ쥤�䤬�������ϡ� */
      /* ���Υץ쥤��γ�����ķ���夲�� */
      if (miyako_ochi == TRUE) {
		i = get_rank_to_playerNo_new(player, DAIHINMIN);
		player[i].new_rank = HINMIN;
		printf("miyako:player[%d].new_rank = %d\n", i, player[i].new_rank);
      }
      player[turn].new_rank = DAIHINMIN;
      printf("foul:player[%d].new_rank = %d\n", turn, player[turn].new_rank);
      break;
    case 2:
      if (miyako_ochi == TRUE) {
		player[get_rank_to_playerNo_new(player, HINMIN)].new_rank = FUGO;
      }
      player[turn].new_rank = HINMIN;
      break;
    case 3:
      if (miyako_ochi == TRUE) {
		player[get_rank_to_playerNo_new(player, FUGO)].new_rank = DAIFUGO;
      }
      player[turn].new_rank = FUGO;
      break;
    }
  }
  else {
    /* �������ȿ§�夬�ꤷ���ץ쥤�䤬����ȡ����餬����� */
    num = count + miyako_ochi + foul_play_count;
    switch(num) {
    case 4:		/* 4�ͤ�������Ǥ����ä������ٹ� */
      player[turn].new_rank = DAIFUGO;
      break;
    case 3:		/* 3�ͤ�������Ǥ����ä����ٹ� */
      player[turn].new_rank = FUGO;
      break;
    case 2:		/* 2�ͤ�������Ǥ����ä�����̱ */
      player[turn].new_rank = HINMIN;
      break;
    case 1:		/* 1�ͤ����ξ�����������̱ */
      player[turn].new_rank = DAIHINMIN;
      break;
    }
  }

}

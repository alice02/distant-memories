/*
  FILE NAME: daifugo_server.c

  DESCRIPTION:
  ゲームの主要な処理をする関数(サーバープログラム)
*/


#include "daifugo.h"


int main(void)
{
  PLAYER_DATA player[PLAYER_NUM];	// プレイヤのデータ
  int max_point = 0;   // ポイントの最大値
  int game_count = 1;  // 何ゲーム目か
  int i;

  // ネットワーク関連
  int s[SOCK_MAX + 1]; // array of socket descriptors
  fd_set readfds;

  // ネットワーク初期化
  network_init_server(s, &readfds);

  // ここに来た段階でクライアントが4台接続されているので、ゲーム開始をクライアントに伝える
  for (i = 0; i < PLAYER_NUM; i++) {
    if (s[i+1] != UNUSED) {
      send(s[i+1], "START", sizeof(char)*1024,0);
    }
  }


  while (max_point < POINT) { //POINTに達したら終了
    // 初期化
    initialization(player, game_count, s);

    // メインループ
    game(player, game_count, s, &readfds);

    // ポイントを計算
    max_point = calc_point(player);

    // 結果を表示
    disp_result(player);
	// 結果をクライアントに送信
	send_control_data(s, RESULT);
    for (i = 0; i < PLAYER_NUM; i++) {
      if (s[i+1] != UNUSED) {
		send(s[i+1], player, sizeof(PLAYER_DATA)*(PLAYER_NUM), 0);
      }
    }

    // ゲーム回数更新
    game_count++;

    // 最大pointをクライアントに送信
    for (i = 0; i < PLAYER_NUM; i++) {
      if (s[i+1] != UNUSED) {
		send(s[i+1], &max_point, sizeof(int),0);
      }
    }

  }


  return 0;
}



// 初期化
void initialization(PLAYER_DATA *player, int count, int s[])
{
  int i;

  // 各種フラグ(状態)の初期化
  for (i = 0; i < PLAYER_NUM; i++) {
    player[i].status = PLAYING;
    player[i].pass = FALSE;
    player[i].rule_flag = FALSE;
  }

  distribute_card(player);	// カードを分配

  sort_card(player, ALL_PLAYERS); // 数字，マークでソート

  if (count == 1) {
    for (i = 0; i < PLAYER_NUM; i++) {
      player[i].new_rank = HEIMIN;    // 最初はみんな平民
      player[i].point = 0;
    }
	// クライアントにプレイヤー番号(PLAYER-?を伝える)
    for (i = 0; i < PLAYER_NUM; i++) {
      if (s[i+1] != UNUSED) {
		send(s[i+1], &i, sizeof(int),0);
      }
    }
  }

}



/* ポイントを計算 */
int calc_point(PLAYER_DATA *player)
{
  int i, num;

  // player[?].rankによってポイントを決める
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
    /* 最大のポイントを記憶 */
    if (num < player[i].point) {
      num = player[i].point;
    }
  }

  return num;
}



// 誰からゲームを開始するか決める
int set_first_player(PLAYER_DATA *player, int game_count, int s[])
{
  int i, turn = 0;
  char str[256];

  // 最初はダイヤの３を持っている人から
  if (game_count == 1) {
    for (i = 0; i < PLAYER_NUM; i++) {
      if (player[i].rule_flag == DIA3) {
	turn = i;
	player[i].rule_flag = FALSE;
	printf("PLAYER-%dがダイヤの3を持っています．PLAYER-%dからゲーム開始をします．\n", i, i);
	sprintf(str, "PLAYER-%dがダイヤの3を持っています．PLAYER-%dからゲーム開始をします．\n", i, i); // str[]にコピー
      }
    }
  }
  else {
    // 普段は大貧民から
    for (i = 0; i < PLAYER_NUM; i++) {
      if (player[i].new_rank == DAIHINMIN) {
	turn = i;
	printf("PLAYER-%dが大貧民です．PLAYER-%dからゲーム開始をします．\n", i, i);
	sprintf(str, "PLAYER-%dが大貧民です．PLAYER-%dからゲーム開始をします．\n", i, i); // str[]にコピー
      }
    }
  }

  // クライアントにメッセージ(strに入ってる)を送信
  for (i = 0; i < PLAYER_NUM; i++) {
    if (s[i+1] != UNUSED) {
      send(s[i+1], str, sizeof(str),0);
    }
  }

  // 2秒間表示しておく
  sleep(2);

  return turn;
}



// 大富豪のメインループ
void game(PLAYER_DATA *player, int game_count, int s[], fd_set *readfds)
{
  CARD_DATA field[MAX_FIELD_CARD+1] = { EMPTY };      /* フィールド（場） */
  CARD_DATA select_card[MAX_FIELD_CARD+1] = { EMPTY };     /* プレイヤが選択したカード */
  int foul_play_count;
  int select_card_num, old_num;	  /* 選択したカードの枚数 */
  int turn;	          /* 誰のターンか(0:PLAYER-0, 1:PLAYER-1, ...) */
  int player_count;	  /* プレイしている人の人数 */
  int field_status;	  /* フィールドの状態 */
  int input_status;	  /* 選択したカードが場に出せるかの判定結果を格納 */
  int last_win_player;	  /* そのターンで最後にあがったプレイヤ */
  int ignore_pass;	  /* パスフラグを無視するフラグ */
  int miyako_ochi_flag;
  int last_put_player;
  int i;
  int control_data;
  int recv_flag;
  int n;
  int last_pass_player;


  /* 初期化 */
  select_card_num = old_num = 0;  /* 最初は一枚も選択されていない(場に出ていない) */
  foul_play_count = 0;
  last_win_player = NOBODY;	/* まだ誰もあがってない(はずだよね) */
  ignore_pass = FALSE;	/* まだパスフラグを無視しない */
  miyako_ochi_flag = FALSE;
  field_status = ORDINARY;
  last_put_player = NOBODY;
  player_count = PLAYER_NUM;
  turn = set_first_player(player, game_count, s); /* 誰からゲームスタートか決める */


  // 前回の階級を保存しておく
  for (i = 0; i < PLAYER_NUM; i++) {
    player[i].old_rank = player[i].new_rank;
    player[i].new_rank = HEIMIN;
  }


  /* 最後の一人になるまでループ */
  while (player_count != 1) {
    printf(CLEAR_DISPLAY);	/* 画面クリア */

    init_card_data(select_card);	/* 選択したカードの初期化 */

    // フィールドを表示するためのデータをクライアントに送信
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

    disp_field(player, field, select_card_num, turn, field_status); /* フィールド(場)を表示 */

    disp_card_all(player); /* プレイヤの手札を表示 */

    /* フィールドにカードを出した人以外のプレイヤ全員がパスしたら場を流す */
    if (last_put_player == turn && ignore_pass == FALSE) {
      last_pass_player = NOBODY;
      last_put_player = NOBODY;
      // disp_all_pass_message();	  /* 全員パスしたメッセージの表示 */
      init_card_data(field);      /* フィールドの初期化 */
      init_pass_flag(player);     /* パスフラグの初期化 */
      select_card_num = old_num = 0;	  /* フィールドにカードは無い */

	  // クライアントに全員がパスしたことを伝える
	  send_control_data(s, ALL_PASS);

    }
    else {
      if (player[turn].pass == TRUE) {
		// disp_pass_message();
		last_pass_player = turn;

		// クライアントにパスしたことを伝える
		send_control_data(s, PASS);

      }
      else {
		/* 普段はこっち */
		old_num = select_card_num;      /* 1つ前のターンに場に出したカードの枚数を保持しておく */

		do {
		  // クライアントにカードを選択させる
		  send_control_data(s, SELECT_CARD);
		  for (i = 0; i < PLAYER_NUM; i++) {
			if (s[i+1] != UNUSED) {
			  send(s[i+1], &turn, sizeof(int) ,0);
			}
		  }

		  /* 選択したカードの初期化 */
		  init_select_card(select_card);

		  // クライアントから選択したカードを受信する
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

		  /* 何もカードを選択しないとパス */
		  if (select_card_num == 0) {
			if (old_num == 0) {
			  input_status = ERROR;
			}
			else {
			  select_card_num = old_num;
			  player[turn].pass = TRUE;
			  // disp_pass_message();
			  last_pass_player = turn;

			  // クライアントにパスメッセージを表示させる
			  send_control_data(s, PASS);

			  break;
			}
		  }
		  /* パスじゃないなら選択したカードが場に出せるかチェック */
		  else {
			input_status = check_input(field, select_card, select_card_num, old_num);
		  }
		} while (input_status == ERROR);


		/* パスじゃないとき */
		if (player[turn].pass == FALSE) {
		  /* フィールドにカードを出す */
		  for (i = 0; i < MAX_FIELD_CARD; i++) {
			field[i] = select_card[i];
		  }

		  delete_used_card(&player[turn], select_card); /* 出したカードを手札から削除 */

		  // printf("select card num = %d\n", select_card_num);
		  if (select_card_num >= 4) {   // フィールドに4枚以上カードが出たら革命
		    kakumei(player, field_status);

			if (field_status == ORDINARY) {
			  field_status = KAKUMEI;
			}
			else {
			  field_status = ORDINARY;
			}

			// クライアントに革命メッセージを表示させる
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

			//			disp_kakumei_message(); // 革命!!!メッセージを表示

			// 手札をソートしなおす
			sort_card(player, ALL_PLAYERS);
		  }

		  /* 8切り */
		  if (yagiri(field) == TRUE) {
			printf(CLEAR_DISPLAY);	/* 画面クリア */
			disp_field(player, field, select_card_num, turn, field_status); /* フィールド(場)を表示 */
			disp_my_card(&player[turn]); /* プレイヤの手札を表示 */
			// disp_yagiri_message(); /* メッセージの表示 */

			// クライアントにパスメッセージを表示させる
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

			/* 現段階であがりでなければその人のターン */
			/* (8切り上がりは反則だけどね…) */
			if (player[turn].card_num != 0) {
			  init_card_data(field); /* フィールドクリア */
			  continue;
			}
		  }

		  /* あがった人がいたら*/
		  if (player[turn].card_num == 0) {
			/* 都落ちの処理 */
			if (player_count == PLAYER_NUM && game_count != 1 && player[turn].old_rank != DAIFUGO) {
			  player[get_rank_to_playerNo_old(player, DAIFUGO)].new_rank = DAIHINMIN; /* 都落ちなので大貧民 */
			  player[get_rank_to_playerNo_old(player, DAIFUGO)].status = END;
			  player[get_rank_to_playerNo_old(player, DAIFUGO)].rule_flag = MIYAKO_OCHI;
			  player[get_rank_to_playerNo_old(player, DAIFUGO)].card_num = 0;
			  player[turn].new_rank = DAIFUGO;
			  miyako_ochi_flag = TRUE;
			  player_count--;	/* プレイ人数を更新 */
			}

			/* 反則あがりしていないか確認 */
			if (check_foul_play(field, field_status, select_card_num) == TRUE) {
			  foul_play_count++;
			  player[turn].rule_flag = FOUL_PLAY;
			}

			judge_rank(player, turn, player_count, foul_play_count, miyako_ochi_flag);
			player[turn].status = END; /* そのプレイヤの状態をあがり状態にする */
			player_count--;		/* プレイ人数を更新 */
			last_win_player = turn;	   /* 最後にあがったプレイヤをその人にする */
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
		turn = set_next_turn(player, turn); /* 次の人のターンにする */
      }

    }
  }

  /* 最後の一人の階級を判定 */
  judge_rank(player, turn, player_count, foul_play_count, miyako_ochi_flag);

}



/* 次の人のターンにする */
int set_next_turn(PLAYER_DATA *player, int turn)
{
  int i;

  /* 最後の人なら最初の人へ */
  if (turn == PLAYER_NUM-1) {
    turn = 0;
  }
  /* それ以外は次の人へ */
  else {
    turn++;
  }

  /* あがったひとはスキップ */
  if (player[turn].status == END) {
    turn = set_next_turn(player, turn);
  }

  return turn;
}



/* 階級を判定 */
void judge_rank(PLAYER_DATA *player, int turn, int count, int foul_play_count, int miyako_ochi)
{
  int num;
  int i;

  /* 反則あがりの処理 */
  if (player[turn].rule_flag == FOUL_PLAY) {
    switch (foul_play_count) {
    case 1:
      /* 先に都落ちしているプレイヤがいた場合は、 */
      /* そのプレイヤの階級を一つ繰り上げる */
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
    /* 都落ちや反則上がりしたプレイヤがいると、階級がずれる */
    num = count + miyako_ochi + foul_play_count;
    switch(num) {
    case 4:		/* 4人いる状況であがったら大富豪 */
      player[turn].new_rank = DAIFUGO;
      break;
    case 3:		/* 3人いる状況であがったら富豪 */
      player[turn].new_rank = FUGO;
      break;
    case 2:		/* 2人いる状況であがったら貧民 */
      player[turn].new_rank = HINMIN;
      break;
    case 1:		/* 1人だけの状況だと大貧民 */
      player[turn].new_rank = DAIHINMIN;
      break;
    }
  }

}

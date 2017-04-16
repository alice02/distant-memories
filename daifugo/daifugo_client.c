/*
  FILE NAME: daifugo_client.c

  DESCRIPTION:
  クライアントの処理
*/


#include "daifugo.h"


int main(int argc, char *argv[])
{
  CARD_DATA field[MAX_PLAYER_CARD+1] = { EMPTY };
  CARD_DATA select[MAX_PLAYER_CARD+1] = { EMPTY };
  PLAYER_DATA all_player_data[PLAYER_NUM];
  int turn;
  int select_card_num;
  int field_status;
  int player_number;
  char str[256];
  int control_data;
  int fd;
  int max_point;
  int game_number = 1;


  // 引数チェック
  if (argc-1 != 1){
    printf("Usage: %s SERVER_NAME\n", argv[0]);
    exit(1);
  }

  // ネットワークの初期化
  network_init_client(&fd, argv);

  // 他のプレイヤーが揃うまで待機メッセージ
  do {
    printf("Waiting for other players ...\n");
    recv(fd, str, sizeof(char)*1024, 0);
  } while(strcmp(str, "START") != 0);

  // player number[PLAYER-?]を決定
  recv(fd, &player_number, sizeof(int), 0);
  printf("player number : %d\n", player_number);

  do{
    // 誰からゲームを開始するかを表示
    recv(fd, str, sizeof(char)*1024, 0);
    printf("%s\n", str);
    sleep(2);

	// メインループ
    while (1) {
	  // 制御データを受信(network.hで定義)
      recv(fd, &control_data, sizeof(int), 0);

      // フィールド(手札も)表示
      if (control_data == FIELD_DATA) {
		recv(fd, &select_card_num, sizeof(int), 0);
		recv(fd, &turn, sizeof(int), 0);
		recv(fd, &field_status, sizeof(int), 0);
		recv(fd, all_player_data, sizeof(PLAYER_DATA)*(PLAYER_NUM), 0);
		recv(fd, field, sizeof(CARD_DATA)*(MAX_FIELD_CARD+1), 0);

		printf(CLEAR_DISPLAY);
		printf("\n========== I'm PLAYER-%d  GAME:%d ==========\n\n", player_number, game_number);
		disp_field(all_player_data, field, select_card_num, turn, field_status);
		disp_my_card(&all_player_data[player_number]);
      }

      /// カード選択
      else if (control_data == SELECT_CARD) {
		recv(fd, &turn, sizeof(int), 0);
		if (turn == player_number) {
		  init_card_data(select);
		  select_card_num = select_card(&all_player_data[turn], select); /* 場に出すカードを選択させる */
		  send(fd, &select_card_num, sizeof(int), 0);
		  send(fd, select, sizeof(CARD_DATA)*(MAX_FIELD_CARD+1), 0);
		}
      }

      /// パスメッセージ
      else if (control_data == PASS) {
		disp_pass_message();
      }

      /// 全員パスメッセージ
      else if (control_data == ALL_PASS) {
		disp_all_pass_message();
      }

      /// 8切りメッセージ
      else if(control_data == YAGIRI) {
		recv(fd, all_player_data, sizeof(PLAYER_DATA)*(PLAYER_NUM), 0);
		recv(fd, field, sizeof(CARD_DATA)*(MAX_FIELD_CARD+1), 0);
		recv(fd, &select_card_num, sizeof(int), 0);
		recv(fd, &turn, sizeof(int), 0);
		recv(fd, &field_status, sizeof(int), 0);

		printf(CLEAR_DISPLAY);	/* 画面クリア */
		printf("========== I'm PLAYER-%d  GAME:%d ==========\n\n", player_number, game_number);
		disp_field(all_player_data, field, select_card_num, turn, field_status);
		disp_my_card(&all_player_data[player_number]);
		disp_yagiri_message(); /* メッセージの表示 */
      }

      /// 革命メッセージ
      else if (control_data == KAKUMEI_MSG) {
		recv(fd, all_player_data, sizeof(PLAYER_DATA)*(PLAYER_NUM), 0);
		recv(fd, field, sizeof(CARD_DATA)*(MAX_FIELD_CARD+1), 0);
		recv(fd, &select_card_num, sizeof(int), 0);
		recv(fd, &turn, sizeof(int), 0);
		recv(fd, &field_status, sizeof(int), 0);

		printf(CLEAR_DISPLAY);	/* 画面クリア */
		printf("========== I'm PLAYER-%d  GAME:%d ==========\n\n", player_number, game_number);
		disp_field(all_player_data, field, select_card_num, turn, field_status);
		disp_my_card(&all_player_data[player_number]);
		disp_kakumei_message();
      }

      /// 結果表示
      else if(control_data == RESULT) {
		recv(fd, all_player_data, sizeof(PLAYER_DATA)*(PLAYER_NUM), 0);
		printf(CLEAR_DISPLAY);	/* 画面クリア */
		disp_result(all_player_data);
		recv(fd, &max_point, sizeof(int), 0);
		break;
      }
    }

	game_number++;

  }while (max_point < POINT);  // max_pointがPOINTに達したらゲーム終了

  printf("誰かが%d点に達したのでゲームを終了します...\n", POINT);

  close(fd);

  return 0;
}


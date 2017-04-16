/*
  FILE NAME: disp.c

  DESCRIPTION:
  画面表示に関する関数
*/


#include "daifugo.h"


// オープニングメッセージ
void opening(void)
{
  printf(CLEAR_DISPLAY);
  printf("\n\n");

  printf(BOLD);
  printf("               ****************************************\n");
  printf("               *                                      *\n");
  printf("               *             ");
  printf("大  富  豪");
  printf("               *\n");
  printf("               *                                      *\n");
  printf("               ****************************************\n");
  printf(CLEAR_ATTRIBUTE);

  printf("\n\n");
  printf("何かキーを押すとスタート!!\n");
  getchar();
}



// フィールドを表示
void disp_field(PLAYER_DATA *player, CARD_DATA *field, int num, int turn, int field_status)
{
  int i;
  char word[PLAYER_NUM][10];

  // player[?].rankによって、表示する階級を決定
  for (i = 0; i < PLAYER_NUM; i++) {
    if (player[i].status == END) {
      switch (player[i].new_rank) {
      case HEIMIN:
		strcpy(word[i], "  平民  ");
		break;
      case DAIFUGO:
		strcpy(word[i], " 大富豪 ");
		break;
      case FUGO:
		strcpy(word[i], "  富豪  ");
		break;
      case HINMIN:
		strcpy(word[i], "  貧民  ");
		break;
      case DAIHINMIN:
		strcpy(word[i], " 大貧民 ");
		break;
      }
    }
    else {
      switch (player[i].old_rank) {
      case HEIMIN:
		strcpy(word[i], "  平民  ");
		break;
      case DAIFUGO:
		strcpy(word[i], " 大富豪 ");
		break;
      case FUGO:
		strcpy(word[i], "  富豪  ");
		break;
      case HINMIN:
		strcpy(word[i], "  貧民  ");
		break;
      case DAIHINMIN:
		strcpy(word[i], " 大貧民 ");
		break;
      }
    }
  }
  printf("\n");


  // ここから下はフィールドの上に表示されるやつに関する記述
  // (この先エスケープシーケンスの乱用にご注意...)

  /* ▼の表示 */
  printf("\x1b[1A");
  printf("\x1b[6C");
  for (i = 0; i < turn; i++) {
    printf("\x1b[17C");
  }
  printf("▼");
  printf("\x1b[500C");
  printf("\n");

  printf("+------------+   +------------+   +------------+   +------------+\n");
  printf("|            |   |            |   |            |   |            |\n");
  printf("|  PLAYER-0  |   |  PLAYER-1  |   |  PLAYER-2  |   |  PLAYER-3  |\n");
  printf("|            |   |            |   |            |   |            |\n");
  printf("| |￣|       |   | |￣|       |   | |￣|       |   | |￣|       |\n");
  printf("| |  | × %2d |   | |  | × %2d |   | |  | × %2d |   | |  | × %2d |\n", player->card_num, (player+1)->card_num, (player+2)->card_num, (player+3)->card_num);
  printf("|  ￣        |   |  ￣        |   |  ￣        |   |  ￣        |\n");
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
	printf("                         革命なう！！                            \n");
	printf(CLEAR_ATTRIBUTE);
	printf(DEFAULT_COLOR);
  }
  else {
	printf("\n");
  }

  //   ---------------------------
  //   *  PLAYER-? :             *   の表示
  //   ---------------------------

  printf(BLUE);
  printf("                   ---------------------------\n");
  printf("                   *  PLAYER-%d :             *\n", turn);
  printf("                   ---------------------------\n\n");
  printf(DEFAULT_COLOR);


  // フィールドの表示

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



/// 全員の手札を表示(サーバー向け)
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



/* 自分の手札だけ表示(クライアント向け) */
void disp_my_card(PLAYER_DATA *player)
{
  int i, j;

  printf("\n\n↓↓↓↓↓↓↓↓↓↓↓↓↓↓ YOUR CARDS ↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
  printf("[A][D][SPACE]:選択  [ENTER]:決定   (注:何も選択しないとパス)\n\n");

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



// 対戦の結果を表示
void disp_result(PLAYER_DATA *player)
{
  int i, j;
  char *rank[] =  {"大富豪", " 富豪 ", " 貧民 ", "大貧民"};
  char *point[] = {"  +2  ", "  +1  ", "  +0  ", "  -1  "};
  int pointer[PLAYER_NUM];


  // player[?].rankによって表示する文字を選択
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

  // 「終了！！」メッセージを500[ms]表示
  printf("\n\n終了！！\n\n");
  usleep(500000);


  // 結果を表示
  printf(CLEAR_DISPLAY);
  printf("↓↓↓↓↓↓↓↓↓↓↓↓↓↓   結果   ↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n\n");
  printf("+------------+   +------------+   +------------+   +------------+\n");
  printf("|            |   |            |   |            |   |            |\n");
  printf("|  PLAYER-0  |   |  PLAYER-1  |   |  PLAYER-2  |   |  PLAYER-3  |\n");
  printf("|            |   |            |   |            |   |            |\n");
  printf("|   %s   |   |   %s   |   |   %s   |   |   %s   |\n", rank[pointer[0]], rank[pointer[1]], rank[pointer[2]], rank[pointer[3]]);
  printf("|   %s   |   |   %s   |   |   %s   |   |   %s   |\n", point[pointer[0]], point[pointer[1]], point[pointer[2]], point[pointer[3]]);
  printf("|            |   |            |   |            |   |            |\n");
  printf("|  累計:%2dP  |   |  累計:%2dP  |   |  累計:%2dP  |   |  累計:%2dP  |\n", player[0].point, player[1].point, player[2].point, player[3].point);
  printf("|            |   |            |   |            |   |            |\n");
  printf("+------------+   +------------+   +------------+   +------------+\n\n");
  printf("↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑\n\n");

  // 3秒間結果を表示しておく
  sleep(3);

  printf(CLEAR_DISPLAY);
}



// "ALL Players PASS!!!"を表示
void disp_all_pass_message(void)
{
  /* カーソル位置を合わせる */
  printf("\x1b[16A");
  printf("\x1b[22C");
  printf(MAGENTA);
  printf("All Players PASS!!!");
  printf(DEFAULT_COLOR);
  fflush(NULL);
  sleep(1);
}



// "PASS"を表示
void disp_pass_message(void)
{
  /* カーソル位置を合わせる */
  printf("\x1b[16A");
  printf("\x1b[1000D");
  printf("\x1b[33C");
  printf(BLUE);  /* 青にする */
  printf("PASS");
  printf(DEFAULT_COLOR);   /* デフォルトカラーに戻す */
  fflush(NULL);
  sleep(1);	   /* 1[s]表示しておく */
}



// "8切り!!"を表示
void disp_yagiri_message(void)
{
  /* カーソル位置を合わせる */
  printf("\x1b[16A");
  printf("\x1b[1000D");
  printf("\x1b[33C");
  printf(CYAN);		   /* シアンにする */
  printf("8切り!!");
  printf(DEFAULT_COLOR);   /* デフォルトカラーに戻す */
  fflush(NULL);
  sleep(1);	   /* 1[s]表示しておく */
}



// "革命!!!"を表示
void disp_kakumei_message(void)
{
  /* カーソル位置を合わせる */
  printf("\x1b[16A");
  printf("\x1b[1000D");
  printf("\x1b[33C");
  printf(CYAN);		   /* シアンにする */
  printf("革命!!!");
  printf(DEFAULT_COLOR);   /* デフォルトカラーに戻す */
  fflush(NULL);
  sleep(1);	   /* 1[s]表示しておく */
}

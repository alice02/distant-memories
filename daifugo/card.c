/*
  FILE NAME: card.c

  DESCRIPTION:
  カード操作に関する関数
*/


#include "daifugo.h"


// カードを分配する
void distribute_card(PLAYER_DATA *player)
{
  CARD_DATA card[MAX_CARD_NUM];   	// カードのデータ 
  char c_mark_table[] = {'S', 'H', 'D', 'C', 'J'};
  int i_mark_table[] =  { 1 ,  2 ,  3 ,  4 ,  0 };
  char c_num_table[][3] = {"A ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "Q ", "K "};
  int i_num_table[] =     { 2  ,  1  ,  13 ,  12 ,  11 ,  10 ,  9  ,  8  ,  7  ,  6  ,  5  ,  4  ,  3  };
  int rand_table[PLAYER_NUM];
  int rand_table_card[MAX_CARD_NUM];
  int i, j, count;
  int tmp1, tmp2, val1, val2;

  // 乱数の種を決定
  srand((unsigned)time(NULL));

  for (i = 0; i < MAX_CARD_NUM; i++) {
	// カードをセット
    card[i].c_mark = c_mark_table[i/MAX_MARK_NUM];
    card[i].i_mark = i_mark_table[i/MAX_MARK_NUM];
    if (i < MAX_CARD_NUM - 2) {
      strcpy(card[i].c_num, c_num_table[i%MAX_MARK_NUM]);
      card[i].i_num = i_num_table[i%MAX_MARK_NUM];
    }
    // ジョーカーは特別に
    else {
      strcpy(card[i].c_num, "K ");
      card[i].i_num = 0;
    }

	// ルックアップテーブルの初期化
    rand_table_card[i] = i;
  }

  // プレイヤが所持しているカードの枚数を初期化
  for (i = 0; i < PLAYER_NUM; i++) {
    player[i].card_num = 0;
  }

  // ランダムに並び替える
  j = MAX_CARD_NUM;
  count = 0;
  while (count < MAX_CARD_NUM) {
    // ルックアップテーブルの初期化
    for (i = 0; i < PLAYER_NUM; i++) {
      rand_table[i] = i;
    }
    // 重複の無いようにランダムに並び替え
    for (i = PLAYER_NUM; i > 0 && count < MAX_CARD_NUM; i--) {
      tmp1 = rand() % i;
      val1 = rand_table[tmp1];
      tmp2 = rand() % j;
      val2 = rand_table_card[tmp2];
      // ダイヤの3を持ってる人を覚えておく
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



// カードをソートする(3→2,(JK)→S→H→D→C) 
void sort_card(PLAYER_DATA *player, int no)
{
  CARD_DATA card_tmp;
  int i, j, k;

  // すべてのプレイヤの手札をソート 
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
  // 指定したプレイヤの手札をソート 
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



// カードを選択させる 
int select_card(PLAYER_DATA *player, CARD_DATA select[])
{
  int pointer[MAX_PLAYER_CARD] = {FALSE};	// 数値はここに一時的に格納される 
  char ch;
  int position_x;
  int count, num, flag;
  int i, j;

  flag = FALSE;
  count = 0;
  position_x = 1;


  // 表示の初期化 
  printf("\x1b[2000D");
  printf("\x1b[K");
  printf("\x1b[5A");
  printf("\x1b[2000D");
  printf("\x1b[K");
  printf("\x1b[5B");
  printf("\x1b[2000D");


  printf(" ▲");		// ▲の表示 
  printf("\x1b[1000C");		// カーソルを一番右へ(1000はあんまりよろしくない…) 

  do {
    ch = getChar();
    switch(ch) {
    case 'd':      // ▲を右へ動かす 
      if (position_x < player->card_num) {
		printf("\x1b[2000D");	// カーソルを一番左へ 
		printf("\x1b[K");	// 一行削除 
		// 位置合わせ 
		for (i = 1; i <= position_x; i++) {
		  printf("      ");
		}
		printf(" ▲");
		printf("\x1b[1000C");	// カーソルを一番右へ 
		position_x++;		// ポジション+1 
      }
      break;

    case 'a':      // ▲を左へ動かす 
      if (position_x > 1) {
		printf("\x1b[2000D");	// カーソルを一番左へ 
		printf("\x1b[K");	// 一行削除 
		// 位置合わせ 
		for (i = 1; i < position_x-1; i++) {
		  printf("      ");
		}
		printf(" ▲");
		printf("\x1b[1000C");	// カーソルを一番右へ 
		position_x--;		// ポジション-1 
      }
      break;

    case ' ':        // ▲のところのカードを選択 
      if (pointer[position_x-1] == FALSE) {
		pointer[position_x-1] = TRUE; // ★をつける 
		count++;
      }
      else {
		pointer[position_x-1] = FALSE; // ★を消す 
		count--;
      }
      printf("\x1b[5A");
      printf("\x1b[2000D");
      printf("\x1b[K");
      for (i = 0; i < player->card_num; i++) {
		if (pointer[i] == TRUE) {
		  printf(" ★");
		}
		else {
		  printf("   ");
		}
		printf("   ");
      }
      // カーソルの位置合わせ 
      printf("\x1b[5B");
      printf("\x1b[1000C");
      break;

    case '\n':	      // 選択終了 
      flag = TRUE;
      break;

    default:
      break;
    }
  } while(flag == FALSE);


  // 選択したカードをコピー 
  num = 0;
  for (i = 0; i < player->card_num; i++) {
    if (pointer[i] == TRUE) {
      select[num] = player->card[i];
      num++;
    }
  }

  return count;
}



// フィールドに出したカードを手札から削除 
void delete_used_card(PLAYER_DATA *player, CARD_DATA select[])
{
  int i, j, k;

  for (i = 0; select[i].i_mark != EMPTY; i++) {
    for (j = 0; j < player->card_num; j++) {
      if (player->card[j].c_mark == select[i].c_mark
		  && strcmp(player->card[j].c_num, select[i].c_num) == 0) {
		// 一要素づつずらしていく 
		for (k = j; k < player->card_num - 1; k++) {
		  player->card[k] = player->card[k+1];
		}
		// 手持ちのカード枚数を減らす 
		(player->card_num)--;
      }
    }
  }

}



// カード交換 
/*
void change_card(PLAYER_DATA *player, int player_no)
{
  
  CARD_DATA select[MAX_FIELD_CARD+1] = { EMPTY };     // 選択したカード 
  int num, No;

  printf("player_no = %d\n",player_no);
  switch(player[player_no].rank) {
  case DAIFUGO:
    printf("3\n");
    No = get_rank_to_playerNo(player, DAIHINMIN);
    printf("4\n");
    do {
      printf(CLEAR_DISPLAY);
      printf("不要なカードを２枚、大貧民(PLAYER-%d)に渡してください。", No);
      disp_my_card(&player[player_no]); // プレイヤの手札を表示 
      init_select_card(select);
      num = select_card(&player[player_no], select); // カードを選択させる 
    } while (num != 2);
    send_card(&player[No], select);
    delete_used_card(&player[player_no], select); // 手札から削除 
    break;
  case FUGO:
    No = get_rank_to_playerNo(player, HINMIN);
    do {
      printf(CLEAR_DISPLAY);
      printf("不要なカードを１枚、貧民(PLAYER-%d)に渡してください。", No);
      disp_my_card(&player[player_no]); // プレイヤの手札を表示 
      init_select_card(select);
      num = select_card(&player[player_no], select); // カードを選択させる 
      printf("\n");
    } while (num != 1);
    send_card(&player[No], select);
    delete_used_card(&player[player_no], select); // 手札から削除 
    break;
  case HINMIN:
    No = get_rank_to_playerNo(player, FUGO);
    init_select_card(select);
    printf("一番強いカードを１枚、富豪(PLAYER-%d)に渡します。", No);
    disp_my_card(&player[player_no]); // プレイヤの手札を表示 
    select[0] = player[player_no].card[player[player_no].card_num-1];
    send_card(&player[No], select);
    delete_used_card(&player[player_no], select); // 手札から削除 
    fflush(NULL);
    sleep(1);
    printf(CLEAR_DISPLAY);
    disp_my_card(&player[player_no]); // プレイヤの手札を表示 
    fflush(NULL);
    sleep(1);
    break;
  case DAIHINMIN:
    No = get_rank_to_playerNo(player, DAIFUGO);
    init_select_card(select);
    printf("上から順に強いカードを２枚、大富豪(PLAYER-%d)に渡します。", No);
    disp_my_card(&player[player_no]); // プレイヤの手札を表示 
    select[0] = player[player_no].card[player[player_no].card_num-1];
    select[1] = player[player_no].card[player[player_no].card_num-2];
    send_card(&player[No], select);
    delete_used_card(&player[player_no], select); // 手札から削除 
    fflush(NULL);
    sleep(1);
    printf(CLEAR_DISPLAY);
    disp_my_card(&player[player_no]); // プレイヤの手札を表示 
    fflush(NULL);
    sleep(1);
    break;
  }
  sort_card(player, No);		// 数字，マークでソート 
  printf(CLEAR_DISPLAY);

}
*/



// 指定したプレイヤにカードを送信 
void send_card(PLAYER_DATA *player, CARD_DATA *select)
{
  int i;

  for (i = 0; select[i].i_mark != EMPTY; i++) {
    player->card[player->card_num] = select[i];
    player->card_num++;
  }

}



// カードデータの初期化 
void init_card_data(CARD_DATA data[])
{
  int i;

  for (i = 0; i < MAX_FIELD_CARD+1; i++) {
    data[i].i_mark = EMPTY;
  }
}



// 選択したカードの初期化
void init_select_card(CARD_DATA *select)
{
  int i;

  for (i = 0; i < MAX_FIELD_CARD+1; i++) {
    select[i].i_mark = EMPTY;
  }

}

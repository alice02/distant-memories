//-----------------------------------------------------------------------
//    ファイル名   ：  client.c
//    概要        ：  クライアント処理に関するモジュール
//    詳細        ：  クライアント側のゲーム進行などを行う．
//
//    履歴        ：  2014/02/18    Kouta ASAI          新規作成
//-----------------------------------------------------------------------


#include "sugoroQ.h"

int proc_flag = FALSE;


//-----------------------------------------------------------------------
//  関数名  ：   print_dot
//  概要    ：  「...」を"それっぽく"表示する関数
//  戻り値  ：  なし
//  引数    ：  なし
//
//  作成    ：  2014/02/18    Kouta ASAI
//-----------------------------------------------------------------------
void print_dot(void)
{
  int i = 0;

  while (proc_flag == FALSE) {
    printf(".");
    usleep(DOT_WAIT_TIME_US);
    fflush(NULL);
    i++;
    if (i == 3) {
      printf("\x1b[3D");
      printf("\x1b[K");
      i = 0;
    }
  }
  proc_flag = TRUE;
}


//-----------------------------------------------------------------------
//  関数名  ：   set_client_data
//  概要    ：  マップを表示する際に使用するデータの初期化
//  戻り値  ：  なし
//  引数    ：  struct board board
//        説明 ゲーム全体の情報を管理している構造体
//  引数    ：  char station[][]
//        説明 駅名を格納する
//  引数    ：  int money
//        説明 駅の価値を格納
//  引数    ：  int stay
//        説明 その駅に誰が止まっているか格納
//  引数    ：  int have
//        説明 その駅は誰が持っているか

//
//  作成    ：  2014/02/17    Yoshitaka TSUMITA, Hikaru NAKASONE
//-----------------------------------------------------------------------
void set_client_data(struct board board, char station[MAP_SIZE][BUF_SIZE], int money[MAP_SIZE], int stay[MAP_SIZE][PLAYER_NUM], int have[MAP_SIZE])
{
  struct station *tmp;
  int i, j;

  tmp = board.s;
  for(i = 0; i < MAP_SIZE; i++){

    strcpy(station[i],tmp->place_name);
    money[i] = tmp->value;
    have[i] = tmp->who_have;
    tmp = tmp->next;
  }

  for(j=0; j<PLAYER_NUM; j++){
    stay[board.p[j].place_id][j] = TRUE;
  }
}


//-----------------------------------------------------------------------
//  関数名  ：   input_name
//  概要    ：  プレイヤ名を入力させる関数
//  戻り値  ：  なし
//  引数    ：  struct board board
//        説明 ゲーム全体の情報を管理している構造体
//  引数    ：  int id
//        説明 プレイヤID
//
//  作成    ：  2014/02/18    Kouta ASAI
//-----------------------------------------------------------------------
void input_name(struct board *board, int id)
{
  char str[BUF_SIZE];

  do {
    printf("名前を入力してください!!!(全角４文字，半角８文字まで): ");
    scanf("%s", str);
  } while(strlen(str) > MAX_NAME_LENGTH);

  strcpy(board->p[id].name ,str);
}

/*---------------------------------------------------
   関数名： hyouji
   概要： サーバ側に各プレイヤの順位と所持金を表示
   戻り値： なし
   引数： struct board *board
       説明 全ての構造体をまとめたもの
   作成： 2014/02/03  Shintaro Ota  新規作成
---------------------------------------------------*/
void hyouji(struct board *board){
  int i;

  /*
    各プレイヤの順位と所持金を表示
   */
  for(i=0; i<PLAYER_NUM; i++){
    printf("%8s: ",board->p[i].name);
    printf("Rank %d  ",board->p[i].rank);
    printf("Money %d\n",board->p[i].money);
  }

}

//-----------------------------------------------------------------------
//  関数名  ：   dice
//  概要    ：  サイコロを振る関数
//  戻り値  ：  サイコロの値
//  引数    ：  なし
//
//  作成    ：  2014/02/18    Kouta ASAI
//-----------------------------------------------------------------------
int dice(void)
{
  int i;
  char ch;
  int num;

  init_keyboard();

  printf("\x1b[%d;%dH", 19, 20);
  printf("サイコロ振りますよー！！  Are you OK? Plase push Enter key.\n");
  do {
    if ( kbhit() ) {
      ch = readkey();
    }
  } while(ch != '\n');

  close_keyboard();

  num = rand()%6+1;

  printf("\x1b[%d;%dH", 21, 20);
  for (i = 0; i < 5; i++) {
    printf(".");
    usleep(DOT_WAIT_TIME_US);
    fflush(NULL);
  }
  printf(" %d !!!\n", num);
  sleep(2);

  return num;
}


int main(void)
{
  struct board board;
  struct client_network_data cnd;
  int player_id;
  int i, j, k;
  char station[MAP_SIZE][BUF_SIZE];
  int money[MAP_SIZE];
  int stay[MAP_SIZE][PLAYER_NUM] = {{FALSE}};
  int have[MAP_SIZE]={-1};
  pthread_t tid;
  int num;

  srand((unsigned)time(NULL));

  // サーバに接続
  network_connect_client(&cnd);

  printf("他のプレイヤの参加を待っています．．．\n\n");

  // playerIDを決定
  num = network_set_player_id_client(&cnd, &player_id);
  network_check_error(num);
  board.p[player_id].id = player_id;
  printf("Your playerID: %d\n", player_id);

  // 名前の入力
  input_name(&board, player_id);

  num = network_send_player_data_client(&cnd, &board, player_id);
  network_check_error(num);

  // サーバからデータの受信
  printf("\nConnecting...\n");

  for (i = 0; i < MAX_TURN; i++) {
    // 初期化
    proc_flag = FALSE;
    printf("%c[2J",ESC);

    // サーバからデータの受信
    num = network_recv_station_data_client(&cnd, &board);
    network_check_error(num);

    num = network_recv_player_quiz_data_client(&cnd, &board);
    network_check_error(num);

    // データのセット
    for(k=0;k<MAP_SIZE;k++){
      for(j=0;j<PLAYER_NUM;j++){
	stay[k][j]=FALSE;
      }
    }
    set_client_data(board, station, money, stay, have);

    printf("%c[2J",ESC);
    DispMap(station,money,have,stay);
    Status(board);

    // サイコロを振る
    board.p[player_id].dice = dice();

    printf("%c[2J",ESC);
    DispMap(station,money,have,stay);
    Status(board);
    quiz(&board, player_id);
    sleep(1);
    printf("%c[2J",ESC);

    printf("通信中です\n");
    pthread_create(&tid, NULL, print_dot, NULL);
    num = network_send_player_data_client(&cnd, &board, player_id);
    network_check_error(num);
    proc_flag = TRUE;
    pthread_join(tid, NULL);
    free_station(&board);
    printf("%c[2J",ESC);
  }

  num = network_recv_player_quiz_data_client(&cnd, &board);
  network_check_error(num);
  hyouji(&board);
  return 0;
}

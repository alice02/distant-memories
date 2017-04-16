/*---------------------------------------------------
   ファイル名： server.c
   概要： サーバの役割をするモジュール
   詳細： 各クライアントからデータを受け取り，ゲームの進行を行う
   履歴： 2014/02/18  Shintaro Ota  新規作成
---------------------------------------------------*/

#include "sugoroQ.h"

/*---------------------------------------------------
   関数名： p_keisan
   概要： 各プレイヤの解答が正解か確認を行い，
         正解であればサイコロの出た目だけ進む
   戻り値： なし
   引数： struct board *board
       説明 全ての構造体をまとめたもの
   作成： 2014/02/18  Shintaro Ota  新規作成
---------------------------------------------------*/
void p_keisan(struct board *board){
  int i;
  struct station *tmp;

  /*
    正解・不正解を確認し，正解であればサイコロを振る
  */
  printf("\n*** player quiz status ***\n");
  for(i=0; i<PLAYER_NUM; i++){
    if(board->p[i].p_answer==(board->q.answer-'0')){
      board->p[i].p_point = board->p[i].dice;
      board->p[i].p_point += (10-board->p[i].answer_time)/2;
      board->p[i].money += (10-board->p[i].answer_time)*10;
      printf("player %d is correct!!\n", i);
      printf("forward %d stations\n", board->p[i].p_point);
    }
    else{
      board->p[i].p_point=0;
    }
  }


  /*
    各プレイヤはサイコロの出た目だけ進む
  */
  for(i=0; i<PLAYER_NUM; i++){
    board->p[i].place_id += board->p[i].p_point;
    board->p[i].place_id %= MAP_SIZE;
  }

}

/*---------------------------------------------------
   関数名： init
   概要： 構造体のメンバを初期化
   戻り値： なし
   引数： struct board *board
       説明 全ての構造体をまとめたもの
   作成： 2014/01/27  Shintaro Ota  新規作成
---------------------------------------------------*/
void init(struct board *board){
  int i;
  char str[BUF_SIZE];
  int start_place_id[4]={3,12,18,27};
  /*
    構造体のメンバを初期化
  */
  for(i=0; i<PLAYER_NUM; i++){
    board->p[i].p_answer=0;
    board->p[i].answer_time=0;
    board->p[i].place_id=start_place_id[i];
    board->p[i].rank=1;
    board->p[i].money=5000;
  }

}

/*---------------------------------------------------
   関数名： ranking
   概要： 各プレイヤの所持金と所持駅から順位付け
   戻り値： なし
   引数： struct board *board
       説明 全ての構造体をまとめたもの
   作成： 2014/01/27  Shintaro Ota  新規作成
---------------------------------------------------*/
void ranking(struct board *board){
  int i,j;
  struct station *tmp;
  tmp = board->s;

  /*
    各プレイヤの所持駅を所持金に換算
   */
  for(i=0; i<PLAYER_NUM; i++){
    for(j=0; j<MAP_SIZE; j++){
      tmp=r_access_station(tmp,j);
      if(tmp->who_have==i){
	board->p[i].money+=tmp->value;
      }
    }
  }

  /*
    各プレイヤの所持金から順位付け
  */
  for(i=0; i<PLAYER_NUM; i++){
    for(j=0; j<PLAYER_NUM; j++){
      if(i!=j){
	if(board->p[i].money<board->p[j].money){
	  board->p[i].rank++;
	}
      }
    }
  }
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
    printf("%s: ",board->p[i].name);
    printf("rank %d  ",board->p[i].rank);
    printf("money %d\n",board->p[i].money);
  }

}

/*---------------------------------------------------
   関数名： baibai
   概要： 各プレイヤが移動先の駅を買うようにし，
         毎ターン所持駅からお金が入る
   戻り値： なし
   引数： struct board *board
       説明 全ての構造体をまとめたもの
   作成： 2014/02/03  Shintaro Ota  新規作成
---------------------------------------------------*/
void baibai(struct board *board){
  int i;
  struct station *tmp;

  /*
    各プレイヤが移動先の駅を買う
   */
  for(i=0; i<PLAYER_NUM; i++){
    //不正解の場合，移動しないため駅を買わないようにする
    if(board->p[i].p_answer==(board->q.answer-'0')){
      tmp = board->s;
      tmp=r_access_station(tmp,board->p[i].place_id);
      //移動先の駅が誰も所持していない場合
      if(tmp->who_have==-1){
	board->p[i].money-=tmp->value;
	tmp->who_have=i;
      }
      //他のプレイヤが所持していた場合
      else if(tmp->who_have!=i){
	tmp->value*=1.5;
	board->p[i].money-=tmp->value;
	board->p[tmp->who_have].money+=tmp->value*0.8;
	tmp->who_have=i;
      }
      //自分の所持している駅の場合
      else if(tmp->who_have==i){
	board->p[i].money+=tmp->value;
      }
    }
  }

  tmp = board->s;
  /*
    各プレイヤに毎ターン所持駅からお金が入る
   */
  for(i=0; i<MAP_SIZE; i++){
    if(tmp->who_have!=-1){
      board->p[tmp->who_have].money+=tmp->value*0.2;
    }
    tmp=tmp->next;
  }

}

int main(void)
{
  struct server_network_data snd;
  int place=0;
  struct board board;
  int num;
  int i, j;

  srand((unsigned)time(NULL));

  network_init_server(&snd);

  printf("プレイヤの受付を終了しました．\n");
  printf("Sending data...\n");

  num = network_send_player_id_server(&snd);
  network_check_error(num);

  init_station_server(&board);

  num = network_recv_player_data_server(&snd, &board);
  network_check_error(num);

  init(&board);


  /*
    ターン終了までゲームを行う
  */
  printf("Start GAME!!\n\n");
  for (i = 0; i < MAX_TURN; i++) {
    SetQuiz(&board);
    board.q.turn=i+1;
    printf("turn : %2d\n", board.q.turn, i);

    printf("\n*** player ***\n");
    print_player_all(board);
    printf("\n*** station ***\n");
    print_station(board);
    printf("\n*** quiz ***\n");
    printf("quiz: %s\n", board.q.mondai);
    printf("selection:\n");
    for (j = 0; j < SELECTION_NUM; j++) {
      printf("%d. %s\n", j+1, board.q.sentaku[j]);
    }
    printf("answer: %c\n", board.q.answer);


    printf("Sending data...\n");
    num = network_send_station_data_server(&snd, &board);
    network_check_error(num);

    num = network_send_player_quiz_data_server(&snd, &board);
    network_check_error(num);

    printf("Receiving data...\n");
    num = network_recv_player_data_server(&snd, &board);
    network_check_error(num);

    p_keisan(&board);

    baibai(&board);
  }

  ranking(&board);
  num = network_send_player_quiz_data_server(&snd, &board);
  network_check_error(num);

  hyouji(&board);

  return 0;
}

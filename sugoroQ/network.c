//-----------------------------------------------------------------------
//    ファイル名  ：  network.c
//    概要        ：  ソケット通信に関するモジュール
//    詳細        ：  サーバ・クライアントからこのモジュールの関数を
//                    呼び出すことにより，ソケット通信を可能にする
//
//    履歴        ：  2014/01/06    Kouta ASAI          新規作成
//-----------------------------------------------------------------------


#include "sugoroQ.h"


//-----------------------------------------------------------------------
//  関数名  ：  network_init_server
//  概要    ：  サーバ側のソケット通信初期化処理
//              PLAYER_NUMの値までクライアントが接続するのを待つ
//  戻り値  ：  なし
//  引数    ：  struct server_network_data *snd
//        説明  サーバでソケット通信に必要なデータ(ポインタ)
//
//  作成    ：  2014/01/06    Kouta ASAI
//-----------------------------------------------------------------------
void network_init_server(struct server_network_data *nd)
{
  fd_set readfds2;
  int max = 0;         // max num of used socket
  int n = 0;
  int len;
  int clilen;               /* client length */
  struct sockaddr_in saddr; /* サーバ側(自分)のアドレス情報 */
  struct sockaddr_in caddr; /* クライアント側のアドレス情報を入れるところ */
  char str[1024];           /* string buffer */
  int i, j;                 /* loop counter */
  int msglen;
  int count;
  int yes = 1;

  // ソケットを作る。
  // このソケットはINETドメインでストリーム型(コネクション型) 。
  if ((nd->s[0] = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  // saddrの中身を0にしておかないと、bind()でエラーが起こることがある
  bzero((char *)&saddr, sizeof(saddr));

  // ソケットに名前をつける bind()
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = INADDR_ANY;
  saddr.sin_port = htons(PORT); // 定数PORTは#defineしたもの

  // connection refusedにならないようにする
  setsockopt(nd->s[0], SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(yes));

  if ((bind(nd->s[0], (struct sockaddr *)&saddr, sizeof(saddr))) == -1) {
    perror("bind");
    exit(1);
  }

  // 接続されるのを待つ listen()
  // 第2引数の値を大きくする
  if ((listen(nd->s[0], SOCK_MAX)) == -1) {
    perror("listen");
    exit(1);
  }
  max = 1;   // s[0] is ready


  // PLAYER_NUMの値までclientが接続したら、初期化終了
  while (max < PLAYER_NUM+1) {

    FD_ZERO(&(nd->readfds));    // fdsの初期化

    // すでにクライアントと接続されているソケットのビットを
    // セットしてselect()の検査対象にする。
    for (i = 0; i < max; i++) {
      if (nd->s[i] != UNUSED) {
	FD_SET(nd->s[i], &(nd->readfds));
      }
    }

    // 新たな接続要求があった場合は、s[0]のビットが立つ。
    // 以下では新たな接続の受け付けを行う。
    if (FD_ISSET(nd->s[0], &(nd->readfds)) != 0) {
      printf("Waiting for connection...\n");
      // 接続を確立する accept()
      len = sizeof(caddr);
      nd->s[max] = accept(nd->s[0], (struct sockaddr *)&caddr, &len);
      if (nd->s[max] == -1) {
	perror(NULL);
	exit(1);
      }
      if (max < SOCK_MAX) {
	printf("client accepted : %d  (%d/%d)\n", max, max, PLAYER_NUM);
	max++;
      } else {
	printf("refuse connection.\n");
	strcpy(str, "Server is too busy.\n");
	write(nd->s[max], str, strlen(str));
	close(nd->s[max]);
      }
    }
  }
}



//-----------------------------------------------------------------------
//  関数名  ：  network_connect_client
//  概要    ：  クライアントからサーバへの接続処理
//              サーバのホスト名を入力させ，サーバに接続する
//              ホスト名を入力させた後，network_init_client()を呼び出す
//  戻り値  ：  なし
//  引数    ：  struct client_network_data *cnd
//        説明  クライアントでソケット通信に必要なデータ(ポインタ)
//
//  作成    ：  2014/01/06    Kouta ASAI
//-----------------------------------------------------------------------
void network_connect_client(struct client_network_data *cnd)
{
  int i_ret;
  char buf[255];

  do {
    // ホスト名の入力
    printf("サーバーのホスト名を入力してください．(q で終了)\n");
    fgets(buf, sizeof(buf), stdin);

    // 'q'が入力されたらプログラムを終了する
    if (strcmp(buf, "q") == TRUE) {
      exit(EXIT_FAILURE);
    }

    sscanf(buf, "%s", cnd->host);

    i_ret = network_init_client(cnd);  // サーバへ接続を試みる
  } while(i_ret == EXIT_FAILURE);  // 指定したホストへ接続できない場合はループ

}



//-----------------------------------------------------------------------
//  関数名  ：  network_init_client
//  概要    ：  クライアントのソケット通信初期化処理
//              クライアントからサーバへ接続を試みる
//  戻り値  ：  EXIT_FAILURE:接続失敗，EXIT_SUCCESS:接続成功
//  引数    ：  struct client_network_data *cnd
//        説明  クライアントでソケット通信に必要なデータ(ポインタ)
//
//  作成    ：  2014/01/06    Kouta ASAI
//-----------------------------------------------------------------------
int network_init_client(struct client_network_data *cnd)
{
  struct sockaddr_in    addr;
  struct hostent *hp;


  /*
   *  ソケットを作る。このソケットはUNIXドメインで、ストリーム型ソケット。
   */
  if ((cnd->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  /* 
   * addrの中身を0にしておかないと、bind()でエラーが起こることがある
   */
  bzero((char *)&addr, sizeof(addr));

  /*
   * ソケットの名前を入れておく
   */

  hp = gethostbyname(cnd->host);
  if (hp == NULL) {
    perror("No such host");
    return EXIT_FAILURE;
  }
  bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);

  /*
   *  サーバーとの接続を試みる。これが成功するためには、サーバーがすでに
   *  このアドレスをbind()して、listen()を発行していなければならない。
   */

  if (connect((cnd->fd), (struct sockaddr *)&addr, sizeof(addr)) < 0){
    perror("connect");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}



//-----------------------------------------------------------------------
//  関数名  ：  network_recv_player_quiz_data_client
//  概要    ：  サーバからplayer構造体(全プレイヤのデータ)とquiz構造体を受け取る
//              クライアントから呼び出す関数
//  戻り値  ：  -1:受信失敗，0:接続切断，その他:最後に受信したデータのバイト数
//  引数    ：  struct client_network_data *cnd
//        説明  クライアントでソケット通信に必要なデータ(ポインタ)
//  引数    ：  struct board *board
//        説明  ゲーム全体の情報を格納しているboard構造体(ポインタ)
//
//  作成    ：  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
// player構造体とquiz構造体を受信(client用)
int network_recv_player_quiz_data_client(struct client_network_data *cnd, struct board *board)
{
  int i;
  int size;

  // player構造体を受信
  for (i = 0; i < PLAYER_NUM; i++) { // player構造体は全プレイヤ分受信
    size = recv(cnd->fd, &(board->p[i]), sizeof(struct player), 0);
    if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // 受信に失敗したらreturn
      return size;
    }
    usleep(WAIT_TIME);  // これがあると通信が安定(?)
  }
  // quiz構造体を受信
  size = recv(cnd->fd, &(board->q), sizeof(struct quiz), 0);

  return size;
}



//-----------------------------------------------------------------------
//  関数名  ：  network_send_player_data_client
//  概要    ：  サーバにplayer構造体を送る(自分のプレイデータのみ)
//              クライアントから呼び出す関数
//  戻り値  ：  -1:送信失敗，0:接続切断，その他:送信したデータのバイト数
//  引数    ：  struct client_network_data *cnd
//        説明  クライアントでソケット通信に必要なデータ(ポインタ)
//  引数    ：  struct board *board
//        説明  ゲーム全体の情報を格納しているboard構造体(ポインタ)
//  引数    ：  int id
//        説明  プレイヤID(0〜3のどれか)
//
//  作成    ：  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_send_player_data_client(struct client_network_data *cnd, struct board *board, int id)
{
  int recv_id;
  int size;
  int i;

  for (i = 0; i < PLAYER_NUM; i++) { // 全ユーザに対して通信を行うので，PLAYER_NUMの値だけループ
    // サーバが要求しているプレイヤID
    size = recv(cnd->fd, &recv_id, sizeof(int), 0);
    if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // 送信に失敗したらreturn
      return size;
    }

    // 受信したIDとプレイヤIDが一致した者のみデータを送れる
    // 送るのは自分のプレイデータのみ(board.p[player_id])
    if (recv_id == id) {
      size = send(cnd->fd, &(board->p[id]), sizeof(struct player), 0);
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  関数名  ：  network_recv_player_data_server
//  概要    ：  各クライアントからplayer構造体を受け取る
//              サーバから呼び出す関数
//  戻り値  ：  -1:受信失敗，0:接続切断，その他:最後に受信したデータのバイト数
//  引数    ：  struct server_network_data *snd
//        説明  サーバでソケット通信に必要なデータ(ポインタ)
//  引数    ：  struct board *board
//        説明  ゲーム全体の情報を格納しているboard構造体(ポインタ)
//
//  作成    ：  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_recv_player_data_server(struct server_network_data *snd, struct board *board)
{
  int i, j;
  int size;
  int id;

  for (i = 0; i < PLAYER_NUM+1; i++) {
    if (snd->s[i] != UNUSED) {
      FD_SET(snd->s[i], &(snd->readfds));
    }
  }


  for (i = 0; i < PLAYER_NUM; i++) {
    id = i;  // サーバが要求するプレイヤID

    // 全クライアントにサーバが要求しているプレイヤIDを知らせる
    for (j = 0; j < PLAYER_NUM; j++) {
      if (snd->s[j+1] != UNUSED) {
	size = send(snd->s[j+1], &id, sizeof(int), 0);
	if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // 受信に失敗したらreturn
	  return size;
	}

      }
    }

    if (snd->s[id+1] != UNUSED) {
      if (FD_ISSET(snd->s[id+1], &(snd->readfds))) {
	// 指定したplayerのデータのみ受け取る
	size = recv(snd->s[i+1], &(board->p[id]), sizeof(struct player), 0);
	if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // 受信に失敗したらreturn
	  return size;
	}

      }
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  関数名  ：  network_send_player_quiz_data_server
//  概要    ：  各クライアントにplayer構造体(全プレイデータ)とquiz構造体を送る
//              サーバから呼び出す関数
//  戻り値  ：  -1:送信失敗，0:接続切断，その他:最後に送信したデータのバイト数
//  引数    ：  struct server_network_data *snd
//        説明  サーバでソケット通信に必要なデータ(ポインタ)
//  引数    ：  struct board *board
//        説明  ゲーム全体の情報を格納しているboard構造体(ポインタ)
//
//  作成    ：  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_send_player_quiz_data_server(struct server_network_data *snd, struct board *board)
{
  int size;
  int i, j;

  for (i = 0; i < PLAYER_NUM; i++) {  // 全クライアントに対して送信する
    if (snd->s[i+1] != UNUSED) {
      for (j = 0; j < PLAYER_NUM; j++) {  // 全プレイヤのプレイデータを送信
	size = send(snd->s[i+1], &(board->p[j]), sizeof(struct player), 0);
	if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // 送信に失敗したらreturn
	  return size;
	}
	usleep(WAIT_TIME);
      }
      send(snd->s[i+1], &(board->q), sizeof(struct quiz), 0);
      if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // 送信に失敗したらreturn
	return size;
      }
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  関数名  ：  network_set_player_id_client
//  概要    ：  プレイヤIDをサーバから受け取る
//              クライアントから呼び出す関数
//  戻り値  ：  -1:送信失敗，0:接続切断，その他:受信したデータのバイト数
//  引数    ：  struct client_network_data *cnd
//        説明  クライアントでソケット通信に必要なデータ(ポインタ)
//  引数    ：  int *id
//        説明  プレイヤID(ポインタ)
//
//  作成    ：  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_set_player_id_client(struct client_network_data *cnd, int *id)
{
  int size;

  size = recv(cnd->fd, id, sizeof(int), 0);
  
  return size;
}



//-----------------------------------------------------------------------
//  関数名  ：  network_send_player_id_server
//  概要    ：  プレイヤIDをクライアントに送信する
//              サーバから呼び出す関数
//  戻り値  ：  -1:送信失敗，0:接続切断，その他:最後に送信したデータのバイト数
//  引数    ：  struct server_network_data *snd
//        説明  サーバでソケット通信に必要なデータ(ポインタ)
//
//  作成    ：  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_send_player_id_server(struct server_network_data *snd)
{
  int i;
  int size;

  for (i = 0; i < PLAYER_NUM; i++) {
    if (snd->s[i+1] != UNUSED) {
      size = send(snd->s[i+1], &i, sizeof(int), 0);
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  関数名  ：  network_send_station_data_server
//  概要    ：  駅名などの駅のデータをクライアントに送信する
//             サーバから呼び出す関数
//  戻り値  ：  -1:送信失敗，0:接続切断，その他:送信したデータのバイト数
//  引数    ：  struct server_network_data *snd
//        説明  サーバでソケット通信に必要なデータ(ポインタ)
//  引数    ：  struct board *board
//        説明  ゲーム全体の情報を格納しているboard構造体(ポインタ)
//
//  作成    ：  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_send_station_data_server(struct server_network_data *snd, struct board *board)
{
  int i, j;
  struct station *station;
  int size;

  for (i = 0; i < PLAYER_NUM; i++) {
    station = board->s;
    if (snd->s[i+1] != UNUSED) {
      for (j = 0; j < MAP_SIZE; j++) {
	size = send(snd->s[i+1], &(station->place_name), sizeof(char)*256, 0);
	size = send(snd->s[i+1], &(station->value), sizeof(int), 0);
	size = send(snd->s[i+1], &(station->who_have), sizeof(int), 0);
	usleep(WAIT_TIME);  // これがあると通信が安定(?)
	station = station->next;
      }
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  関数名  ：  network_recv_station_data_client
//  概要    ：  駅名などの駅のデータをサーバから受信する
//             クライアントから呼び出す関数
//  戻り値  ：  -1:送信失敗，0:接続切断，その他:受信したデータのバイト数
//  引数    ：  struct client_network_data *cnd
//        説明  クライアントでソケット通信に必要なデータ(ポインタ)
//  引数    ：  struct board *board
//        説明  ゲーム全体の情報を格納しているboard構造体(ポインタ)
//
//  作成    ：  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_recv_station_data_client(struct client_network_data *cnd, struct board *board)
{
  int j;
  char name[MAP_SIZE][BUF_SIZE];
  int value[MAP_SIZE];
  int have[MAP_SIZE];
  int size;


  for (j = 0; j < MAP_SIZE; j++) {
    size = recv(cnd->fd, name[j], sizeof(char)*256, 0);
    size = recv(cnd->fd, &(value[j]), sizeof(int), 0);
    size = recv(cnd->fd, &(have[j]), sizeof(int), 0);
    usleep(WAIT_TIME);  // これがあると通信が安定(?)
  }

  init_station_client(board, name, value, have);

  return size;
}



//-----------------------------------------------------------------------
//  関数名  ：  network_check_error
//  概要    ：  通信でエラーが発生したらメッセージを表示し強制終了する
//  戻り値  ：  なし
//  引数    ：  int num
//        説明  recv or send関数の戻り値
//
//  作成    ：  2014/02/17    Kouta ASAI
//-----------------------------------------------------------------------
void network_check_error(int num)
{
  if (num == NETWORK_ERROR) {
    printf("通信エラーが発生しました。プログラムを終了します。\n");
    exit(100);
  }
  else if (num == NETWORK_DISCONNECTED) {
    printf("サーバーとの接続が切断されました。プログラムを終了します。\n");
    exit(101);
  }
}

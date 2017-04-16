#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "network.h"



// ---------------------------------
//       ●● マクロの宣言 ●●
// ---------------------------------

#define TRUE 1
#define FALSE 0

// check_input()の戻り値
#define ERROR 1    //正しくない入力
#define CORRECT 0  //正しい入力

// ゲームの核となる値(POINT以外は変えちゃだめ)
#define POINT  6            /* このポイントに誰かが到達した時点で終了 */
#define PLAYER_NUM 4		/* プレイヤの人数(4以外はマズイ...) */
#define MAX_CARD_NUM 54  	/* カードの最大枚数(13*4+2) */
#define MAX_MARK_NUM 13		/* 1つのマークにつき13枚 */
#define MAX_PLAYER_CARD 14	/* プレイヤの手札の最大枚数 */
#define MAX_FIELD_CARD 14	/* フィールドに一度に出せる枚数(3 4 5 ... K A 2 JK) */

/* 階級(数字は特に意味なし) */
#define DAIFUGO 30		/* 大富豪 */
#define FUGO 20			/* 富豪 */
#define HINMIN 10		/* 貧民 */
#define DAIHINMIN 0		/* 大貧民 */
#define HEIMIN -10		/* 平民 */

// カラの状態を表す(便宜上)
#define EMPTY -1
#define NOBODY -10
#define ALL_PLAYERS 1000

/* プレイヤの状態 */
#define PLAYING 100      // 今プレイしている
#define END 200          // あがり状態
#define DIA3 300         // ダイヤ3を持っている
#define FOUL_PLAY 400    // 反則あがりをした
#define MIYAKO_OCHI 500  // 都落ちした

/* フィールドの状態 */
#define ORDINARY 0  // ノーマル状態
#define KAIDAN 1    // 階段
#define KAKUMEI 2   // 革命
#define SHIBARI 3   // しばり


/* エスケープシーケンス(色制御) */
/* 文字色 */
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define DEFAULT_COLOR "\x1b[39m"

/* 属性 */
#define CLEAR_ATTRIBUTE "\x1b[0m"
#define BOLD "\x1b[1m"
#define UNDER_LINE "\x1b[4m"
#define HANTEN "\x1b[7m"

/* エスケープシーケンス(画面制御) */
#define CLEAR_DISPLAY "\x1b[2J"	/* 画面クリア */




// ---------------------------------
//       ●● 構造体の宣言 ●●
// ---------------------------------

/* カード１枚の情報 */
typedef struct {
  int i_mark;	    /* マークの強さ(0~4,J->S->H->D->C) */
  char c_mark;      /* 表示用 */
  int i_num;        /* カード(数字)の強さ(2->1->13->...->3) */
  char c_num[3];    /* 表示用 */
} CARD_DATA;

/* プレイヤの情報 */
typedef struct {
  int card_num;	    /* 現在の手札の枚数 */
  CARD_DATA card[MAX_PLAYER_CARD + 4];  /* 持ってるカードのデータ */
  int status;	    /* プレイ状態(PLAYING, END) */
  int pass;	        /* パスしたか(TRUE:パスした, FALSE:パスしてない) */
  int old_rank;	    /* old階級(大富豪, 富豪, 貧民, 大貧民) */
  int new_rank;	    /* new階級(大富豪, 富豪, 貧民, 大貧民) */
  int point;	    /* ポイントを記録 */
  int rule_flag;    /* ルール関係の情報を格納 */
} PLAYER_DATA;




// ---------------------------------
//    ●● 関数プロトタイプ宣言 ●●
// ---------------------------------

// ↓↓ card.c ↓↓
// カードを分配する
void distribute_card(PLAYER_DATA *player);

// カードをソートする(3→2,(JK)→S→H→D→C)
void sort_card(PLAYER_DATA *player, int no);

// カードを選択させる
int select_card(PLAYER_DATA *player, CARD_DATA select[]);

// フィールドに出したカードを手札から削除
void delete_used_card(PLAYER_DATA *player, CARD_DATA select[]);

// カード交換
void change_card(PLAYER_DATA *player, int player_no);

// 指定したプレイヤにカードを送信
void send_card(PLAYER_DATA *player, CARD_DATA *select);

// カードデータの初期化
void init_card_data(CARD_DATA data[]);

// 選択したカードの初期化
void init_select_card(CARD_DATA *select);


// ↓↓ disp.c ↓↓
// オープニングメッセージ
void opening(void);

// フィールドを表示
void disp_field(PLAYER_DATA *player, CARD_DATA *field, int num, int turn, int field_status);

// 全員の手札を表示(サーバー向け)
void disp_card_all(PLAYER_DATA *player);

// 自分の手札だけ表示(クライアント向け)
void disp_my_card(PLAYER_DATA *player);

// 対戦の結果を表示
void disp_result(PLAYER_DATA *player);

// "ALL Players PASS!!!"を表示
void disp_all_pass_message(void);

// "PASS"を表示
void disp_pass_message(void);

// "8切り!!"を表示
void disp_yagiri_message(void);

// "革命!!!"を表示
void disp_kakumei_message(void);


// ↓↓ rule.c ↓↓
// ジョーカーを探す
int joker_search(CARD_DATA select[], int num, int pos);

// 選択したカードがフィールドに出せるか確認
int check_input (CARD_DATA field[], CARD_DATA select[], int num, int old_num);

// 反則あがりチェック
int check_foul_play(CARD_DATA *field, int field_status, int select_num);

// 革命を起こす
void kakumei(PLAYER_DATA *data, int field_status);

// 8切り
int yagiri(CARD_DATA *select);


// ↓↓ daifugo_server.c ↓↓
// 初期化
void initialization(PLAYER_DATA *player, int count, int s[]);

/* ポイントを計算 */
int calc_point(PLAYER_DATA *player);

// 誰からゲームを開始するか決める
int set_first_player(PLAYER_DATA *player, int game_count, int s[]);

// 大富豪のメインループ
void game(PLAYER_DATA *player, int game_count, int s[], fd_set *readfds);

/* 次の人のターンにする */
int set_next_turn(PLAYER_DATA *player, int turn);

/* 階級を判定 */
void judge_rank(PLAYER_DATA *player, int turn, int count, int foul_play_count, int miyako_ochi);


// ↓↓ rule.c ↓↓
/* 階級からプレイヤNoを取得(new_rank) */
int get_rank_to_playerNo_new(PLAYER_DATA *player, int rank);

/* 階級からプレイヤNoを取得(old_rank) */
int get_rank_to_playerNo_old(PLAYER_DATA *player, int rank);

// パスフラグの初期化
void init_pass_flag(PLAYER_DATA *player);

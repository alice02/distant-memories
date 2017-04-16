#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "robots.h"


int main(int argc, char *argv[])
{
  struct zahyou Rlist_header;	/* ロボットの座標(連結リスト) */
  struct zahyou *Rlist_last;
  struct zahyou Slist_header;	/* スクラップの座標(連結リスト) */
  struct zahyou *Slist_last;
  struct zahyou player;		/* プレイヤの座標 */
  int level = 1;	/* プレイしているレベル(初期値:1) */
  int robots_num;	/* プレイしているレベルでのロボットの個数の初期値 */
  int remaining;	/* 残りのロボット数 */
  int score = 0;	/* スコア */
  int wait_flag;	/* 'w'キーを押した時の動作変更用フラグ */
  int val, judge;	/* 戻り値を格納する変数 */

  
  /* スコア表示モード (-s)*/
  if (argc-1 == 1) {
    if (argv[1][0] == '-' && argv[1][1] == 's') {
      print_score();
      exit(0);
    }
  }

  srand((unsigned)time(NULL)); 

  do {
    /* リストの初期化 */
    Rlist_header.next = NULL;
    Rlist_last = &Rlist_header;
    Slist_header.next = NULL;
    Slist_last = &Slist_header;

    /* 初期化 */
    initialization(&Rlist_header, Rlist_last, &player, level, &robots_num, &remaining);
    wait_flag = FALSE;

    /* メインループ */
    do {

      disp_field(&Rlist_header, player, &Slist_header); /* フィールドの表示 */
      if (wait_flag == TRUE) {
	usleep(100000);
      }

      printf("(level:%d, score:%d):?", level, score); /* レベル、スコアの表示 */

      if (wait_flag == FALSE) {
	val = move_player(&player, &Rlist_header, &Slist_header); /* プレイヤの移動 */
      }

      if (val == NORMAL) {
	move_robots(&Rlist_header, player); /* ロボットの移動 */
      }
      else if (val == WAIT_FOR_END) {
	wait_flag = TRUE;
	val = NORMAL;
      }

      judge = crash_judge(&Rlist_header, player, &Slist_header, Slist_last, robots_num, &remaining, &score); /* 衝突判定 */

    } while (judge == ALIVE && remaining != 0);

    /* ゲームクリアの場合 */
    if (judge == ALIVE) {
      score += level*10;	/* スコアの更新 */
      level++;			/* レベルの更新 */
      stage_clear();		/* メッセージを表示 */
    }
    /* ゲームオーバーの場合 */
    else {
      game_over();		/* メッセージを表示 */
    }

  } while (judge == ALIVE);

  save_score(score, level);

  return 0;
}

/*
  FILE NAME: player.c

  DESCRIPTION:
  いろんな関数の寄せ集め(どこのファイルに入れようか悩んだやつをまとめた)
*/


#include "daifugo.h"


/* 階級からプレイヤNoを取得(new_rank) */
int get_rank_to_playerNo_new(PLAYER_DATA *player, int rank)
{
  int i, num;

  for (i = 0; i < PLAYER_NUM; i++) {
    if (player[i].new_rank == rank) {
      num = i;
	  printf("in:%d, out%d\n", rank, i);
    }
  }

  return num;
}



/* 階級からプレイヤNoを取得(old_rank) */
int get_rank_to_playerNo_old(PLAYER_DATA *player, int rank)
{
  int i, num;

  for (i = 0; i < PLAYER_NUM; i++) {
    if (player[i].old_rank == rank) {
      num = i;
	  printf("in:%d, out%d\n", rank, i);
    }
  }

  return num;
}



// パスフラグの初期化
void init_pass_flag(PLAYER_DATA *player)
{
  int i;

  for (i = 0; i < PLAYER_NUM; i++) {
    player[i].pass = FALSE;
  }

}

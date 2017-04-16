#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>


#define TRUE 1
#define FALSE 0

// バッファサイズ
#define BUF_SIZE 256


// プレイヤの人数(4人固定)
#define PLAYER_NUM 4
// マップサイズ
#define MAP_SIZE 30
// 終了ターン数
#define MAX_TURN 5
// 選択肢の数
#define SELECTION_NUM 4 
// クイズデータのファイル
#define QUIZFILENAME "quiz.csv"
// クイズ問題数
#define QUIZ_NUM 200


struct player {
  int id;
  char name[BUF_SIZE];
  int place_id;
  int answer_time;
  int p_answer;
  int p_point;
  int rank;
  int money;
  int dice;
};


struct quiz {
  char mondai[BUF_SIZE*4];
  char sentaku[SELECTION_NUM][BUF_SIZE];
  char answer;
  int point;
  int row;
  int turn;
};


struct station {
  char place_name[BUF_SIZE];
  int place_id;
  int value;
  int who_have;
  struct station *next;
  struct station *prev;
};


struct board {
  struct player p[PLAYER_NUM];
  struct quiz q;
  struct station *s;
};

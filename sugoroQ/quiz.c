//-----------------------------------------------------------------------------
//    ファイル名  ：   quiz.c
//    概要       ：   クイズテキストから問題，選択肢，答えを持ってくる．
//    詳細       ：   クイズテキストから一行読み込みを行い，「問題，選択肢，答え」を持ってくる//                   ．それぞれ”，”で区切られているため，それぞれを分解し各変数に代入する．
//
//    履歴       ：   2014/02/18    Yousuke Nakanishi          新規作成
//-----------------------------------------------------------------------------

#include "sugoroQ.h"

//-----------------------------------------------------------------------------
//    関数名     ：   SetQuiz
//    概要       ：   クイズテキストから読み込む行数をランダムに決める．
//    戻り値     ：   なし   
//    引数       ：   struct board *board
//              説明  ゲーム全体の情報を格納しているboard構造体(ポインタ)
//    作成       ：   2014/02/18    Yousuke Nakanishi
//-----------------------------------------------------------------------------

void SetQuiz(struct board *board)
{
  char str[BUF_SIZE*4];
  static int q_flag[QUIZ_NUM] = { FALSE };

  do {   //クイズテキストから読み込む行数をランダムに決める
    board->q.row = rand() % QUIZ_NUM + 1; 
  } while(q_flag[board->q.row] == TRUE);
  q_flag[board->q.row] = TRUE; //同じ問題を表示させないようにする
  
  ReturnStrings(QUIZFILENAME, board->q.row, str, BUF_SIZE); //クイズテキストから一行読み込む
  
  printf("%s\n", str);

  SplitData(str, &(board->q));
}

//-----------------------------------------------------------------------------
//    関数名     ：   ReturnStrings
//    概要       ：   クイズテキストから指定された1行を読み込む．
//    戻り値     ：   0：正常終了,-1：ファイルオープン失敗,-2：指定された行のデータ取得に失敗
//    引数       ：   const char* path
//              説明  クイズテキストの名前
//    引数       ：   const int num
//              説明  取得した行番号
//    引数       ：   char* buf
//              説明  取得したデータ格納先へのポインタ
//    引数       ：   const int size
//              説明  バッファのサイズ(要素数)
//
//    作成       ：   2014/02/18    Yousuke Nakanishi
//-----------------------------------------------------------------------------

int ReturnStrings(const char* path, const int num, char* buf, const int size)
{                              /*ファイルの中身を1行ずつ読み込む*/
  int cnt = 0;
  FILE* file = NULL;

  if((file = fopen(path, "r")) == NULL)
  {
    printf("%sファイルが開けません．\n",path);
    return -1;
  }

  while (fgets(buf, size, file) != NULL && num > ++cnt); 
  fclose(file);

  if(num != cnt)
  {
    for (cnt = 0; cnt < size; ++cnt)
    {
      buf[cnt] = 0;
    }
    return -2;
  }

  return 0;
}

//-----------------------------------------------------------------------------
//    関数名     ：   SplitData
//    概要       ：   読み込んだクイズを問題，選択肢，解答に分ける．
//    戻り値     ：   なし
//    引数       ：   char* str
//              説明  読み込んだ行のデータを格納している(ポインタ)
//    引数       ：   struct quiz *q
//              説明  クイズの情報を格納しているquiz構造体(ポインタ)
//
//    作成       ：   2014/02/18    Yousuke Nakanishi
//-----------------------------------------------------------------------------


void SplitData(char *str, struct quiz *q)
{
  int i, j, k;

  //「問題，選択，答え」となっているため”，”で区切る
  for (i = 0; str[i] != ','; i++) {
    q->mondai[i] = str[i]; //問題を代入
  }
  q->mondai[i] = '\0';
  
  for (k = 0; k < 4; k++) {
    i++;
    for (j = 0; str[i] != ',' && str[i] != '\0'; i++, j++) {
      q->sentaku[k][j] = str[i]; //選択肢を代入
    }
    q->sentaku[k][j] = '\0';
  }
  
  q->answer = str[i+1]; //答えを代入

}

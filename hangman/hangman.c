#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM 30			/* 答えなどを格納する配列の確保するサイズ */
#define WORD_SIZE 235881	/* 辞書ファイルの行数 */
#define TRUE 1
#define FALSE 0
#define XORKEY 0x34509		/* 暗号化の鍵 */
#define RETRY 7

typedef struct
{
  char word_ans[NUM+1];		/* 答えを格納する配列(最大30文字) */
  char word_disp[NUM+1];	/* 文字の表示用の配列(最大30文字) */
  char used_words[26];   	/* 使用した文字を格納する配列
				   (アルファベット小文字26文字分)*/
  char miss_words[NUM][NUM+1];	/* 不正解の単語一覧(30文字×30回分) */
  int right_count, wrong_count;	/* 正解数，不正解数 */
  int hit, mistake, length;	/* それぞれ，ヒット数,失敗した数,答えの文字数 */
} GAME_STATE;

/* 関数プロトタイプ宣言 */
void initialize(GAME_STATE *state);
void hangman(GAME_STATE *state);
void endscreen(GAME_STATE *state);

int main(void)
{
  GAME_STATE state;
  int select = FALSE;
  int i;

  /* ゲームの成績に関する変数の初期化 */
  state.right_count = state.wrong_count = 0;

  for (i = 0; i < NUM; i++) {
    state.miss_words[i][0] = '\0';
  }

  do {
    initialize(&state);

    printf("\n ans:%s\n", state.word_ans);
    
    /* メインループ */
    while (1) {
      hangman(&state);

      if (state.hit == state.length) {
	state.right_count++;
	printf("正解です %s\n", state.word_ans);
	printf("続けますか(y/n)?");
	select = getChar();
	break;
      }
      else if (state.mistake == 7) {
	strcpy(&(state.miss_words[state.wrong_count][0]), state.word_ans);
	state.wrong_count++;
	printf("残念 正解は %s でした\n", state.word_ans);
	printf("続けますか(y/n)?");
	select = getChar();
	break;
      }
    }

    printf("\n\n");

  } while(select == 'y');


  endscreen(&state);

  return 0;
}

/* 初期化 */
void initialize(GAME_STATE *state)
{
  int i, num;
  char tmp[NUM];
  FILE *fp;

  srand((unsigned)time(NULL));

  /* ファイルのオープン */
  fp = fopen("words", "r");
  if (fp == NULL) {
    printf("Cannot open words file.\n");
    exit(1);
  }

  state->hit = 0;
  state->mistake = 0;

  /* wordsを適当な行数分読み飛ばして正解の単語を格納 */
  num = rand() % WORD_SIZE;
  for (i = 0; i < num; i++) {
    fscanf(fp, "%s", tmp);
  }
  fscanf(fp, "%s", state->word_ans);

  /* 正解の単語の文字数を調べる */
  state->length = strlen(state->word_ans);

  /* -------の初期化 */
  for (i = 0; i < state->length; i++) {
    state->word_disp[i] = '-';
  }
  state->word_disp[i] = '\0';

  /* 入力した文字が既に使われていないか判定する配列の初期化 */
  for (i = 0; i <= 'z'-'a'; i++) {
    state->used_words[i] = FALSE;
  }

  fclose(fp);

}


void hangman(GAME_STATE *state)
{
  int i, hit_flag, skip;
  char c;
  
  hit_flag = FALSE;
  skip = FALSE;

  printf("単語:%s\n", state->word_disp);

  printf("使われた文字:");
  for (i = 0; i <= 'z'-'a'; i++) {
    if (state->used_words[i] == TRUE) {
      printf("%c ", 'a'+i);
    }
  }
  printf("\n");

  printf("残り回数:%d\n", RETRY-(state->mistake));

  printf("文字を入力して下さい:");
  c = getChar();

  if (islower(c)) {
    printf("%c\n", c);
  }
  else {
    printf("英小文字を入力して下さい．\n");
    skip = TRUE;
  }
  printf("\n\n");

  /* すでに入力した文字が使われていないかの確認 */
  if (state->used_words[c-'a'] == TRUE) {
    printf("すでに使われています.\n");
    skip = TRUE;
  }

  /* 使われた文字を格納する作業 */
  if (skip == FALSE) {
    state->used_words[c-'a'] = TRUE;
  }

  /* ヒットしているかの判定 */
  for (i = 0; i < state->length && skip == FALSE; i++ ) {
    if (state->word_ans[i] == c || state->word_ans[i] == c - ('a'-'A')) {
      state->word_disp[i] = state->word_ans[i];
      state->hit++;
      hit_flag = TRUE;
    }
  }

  /* 失敗した回数のカウント */
  if (hit_flag == FALSE && skip == FALSE) {
    state->mistake++;
  }

}


void endscreen(GAME_STATE *state)
{
  int t_total, t_right, t_wrong; /* 累積の成績計算用 */
  int i;
  FILE *fp;

  t_total = t_right = t_wrong = 0;

  printf("\n\n*** 不正解単語一覧 ***\n");
  for (i = 0; i < state->wrong_count; i++) {
    printf("・%s\n", &state->miss_words[i][0]);
  }
  printf("**********************\n");

  fp = fopen("record.dat", "r");
  if (fp != NULL) {
    fscanf(fp, "%d %d %d", &t_total, &t_right, &t_wrong); /* データの読み込み */
    fclose(fp);

    /* 暗号化されているデータを復号する */
    t_total ^= XORKEY;
    t_right ^= XORKEY;
    t_wrong ^= XORKEY;
  }

  /* 累積の成績の計算 */
  t_total += (state->right_count + state->wrong_count);
  t_right += state->right_count;
  t_wrong += state->wrong_count;

  printf("\n--------------------------------------\n");
  printf("|          | 今回の成績 | 累積の成績 |\n");
  printf("|------------------------------------|\n");
  printf("| ゲーム数 |  %4d回    |  %4d回    |\n", (state->right_count + state->wrong_count), t_total);
  printf("|  正解数  |  %4d回    |  %4d回    |\n", state->right_count, t_right);
  printf("| 不正解数 |  %4d回    |  %4d回    |\n", state->wrong_count, t_wrong);
  printf("|  正解率  |  %4d\%　　 |  %4d\% 　  |\n", (int)((double)state->right_count / (state->right_count + state->wrong_count)*100),  (int)(((double)t_right / t_total*100)));
  printf("--------------------------------------\n");

  fp = fopen("record.dat", "w");
  if (fp == NULL) {
    printf("Can't open file!\n");
    exit(1);
  }

  fprintf(fp, "%d %d %d", t_total^XORKEY, t_right^XORKEY, t_wrong^XORKEY); /* 暗号化してファイルに書き込む */

  printf("\nまたね\n");

  fclose(fp);

}

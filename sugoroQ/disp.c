//---------------------------------------------------------------------------
//   ファイル名    ：    disp.c
//   概要         ：    マップを表示する
//   詳細         ：    サーバーから受け取ったプレイヤー情報や,駅の情報,問題を表示する
//   履歴         ：    2014/2/18  Yoshitaka TSUMITA , Hikaru NAKASONE 新規作成
//---------------------------------------------------------------------------

#include "sugoroQ.h"

static struct termios init_tio;
int remaining_time = 10;
int flag = FALSE;


//------------------------------------------------------------------------
//   関数名　　　： init_keyboard
//   概要　　　　： キーボードの初期化
//   戻り値     ： なし
//   引数　　　　： なし
//   作成　　　　： 2014/2/18       Kouta ASAI
//------------------------------------------------------------------------
void init_keyboard()
{
  tcgetattr(0,&init_tio);
}

//------------------------------------------------------------------------
//   関数名　　　： close_keyboard
//   概要　　　　： キーボードの終了処理
//   戻り値     ： なし
//   引数　　　　： なし
//   作成　　　　： 2014/2/18       Kouta ASAI
//------------------------------------------------------------------------
void close_keyboard()
{
  tcsetattr(0,TCSANOW,&init_tio);
}

//------------------------------------------------------------------------
//   関数名　　　： kbhit
//   概要　　　　： キーが入力されたかどうかの判定
//   戻り値     ： 1:ON or 0:OFF
//   引数　　　　： なし
//   作成　　　　： 2014/2/18       Kouta ASAI
//------------------------------------------------------------------------
int kbhit()
{
    struct termios tio;
    struct timeval tv;
    fd_set rfds;
    // set up terminal
    memcpy(&tio,&init_tio,sizeof(struct termios));
    tio.c_lflag &= ~(ICANON);
    tcsetattr(0,TCSANOW,&tio);
    // do not wait
    FD_ZERO(&rfds);
    FD_SET(0,&rfds);
    tv.tv_usec = 0;
    tv.tv_sec  = 0;
    select(1,&rfds,NULL,NULL,&tv);
    // back to initial terminal mode
    tcsetattr(0,TCSANOW,&init_tio);
    return (FD_ISSET(0,&rfds)?1:0);
}

//------------------------------------------------------------------------
//   関数名　　　： readkey
//   概要　　　　： キー入力
//   戻り値     ： 入力した文字
//   引数　　　　： なし
//   作成　　　　： 2014/2/18       Kouta ASAI
//------------------------------------------------------------------------
int readkey()
{
    int ch;
    struct termios tio;
    // set up terminal
    memcpy(&tio,&init_tio,sizeof(struct termios));
    tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&tio);
    // input key
    read(0,&ch,1);
    // back to initial terminal mode
    tcsetattr(0,TCSANOW,&init_tio);
    return ch;
}

//------------------------------------------------------------------------
//   関数名　　　： Status
//   概要　　　　： プレイヤーのステータスを表示する
//   戻り値     ： なし
//   引数　　　　： struct board board
//          説明  プレイヤーのステータスを表示するのに必要なboard構造体
//   作成　　　　： 2014/2/18       Yoshitaka TSUMITA
//------------------------------------------------------------------------
void Status(struct board board)
{
  struct station *tmp;

  printf("\x1b[%d;%dH", 8, 51);
  printf("turn:%d",board.q.turn);

  printf("\x1b[%d;%dH", 10, 29);
  printf("1|%8s|",board.p[0].name);
  printf("\x1b[%d;%dH", 11, 30);
  printf("|%8d|",board.p[0].money);
  printf("\x1b[%d;%dH", 12, 30);
  tmp=r_access_station(board.s,board.p[0].place_id);
  printf("|%8s|",tmp->place_name);

  printf("\x1b[%d;%dH", 10, 69);
  printf("2|%8s|",board.p[1].name);
  printf("\x1b[%d;%dH", 11, 70);
  printf("|%8d|",board.p[1].money);
  printf("\x1b[%d;%dH", 12, 70);
  tmp=r_access_station(board.s,board.p[1].place_id);
  printf("|%8s|",tmp->place_name);


  printf("\x1b[%d;%dH", 14, 29);
  printf("3|%8s|",board.p[2].name);
  printf("\x1b[%d;%dH", 15, 30);
  printf("|%8d|",board.p[2].money);
  printf("\x1b[%d;%dH", 16, 30);
  tmp=r_access_station(board.s,board.p[2].place_id);
  printf("|%8s|",tmp->place_name);


  printf("\x1b[%d;%dH", 14, 69);
  printf("4|%8s|",board.p[3].name);
  printf("\x1b[%d;%dH", 15, 70);
  printf("|%8d|",board.p[3].money);
  printf("\x1b[%d;%dH", 16, 70);
  tmp=r_access_station(board.s,board.p[3].place_id);
  printf("|%8s|",tmp->place_name);


}

//------------------------------------------------------------------------
//   関数名　　　： quiz
//   概要　　　　： クイズを表示する関数を呼び出す
//   戻り値     ： なし
//   引数　　　　： struct board *board
//          説明  プレイヤーのステータスを表示するのに必要なboard構造体
//   引数　　　　： int id
//          説明  プレイヤID
//   作成　　　　： 2014/2/18       Yoshitaka TSUMITA , Hikaru NAKASONE
//------------------------------------------------------------------------
void quiz(struct board *board, int id)
{

  disp_quiz(board->q);

  disp_selection(board->q);

  input(&(board->p[id]));

  judge(*board, id);

}

//------------------------------------------------------------------------
//   関数名　　　： disp_quiz
//   概要　　　　： 問題文を表示する
//   戻り値     ： なし
//   引数　　　　： struct quiz q 
//          説明  問題文の格納先であるquiz構造体
//   作成　　　　： 2014/2/18       Yoshitaka TSUMITA , Hikaru NAKASONE　
//------------------------------------------------------------------------
void disp_quiz(struct quiz q)
{
  int i,j;
  int x,y;

  x = 20;
  y = 19;

  j = 0; //文字数カウント

  printf("\x1b[%d;%dH", y, x);
  printf("問題:");
  //printf("");
  for (i = 0; q.mondai[i] != '\0'; i++) {
    printf("%c", q.mondai[i]);
    usleep(20000);
    fflush(NULL);
    j++;
    if(j == 70){ //改行
      j = 0;
      y++;
      printf("\x1b[%d;%dH", y, x);
    }
  }
  printf("\n\n");
  usleep(500000);

}

//------------------------------------------------------------------------
//   関数名　　　： disp_selection
//   概要　　　　： 選択肢を表示する
//   戻り値     ： なし
//   引数　　　　： struct quiz q 
//          説明  選択肢の格納先であるquiz構造体
//   作成　　　　： 2014/2/18       Yoshitaka TSUMITA , Hikaru NAKASONE　
//------------------------------------------------------------------------
void disp_selection(struct quiz q)
{
  int i;
  int x = 20;
  int y = 23;

  printf("\x1b[%d;%dH", y, x);
  printf("選択肢:");
  for (i = 0; i < SELECTION_NUM; i++) {
    y++;
    printf("\x1b[%d;%dH", y, x);
    printf(" %d.%s ", i+1, q.sentaku[i]);
  }
  printf("\n");

}

//------------------------------------------------------------------------
//   関数名　　　： input
//   概要　　　　： 回答を入力する
//   戻り値     ： なし
//   引数　　　　： struct player *p 
//   作成　　　　： 2014/2/18       Yoshitaka TSUMITA , Hikaru NAKASONE　
//------------------------------------------------------------------------
void input(struct player *p)
{
  char ch='0';
  time_t start, end;
  pthread_t tid1, tid2;

  flag = FALSE;

  init_keyboard();

  pthread_create(&tid2, NULL, count_time, NULL);
  pthread_create(&tid1, NULL, disp_time_bar, NULL);

  start = time(NULL);

  while ((ch > '4' || ch < '1') && remaining_time > 0) {

    if ( kbhit() ) {
      ch = readkey();
    }

  }
  rewind(stdin);
  end = time(NULL);

  close_keyboard();

  flag = TRUE;

  pthread_join(tid2, NULL);
  pthread_join(tid1, NULL);

  p->p_answer = ch - '0';
  p->answer_time = (int)(end-start);

  remaining_time = 10;

}

//------------------------------------------------------------------------
//   関数名　　　： disp_time_bar
//   概要　　　　： タイムバーを表示する
//   戻り値     ： なし
//   引数　　　　： なし 
//   作成　　　　： 2014/2/18       Yoshitaka TSUMITA , Hikaru NAKASONE　
//------------------------------------------------------------------------
void disp_time_bar(void)
{
  int i, j;
  int count = 0;

  while (remaining_time > 0 && flag == FALSE) {
    //printf("\x1b[2K");//一行消す
    printf("\x1b[%d;%dH", 29, 12);
    printf("                                                                           ");
    //    printf("\x1b[2K");//一行消す
    printf("\x1b[%d;%dH", 29, 20);
    printf("残り時間:%d秒", remaining_time);
    printf("\x1b[%d;%dH", 29, 40);
    for (j = remaining_time*4 - count; j >= 0; j--) {
      printf("|");
    }
    usleep(250000);
    count++;
    if (count == 4) {
      count = 0;
    }
    fflush(NULL);
  }
}

//------------------------------------------------------------------------
//   関数名　　　： count_time
//   概要　　　　： 時間をカウントする
//   戻り値     ： なし
//   引数　　　　： なし 
//   作成　　　　： 2014/2/18       Yoshitaka TSUMITA , Hikaru NAKASONE　
//------------------------------------------------------------------------
void count_time(void)
{
  int i;

  for (i = 10; i >= 0 && flag == FALSE; i--) {
    remaining_time = i;
    sleep(1);
  }

}

//------------------------------------------------------------------------
//   関数名　　　： judge
//   概要　　　　： 正解か不正解かを判定する
//   戻り値     ： なし
//   引数　　　　： struct board *board
//          説明  プレイヤーのステータスを表示するのに必要なboard構造体
//   引数　　　　： int id
//          説明  プレイヤID
//   作成　　　　： 2014/2/18       Yoshitaka TSUMITA , Hikaru NAKASONE　
//------------------------------------------------------------------------
void judge(struct board board, int id)
{

  if (board.p[id].p_answer == (board.q.answer - '0')) {
    //printf("　　　　　\x1b[%d;%dH", 25+5, 0);
    printf("　　　　　\x1b[%d;%dH", 32, 30);
    printf("　　　　　正解！！ 回答時間%d秒\n", board.p[id].answer_time);
  }
  else {
    //printf("　　　　　\x1b[%d;%dH", 25+5, 0);
    printf("　　　　　\x1b[%d;%dH", 32, 30);
    printf("　　　　　残念、不正解...！！\n");
  }
  printf("\x1b[%d;%dH",55,0);
  sleep(1);
}

//------------------------------------------------------------------------------------------
//   関数名　　　： DispMap
//   概要　　　　： マップを表示する
//   戻り値     ： なし
//   引数　　　　： char station[][BUF_SIZE] , int money[], int have[], int stay[][PLAYER_NUM]
//          説明  駅の名前 , 駅の値段 , 今誰がそのマスにいるか , 今誰がその駅を保持しているか
//　　作成　　　　： 2014/2/18       Yoshitaka TSUMITA , Hikaru NAKASONE　
//------------------------------------------------------------------------------------------
void DispMap(char station[][BUF_SIZE], int money[], int have[], int stay[][PLAYER_NUM])
{
  int lockup[30] = {18,19,20,21,22,23,24,25,26,27,17,28,16,29,15,0,14,1,13,2,12,11,10,9,8,7,6,5,4,3}; //駅のルックアップテーブル
  int i,j;
  char staych[MAP_SIZE][9];
  char havech[MAP_SIZE][9];

  for(i=0;i<MAP_SIZE;i++){
    staych[i][8]='\0';
    havech[i][8]='\0';
    for (j = 0; j < 8; j++) {
      havech[i][j] = ' ';
    }
    if (have[i] != -1) {
      havech[i][7] = have[i] + '1';
    }

    for(j=0;j<PLAYER_NUM;j++){
      if(stay[i][j]==TRUE){
	staych[i][j*2]=' ';
	staych[i][j*2+1]=j+'1';
      }
      else {
	staych[i][j*2] = ' ';
	staych[i][j*2+1] = ' ';
      }
    }
  }

  j = 0;

  //printf("\n\n");
  for(i = 0; i < 7; i++){
    if(i == 0){
      printf(" |%s| |%s| |%s| |%s| |%s|  |%s| |%s| |%s| |%s| |%s|\n",station[lockup[j]],station[lockup[j+1]],station[lockup[j+2]],station[lockup[j+3]],station[lockup[j+4]],station[lockup[j+5]],station[lockup[j+6]],station[lockup[j+7]],station[lockup[j+8]],station[lockup[j+9]]);
      printf(" |%8d| |%8d| |%8d| |%8d| |%8d|  |%8d| |%8d| |%8d| |%8d| |%8d|\n",money[lockup[j]],money[lockup[j+1]],money[lockup[j+2]],money[lockup[j+3]],money[lockup[j+4]],money[lockup[j+5]],money[lockup[j+6]],money[lockup[j+7]],money[lockup[j+8]],money[lockup[j+9]]);
      printf(" |%8s| |%8s| |%8s| |%8s| |%8s|  |%8s| |%8s| |%8s| |%8s| |%8s|\n",staych[lockup[j]],staych[lockup[j+1]],staych[lockup[j+2]],staych[lockup[j+3]],staych[lockup[j+4]],staych[lockup[j+5]],staych[lockup[j+6]],staych[lockup[j+7]],staych[lockup[j+8]],staych[lockup[j+9]]);
      printf(" |%8s| |%8s| |%8s| |%8s| |%8s|  |%8s| |%8s| |%8s| |%8s| |%8s|\n\n", havech[lockup[j]],havech[lockup[j+1]],havech[lockup[j+2]],havech[lockup[j+3]],havech[lockup[j+4]],havech[lockup[j+5]],havech[lockup[j+6]],havech[lockup[j+7]],havech[lockup[j+8]],havech[lockup[j+9]]);
      j = 10;
    }else if(i == 6){
      printf(" |%s| |%s| |%s| |%s| |%s|  |%s| |%s| |%s| |%s| |%s|\n",station[lockup[j]],station[lockup[j+1]],station[lockup[j+2]],station[lockup[j+3]],station[lockup[j+4]],station[lockup[j+5]],station[lockup[j+6]],station[lockup[j+7]],station[lockup[j+8]],station[lockup[j+9]]);
      printf(" |%8d| |%8d| |%8d| |%8d| |%8d|  |%8d| |%8d| |%8d| |%8d| |%8d|\n",money[lockup[j]],money[lockup[j+1]],money[lockup[j+2]],money[lockup[j+3]],money[lockup[j+4]],money[lockup[j+5]],money[lockup[j+6]],money[lockup[j+7]],money[lockup[j+8]],money[lockup[j+9]]);
      printf(" |%8s| |%8s| |%8s| |%8s| |%8s|  |%8s| |%8s| |%8s| |%8s| |%8s|\n",staych[lockup[j]],staych[lockup[j+1]],staych[lockup[j+2]],staych[lockup[j+3]],staych[lockup[j+4]],staych[lockup[j+5]],staych[lockup[j+6]],staych[lockup[j+7]],staych[lockup[j+8]],staych[lockup[j+9]]);
      printf(" |%8s| |%8s| |%8s| |%8s| |%8s|  |%8s| |%8s| |%8s| |%8s| |%8s|\n",havech[lockup[j]],havech[lockup[j+1]],havech[lockup[j+2]],havech[lockup[j+3]],havech[lockup[j+4]],havech[lockup[j+5]],havech[lockup[j+6]],havech[lockup[j+7]],havech[lockup[j+8]],havech[lockup[j+9]]);   
    }else{
      printf(" |%s|                                                                                          |%s|\n",station[lockup[j]],station[lockup[j+1]]);
      printf(" |%8d|                                                                                          |%8d|\n",money[lockup[j]],money[lockup[j+1]]);
      printf(" |%8s|                                                                                          |%8s|\n",staych[lockup[j]],staych[lockup[j+1]]);
      printf(" |%8s|                                                                                          |%8s|\n\n",havech[lockup[j]],havech[lockup[j+1]]);
      j += 2;
    }
  }
}
/*
int main()
{
  struct board map;
  struct station *tmp;
  char station[MAP_SIZE][BUF_SIZE];
  int money[MAP_SIZE];
  int stay[MAP_SIZE][PLAYER_NUM] = {{FALSE}};
  int have[MAP_SIZE]={-1};
  int i,j;

  init_station(&map);

  tmp = map.s;

  map.p[0].name[0] = 'a';
  map.p[0].name[1] = '\0';
  map.p[1].name[0] = 'c';
  map.p[1].name[1] = '\0';  
  map.p[2].name[0] = 'v';
  map.p[2].name[1] = '\0';
  map.p[3].name[0] = 'b';
  map.p[3].name[1] = '\0';


  map.p[0].rank = 1;
  map.p[1].rank = 2;  
  map.p[2].rank = 3;
  map.p[3].rank = 4;

  map.p[0].money = 1000;
  map.p[1].money = 2000;
  map.p[2].money = 3000;
  map.p[3].money = 4000;

  for(j=0; j<PLAYER_NUM; j++){
    map.p[j].place_id = j;
  } /*
    printf("name[%d]: ",j);
    scanf("%s",&(map.p[j].name[256]));
    map.p[j].money=j*100;
    }

  for(i = 0; i < MAP_SIZE; i++){

    tmp->who_have = i%4;

    strcpy(station[i],tmp->place_name);
    money[i] = tmp->value;
    have[i] = tmp->who_have;

    for(j=0; j<PLAYER_NUM; j++){
      stay[map.p[j].place_id][i] = TRUE;
    }

    tmp = tmp->next;
  }

  
  while(1){
    DispMap(&map,station,money,have,stay);
    Status(map);
    quiz(&map);
    printf("%c[2J",ESC);
  }
  
  return 0; 
}
*/

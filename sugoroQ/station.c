//-----------------------------------------------------------------------
//    ファイル名  ：  station_client.c
//    概要        ：  stationに関するモジュール
//    詳細        ：  この関数を呼び出すことでstationの初期化
//                    位置の取得が行える．
//
//    履歴        ：  2014/02/17    Shingo SEKIYA          新規作成
//-----------------------------------------------------------------------


#include "sugoroQ.h"

/*
//test用のヘッダファイル
#include"station.h"
#include"test_print.h"
*/

//-----------------------------------------------------------------------
//  関数名  ：  init_station_server
//  概要    ：  サーバー側のstation初期化関数
//              双方向循環リストでの作成
//  戻り値  ：  なし
//  引数    ：  struct board 
//        stationの先頭番地を含むゲームデータ
//
//  作成    ：  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
void init_station_server(struct board *board){
  int i;
  char string[BUF_SIZE];
  struct station *p;
  FILE *fp;


  fp=fopen("station.txt","r");

  p=(struct station*)malloc(sizeof(struct station));
  //領域の確保ができていなかったら強制終了
  if(p==NULL)exit(1);

  board->s=p;
  p->next=p;
  p->prev=p;

  p->place_id=0;
  p->who_have=-1;
  fgets(string,BUF_SIZE,fp);
  convert_CSV(p,string);

  //駅リストの初期位置以外の設定を行うループ
  for(i=1;i<MAP_SIZE;i++){
    p=insert_station(p);
    p->place_id=i;
    p->who_have=-1;
    fgets(string,BUF_SIZE,fp);
    convert_CSV(p,string);
  }
}


//-----------------------------------------------------------------------
//  関数名  ：  init_station_client
//  概要    ：  クライアント側のstation初期化関数
//              双方向循環リストでの作成
//  戻り値  ：  なし
//  引数    ：  struct board*,char st_name[][],int value[]
//        stationの先頭番地を含むゲームデータ
//        全駅の名前
//        全駅の値段
//  引数    ：  char st_name
//        駅名前が格納されている配列
//
//  作成    ：  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
void init_station_client(struct board *board,char st_name[MAP_SIZE][BUF_SIZE], int value[MAP_SIZE], int have[MAP_SIZE]){
  int i;
  struct station *p;

  p=(struct station*)malloc(sizeof(struct station));
  //領域の確保ができていなかったら強制終了
  if(p==NULL)exit(1);

  board->s=p;
  p->next=p;
  p->prev=p;

  p->place_id=0;
  p->who_have=have[0];
  strcpy(p->place_name,st_name[0]);
  p->value = value[0];

  //駅リストの初期位置以外の設定を行うループ
  for(i=1;i<MAP_SIZE;i++){
    p=insert_station(p);
    p->place_id=i;
    p->who_have=have[i];
    strcpy(p->place_name,st_name[i]);
    p->value = value[i];
  }
}


//-----------------------------------------------------------------------
//  関数名  ：  free_station
//  概要    ：  stationの開放を行う関数
//              
//  戻り値  ：  なし
//  引数    ：  struct board *board 
//        ゲームデータ
//
//  作成    ：  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
void free_station(struct board *board){
  int i;
  struct station *p,*tmp;

  p=board->s;
  board->s=NULL;
  //0~29番目の駅の開放
  for(i=0;i<MAP_SIZE-1;i++){
    tmp=p->next;
    free(p);
    p=tmp;
  }
  free(p);
}


//-----------------------------------------------------------------------
//  関数名  ：  convert_CSV
//  概要    ：  stationの初期化のためにcsv形式の文字列から駅名と
//              駅の値段を求める．
//  戻り値  ：  なし
//  引数    ：   struct station *dat,char string[256]
//        1つの駅のデータへのポインタ
//        CSVファイルから読み込んだ一行分の文字列
//
//  作成    ：  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
void convert_CSV(struct station *p,char string[BUF_SIZE]){
  int i;

  //CSVファイルが"駅名(文字列),値段(数字列)"の形になっている
  //','までの駅名を代入
  for(i=0;string[i]!=',';i++){
    p->place_name[i]=string[i];
  }

  p->place_name[i]='\0';
  p->value=0;
  i++;

  //'\n'までの数字列を数値に変換して代入
  for(;string[i]!='\n';i++){
    p->value*=10;
    p->value+=string[i]-'0';
  }
}


//-----------------------------------------------------------------------
//  関数名  ：  insert_station
//  概要    ：  stationの追加を行う関数
//              
//  戻り値  ：  struct station*
//        新しく作成した駅のポインタ
//  引数    ：  struct station *p 
//        stationの追加したい一つ手前のポインタ
//
//  作成    ：  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
struct station *insert_station(struct station *p){
  struct station *new;

  new=(struct station*)malloc(sizeof(struct station));
  //領域の確保ができていなかったら強制終了
  if(new==NULL)exit(1);

  new->next=p->next;
  new->prev=p;
  p->next=new;

  return new;
}


//-----------------------------------------------------------------------
//  関数名  ：  s_access_station
//  概要    ：  station間の移動関数
//             引数で渡されたポインタの位置からn個進む 
//  戻り値  ：  struct station*
//        移動後の駅ポインタ
//  引数    ：  struct station *p,int n 
//        stationのポインタであり直接中身をいじらないため
//           board内の駅の先頭番地sも引数として扱える
//        進ませる駅の数n
//
//  作成    ：  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
struct station *s_access_station(struct station *p,int n){
  int i;
  struct station *foo;

  foo=p;
  //シーケンシャルアクセスでの順方向アクセスをn>0，逆方向アクセスをn<0としている
  if(n>0){
    //nの絶対値回進む
    for(i=0;i<n;i++)foo=foo->next;
  }else{
    //nの絶対値回戻る
    for(i=0;i>n;i--)foo=foo->prev;
  }

  return foo;  
}


//-----------------------------------------------------------------------
//  関数名  ：  r_access_station
//  概要    ：  station間の移動関数
//             idの位置に移動する 
//  戻り値  ：  struct station*
//        移動後の駅ポインタ
//  引数    ：  struct station *p,int id 
//        stationのポインタであり直接中身をいじらないため
//           board内の駅の先頭番地sも引数として扱える
//        進ませる駅のid
//
//  作成    ：  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
struct station *r_access_station(struct station *p,int id){
  struct station *foo;

  foo=p;
  //指定したidが領域外であれば処理しない
  if(0<=id&&id<MAP_SIZE){
    //指定したidが見つかるまで進む
    while(foo->place_id!=id){
      foo=foo->next;
    }
  }
  return foo;
}

/*
//test用のmain関数
int main(void){
  struct board board;

  init_station_server(&board);
  print_station(board);
  free_station(&board);
  return 0;
}  
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void opening(void);
int get_number(void);
int distinction(int);
int escape1(void);
int escape2(void);


int main(void)
{
  int score_1, score_2;

  srand((unsigned)time(NULL));

  opening();

  score_1 = escape1();

  if(score_1!=0){
    sleep(1);
    score_2 = escape2();
  }else{
    printf("\nGame Over!! ゲームを終了します...\n\n");
    sleep(1);
    return 0;
  }

  if(score_2!=0){
    printf("\x1b[7m"); //反転
    printf("all stage complete!!!\n\n");
    printf("\x1b[0m"); //属性クリア
    sleep(1);
  }else{
    printf("\nGame Over!! ゲームを終了します...\n\n");
    sleep(1);
  }

  if(score_1!=0){
    printf("+----------------------------------+\n");
    printf("|  「Escape 1」のスコア … %5d   |\n", score_1);
  }
  if(score_2!=0){
    printf("|  「Escape 2」のスコア … %5d   |\n", score_2);
  }
  printf("+----------------------------------+\n\n");

  return 0;
}

void opening(void)
{
  printf("\n\n***********************************\n");
  printf("*                                 *\n");
  printf("*          Strange House          *\n");
  printf("*                                 *\n");
  printf("* 警告:ただの数当てゲームです(笑) *\n");
  printf("*                                 *\n");
  printf("***********************************\n\n");

  printf("〜|注意|〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜\n"); 
  printf("｜ 数字を入力する場面では，                      ・\n");
  printf("・ 数字以外を入力しないでください．              ｜\n");
  printf("｜ 文字などを入力すると，無限ループします．      ・\n");
  printf("・ もし，無限ループしてしまった場合は，          ｜\n");
  printf("｜ [Ctrl + c]でプログラムを強制終了してください．・\n");
  printf("〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜\n\n"); 

  printf("Press Enter to Start Game!!\n");
  getc(stdin);
}

int get_number(void)
{
  int number;

  do{
    printf("答えは?:");
    scanf("%d", &number);
    
    if(number<0 || number>100){
      printf("input error!!\n");
    } 
  } while(number<0 || number>100);

  return number;
}

int distinction(int ans)
{
  int flag , input_ans;
  
  input_ans = get_number();
    
  if(input_ans==ans){
    flag = TRUE;
  }else if(input_ans<ans){
    printf("\x1b[4m"); //アンダーライン
    printf("番号はもっと大きいような気がする…\n");
    printf("\x1b[0m"); //属性クリア
    flag = FALSE;
    printf("\n");
  }else if(input_ans>ans){
    printf("\x1b[4m"); //アンダーライン
    printf("番号はもっと小さいような気がする…\n");
    printf("\x1b[0m"); //属性クリア
    flag = FALSE;
    printf("\n");
  }  

  return flag;
}

int escape1(void)
{
  int ans, flag=FALSE, count=10, score=0;
  
  ans = rand() % 100;
  
  printf("\n##################\n");
  printf("#                #\n");
  printf("#    Escape 1    #\n");
  printf("#                #\n");
  printf("##################\n\n");

  usleep(500000);
  printf("〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜\n"); 
  printf("｜意識が朦朧としている...                                   ・\n");
  printf("・ここは一体何処なのだろうか...                             ｜\n");
  printf("｜辺りを見回しても窓もない...                               ・\n");
  printf("・唯一,鍵のかかったドアがあるだけ。                         ｜\n");
  printf("｜嫌な予感がする...                                         ・\n");
  printf("・どうやら密室に閉じ込められてしまったようだ。              ｜\n");
  printf("｜んっ!!ドアと床の隙間に紙が挟んである!                     ・ \n");
  printf("・その紙によると、このドアの鍵の番号は,0〜99のどれからしい。｜\n");
  printf("｜しかも、10回間違えると一生開かなくなってしまうようだ...   ・\n");
  printf("・なんとしてもこの部屋から脱出せねば!!                      ｜\n");
  printf("〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜\n\n"); 
  usleep(500000);
  
  printf("Enterキーを押すと,ゲームを開始します.\n");
  getc(stdin);

  while(flag==FALSE && count>0){
    printf("残り%d回\n", count);
    flag = distinction(ans);
    if(flag == FALSE){
      count--;
    }
  }

  score = count * (rand() % 300 + 150); //スコアの計算

  if(flag == TRUE){
    printf("\n…ガチャ!! ドアが開いた!!  脱出することに成功した!!!\n\n");
    printf("******************\n");
    printf("*  score：%5d  *\n", score);
    printf("******************\n\n");
    sleep(1);
    printf("次のステージに進みます...\n");
  }else{
    printf("10回間違えてしまった…\n");
    printf("もう一生この部屋から出ることは出来ないのだろうか…\n");
    printf("目の前が真っ暗になった... [ちなみに，答えは%dでした]\n", ans); 
 }

  return score;
}

int escape2(void)
{
  int ans, flag=FALSE, count=5, score=0;

  ans = rand() % 100;

  printf("\n##################\n");
  printf("#                #\n");
  printf("#    Escape 2    #\n");
  printf("#                #\n");
  printf("##################\n\n");

  usleep(500000);
  printf("〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜\n"); 
  printf("｜なんとかあの部屋から脱出することに成功した...          ・\n");
  printf("・「とりあえず、この奇妙な家から出よう…」               ｜\n");
  printf("｜そう思って、とりあえず玄関を探してみた。               ・\n");
  printf("・そして、なんとか玄関にたどり着いたのだが...            ｜\n");
  printf("｜なんと玄関には時限爆弾がセットされていた!!!            ・\n");
  printf("・どうやらこの時限爆弾を解除するにはパスワードが必要で、 ｜\n");
  printf("｜そのパスワードは0〜99のうちのどれかのようだ...         ・ \n");
  printf("・ただし、5回間違えると爆発する設定になっている。        ｜\n");
  printf("｜時限爆弾を解除できると、玄関の鍵も勝手に開くみたい...  ・\n");
  printf("・なんとしてもこの奇妙な家から脱出せねば!!               ｜\n");
  printf("〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜・〜\n\n"); 
  usleep(500000);
  
  printf("Enterキーを押すと,ゲームを開始します.\n");
  getc(stdin);
  getc(stdin);

  while(flag==FALSE && count>0){

    printf("残り%d回\n", count);

    flag = distinction(ans);

    if(flag == FALSE){
      count--;
    }
  }
  
  score = count * (rand() % 1000 + 850); //スコアの計算

  if(flag == TRUE){
    printf("\nおっ!! どうやら 時限爆弾の解除に成功したようだ!!!\n\n");
    printf("******************\n");
    printf("*  score：%5d  *\n", score);
    printf("******************\n\n");
  }else{
    printf("「・・・・・やばっ」\n\n");
    sleep(1);
    printf("[答えは%dでした]\n", ans);
  }
  return score;
}

#include <stdio.h>

int getdata(void)
{
  int a;

  printf("数値を入力してください：");
  scanf("%d",&a);

  return a;
}

void omikuji(int number)
{
  if(number == 1){
    printf("大吉です！すごいね！\n");
  }
  else if(number == 2){
    printf("吉です．やったー．\n");
  }
  else if(number == 3){
    printf("末吉です．まぁ，普通だね\n");
  }
  else{
    printf("1,2,3以外の数値が入力されました.\n");
    printf("1,2,3のどれかを入力してね．\n");
  }
}

int main(void)
{
  int x;

  x = getdata();

  omikuji(x);

  return 0;
}

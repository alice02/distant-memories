#include <stdio.h>

int pay_money(int total)
{
  int x;

  if(total>=10000){
    x = total - 3000;
  }else{
    x = total - 200;
  }

  return x;
}

int main(void)
{
  int a,b;

  printf("お買い物合計金額：");
  scanf("%d",&a);

  b = pay_money(a);

  printf("支払い代金は%d円デス\n",b);

  return 0;
}

#include "stack.h"

void  my_init_tower(struct stack  *ss)
{
  int  i;

  // 大きい円盤から順にスタックに積む．
  for (i = ss->i_size-1; i >= 0;  i--)  //● 初期化，反復条件
  {
    my_push(ss, i);  //● 引数
  }
}

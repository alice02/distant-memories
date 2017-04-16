#include "stack.h"

// このスタックは，配列の添字の大きい領域から小さい方向に向かって
// データを積んでいく．
// スタックポインタは，最初，スタックの領域外を指している．
int  my_pop(struct stack  *ss,
	    int  *ip_num)
{
  int  i_ret;

  if (ss->i_sp == ss->i_size)  //● 分岐条件
  {
    // スタックは空．
    i_ret = 1;  //● 右辺
  }
  else
  {
    *ip_num = ss->ia_stack[ss->i_sp];  //● 右辺
    (ss->i_sp)++;  //● 値の更新
    i_ret = 0;  //● 右辺
  }

  return i_ret;  //● 戻り値
}

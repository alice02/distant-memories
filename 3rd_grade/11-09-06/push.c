#include "stack.h"

// このスタックは，配列の添字の大きい領域から小さい方向に向かって
// データを積んでいく．
// スタックポインタは，最初，スタックの領域外を指している．
int  my_push(struct stack  *ss,
	     int  i_num)
{
  int  i_ret;

  if (ss->i_sp == 0)  //● 分岐条件
  {
    // スタックはすでに一杯．
    i_ret = 1;  //● 右辺
  }
  else
  {
    (ss->i_sp)--;  //● 値の更新
    ss->ia_stack[ss->i_sp] = i_num;  //● 左辺の添字
    i_ret = 0;  //● 右辺
  }

  return i_ret;  //● 戻り値
}

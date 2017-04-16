int  my_factorial(int  i_num)
{
  int  i_ans = 1;
  int  i;

  /*¡ü¡ü¡ü ½èÍıÆâÍÆ¤ò½ñ¤¯¡¥¡ü¡ü¡ü*/
  for (i = 2; i <= i_num; i++) {
    i_ans *= i;
  }

  return i_ans;
}

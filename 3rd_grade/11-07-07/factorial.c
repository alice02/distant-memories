int  my_factorial(int  i_num)
{
  int  i_ans = 1;
  int  i;

  /*������ �������Ƥ�񤯡�������*/
  for (i = 2; i <= i_num; i++) {
    i_ans *= i;
  }

  return i_ans;
}

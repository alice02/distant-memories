int my_string2int(char  ca_string[])
{
  int  i;
  int  i_num;
  int  i_ret;

  i_ret = 0;

  for (i=0; ca_string[i]!='\0'; i++) {
    i_num = ca_string[i] - '0';
    i_ret = i_ret * 10 + i_num;
  }

  return i_ret;
}

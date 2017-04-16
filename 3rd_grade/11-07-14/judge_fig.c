struct data
{
  char  *cp_dat;
  int   i_length;
};

struct judge
{
  int  i_hit;
  int  i_blow;
};

void my_judge_fig(struct data  ans,
		  char  cp_input[],
                  struct judge  *hb)
{
  int i, j;

  /*¡ü¡ü¡ü ½èÍýÆâÍÆ ¡ü¡ü¡ü*/
  hb->i_hit = hb->i_blow = 0;

  for (i = 0; i < ans.i_length; i++) {
    if (ans.cp_dat[i] == cp_input[i]) {
      hb->i_hit ++;
    }
    else {
      for (j = 0; j < ans.i_length; j++) {
	if (ans.cp_dat[i] == cp_input[j]) {
	  hb->i_blow ++;
	}
      }
    }
  }
}

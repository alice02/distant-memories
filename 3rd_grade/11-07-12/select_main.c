/*¡ü¡ü¡ü É¬Í×¤Ê¥Ø¥Ã¥À¥Õ¥¡¥¤¥ë¤ò´Þ¤á¤ë ¡ü¡ü¡ü*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct data
{
  char  *cp_dat;
  int   i_num;
};

/*¡ü¡ü¡ü ´Ø¿ô¥×¥í¥È¥¿¥¤¥×Àë¸À ¡ü¡ü¡ü*/
void my_select(struct data  ref,
	       struct data  *set);


int main(int argc, char *argv[])
{
  struct data  ref;
  struct data  set;
  int  i;

  srand((unsigned)time(NULL));

  if (argc-1 != 1) {
    printf("%s number\n", argv[0]);
    exit(1);
  }

  ref.i_num = atoi(argv[1]);

  set.i_num = ref.i_num;

  ref.cp_dat = (char *)malloc(sizeof(char)*ref.i_num+1);

  set.cp_dat = (char *)malloc(sizeof(char)*set.i_num+1);

  for (i = 0; i < ref.i_num; i++) {
    ref.cp_dat[i] = 'a'+i;
  }
  ref.cp_dat[i] = '\0';

  printf("%s\n", ref.cp_dat);

  my_select(ref, &set);

  printf("%s\n", set.cp_dat);

  return 0;
}

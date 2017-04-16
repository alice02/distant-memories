#include <stdlib.h>

struct data
{
  char  *cp_dat;  /* Ê¸»úÎó¤ò³ÊÇ¼¤¹¤ëÎÎ°è¤ÎÀèÆ¬ÈÖÃÏ¤òµ­²±¤¹¤ë¡¥*/
  int   i_length;  /* Ê¸»úÎó¤Î¥µ¥¤¥º¤ò³ÊÇ¼¤¹¤ë¡¥*/
};


void my_init_fig(struct data  *ans)
{
  int i_rand;
  int i_max;
  char ca_fig[10];
  int i;

  for (i = 0;  i <= 9;  i ++)
  {
    ca_fig[i] = '0' + i;  /*¡ü¡ü¡ü ±¦ÊÕ ¡ü¡ü¡ü*/
  }

  i_max = 10;
  for (i = 0;  i < ans->i_length;  i ++)  /*¡ü¡ü¡ü È¿Éü¾ò·ï ¡ü¡ü¡ü*/
  {
    i_rand = rand() % i_max;  /*¡ü¡ü¡ü ±¦ÊÕ ¡ü¡ü¡ü*/
    ans->cp_dat[i] = ca_fig[i_rand];  /*¡ü¡ü¡ü ±¦ÊÕ ¡ü¡ü¡ü*/
    ca_fig[i_rand] = ca_fig[i_max-1];  /*¡ü¡ü¡ü º¸ÊÕ¡¦±¦ÊÕ¤È¤âindex ¡ü¡ü¡ü*/
    i_max --;  /*¡ü¡ü¡ü ¹¹¿·½èÍı ¡ü¡ü¡ü*/
  }
  ans->cp_dat[ans->i_length] = '\0';  /*¡ü¡ü¡ü ±¦ÊÕ ¡ü¡ü¡ü*/
}

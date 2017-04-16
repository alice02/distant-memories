#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 3

struct parameter {
  int no;
  int hp;
  int mp;
  double attack;
  double defense;
};

void initialize(struct parameter player[]);
void disp_player(struct parameter player[]);
void save(struct parameter player[]);

int main(void)
{
  struct parameter player[PLAYER];

  char sv;

  srand((unsigned)time(NULL));

  initialize(player);

  disp_player(player);

  printf("save?(y/n)\n");
  scanf("%c", &sv);

  if (sv == 'y') {
    save(player);
  }
    
  return 0;
}

void initialize(struct parameter player[])
{
  int i;

  for (i=0; i<PLAYER; i++) {
    player[i].no = i;
    player[i].hp = rand()%99+1;
    player[i].mp = rand()%99+1;
    player[i].attack = (rand()%99+1)/(double)100;
    player[i].defense =(rand()%99+1)/(double)100;
  }

}

void disp_player(struct parameter player[])
{
  int i;

  printf("No  HP  MP  AT    DE \n");
  for (i=0; i<PLAYER; i++) {
    printf("%2d  %2d  %2d  %.2f  %.2f\n", 
           player[i].no, player[i].hp, player[i].mp, player[i].attack, player[i].defense);
  }

}

void save(struct parameter player[])
{
  FILE *fp_write;
  int i;

  if ((fp_write = fopen("save.dat", "w"))==NULL) {
    printf("can't open file.");
    exit(1);
  }

  fprintf(fp_write, "No  HP  MP  AT    DE \n");

  for (i=0; i<PLAYER; i++) {
    fprintf(fp_write, "%2d  %2d  %2d  %.2f  %.2f\n", player[i].no, player[i].hp, player[i].mp, player[i].attack, player[i].defense);
  }

  fclose(fp_write);

}

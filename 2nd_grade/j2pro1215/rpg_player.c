#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 10
#define NAME 8+1

void initialize(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[]);
void disp_array(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[]);

int main(void)
{
  int no[PLAYER];
  char name[PLAYER][NAME];
  int hp[PLAYER];
  int mp[PLAYER];
  double attack[PLAYER];
  double defence[PLAYER];
  int player_no;

  //srand((unsigned)time(NULL));
  srand(1);

  initialize(no, name, hp, mp, attack, defence);

  disp_array(no, name, hp, mp, attack, defence);

  return 0;
}

void initialize(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[])
{
  int i, j;

  for (i=0; i<PLAYER; i++) {
    no[i] = i;
    for (j=0; j<NAME-1; j++) { 
      name[i][j] = 'a'+rand()%26;
    }
    name[i][j] = '\0';
    hp[i] = rand()%100;
    mp[i] = rand()%100;
    attack[i] = (double)rand()/RAND_MAX;
    defence[i] = (double)rand()/RAND_MAX;
  }

}

void disp_array(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[])
{
  int i;

  printf(" No  Name     HP MP AT   DE \n");
  for (i=0; i<PLAYER; i++) {
    printf("[%2d] ", no[i]);
    printf("%s", name[i]);
    printf(" ");
    printf("%2d %2d %.2f %.2f\n", hp[i], mp[i], attack[i], defence[i]);
  }

}


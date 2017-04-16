#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER 10
#define NAME 8+1

void initialize(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[]);
void disp_array(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[]);
void sort(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[]);
void swap_double(double *x, double *y);
void swap_int(int *x, int *y);
void swap_char(char *x, char *y);

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

  sort(no, name, hp, mp, attack, defence);

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

void sort(int no[], char name[][NAME], int hp[], int mp[], double attack[], double defence[])
{
  int i, j, k, index;

  for (i=0; i<PLAYER-1; i++) {
    index = i;
    for (j=i+1; j<PLAYER; j++) {
      if(attack[j]>attack[index]) {
	index = j;
      }
    }
    swap_double(&attack[i], &attack[index]);
    swap_double(&defence[i], &defence[index]);
    swap_int(&no[i], &no[index]);
    swap_int(&hp[i], &hp[index]);
    swap_int(&mp[i], &mp[index]);
    for (k=0; name[i][k]!='\0' && name[index][k]!='\0'; k++) {
      swap_char(&name[i][k], &name[index][k]);
    }
  }
}

void swap_double(double *x, double *y)
{
  double tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

void swap_int(int *x, int *y)
{
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

void swap_char(char *x, char *y)
{
  char tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp_read;
  FILE *fp_write;
  FILE *fp_append;
  int attack;
  int defense;

  /* READ */
  fp_read = fopen("ability.dat", "r");
  if(fp_read==NULL) {
    printf("can't open file.\n");
    exit(1);
  }
  
  fscanf(fp_read, "%d", &attack);
  fscanf(fp_read, "%d", &defense);

  printf("attack  = %d\n", attack);
  printf("defense = %d\n", defense);

  fclose(fp_read);

  /* WRITE */
  fp_write = fopen("ability.dat", "w");
  if(fp_write==NULL) {
    printf("can't open file.\n");
    exit(1);
  }
  
  attack += 10;
  defense += 10;

  fprintf(fp_write, "%d\n", attack);
  fprintf(fp_write, "%d\n", defense);

  fclose(fp_write);

  /* APPEND */
  fp_append = fopen("ability.dat", "a");
  if(fp_append==NULL) {
    printf("can't open file.\n");
    exit(1);
  }
  
  attack += 10;
  defense += 10;

  fprintf(fp_append, "%d\n", attack);
  fprintf(fp_append, "%d\n", defense);

  fclose(fp_append);

  return 0;
}

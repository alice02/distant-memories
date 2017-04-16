#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM 30			/* �����ʤɤ��Ǽ��������γ��ݤ��륵���� */
#define WORD_SIZE 235881	/* ����ե�����ιԿ� */
#define TRUE 1
#define FALSE 0
#define XORKEY 0x34509		/* �Ź沽�θ� */
#define RETRY 7

typedef struct
{
  char word_ans[NUM+1];		/* �������Ǽ��������(����30ʸ��) */
  char word_disp[NUM+1];	/* ʸ����ɽ���Ѥ�����(����30ʸ��) */
  char used_words[26];   	/* ���Ѥ���ʸ�����Ǽ��������
				   (����ե��٥åȾ�ʸ��26ʸ��ʬ)*/
  char miss_words[NUM][NUM+1];	/* �������ñ�����(30ʸ����30��ʬ) */
  int right_count, wrong_count;	/* �������������� */
  int hit, mistake, length;	/* ���줾�졤�ҥåȿ�,���Ԥ�����,������ʸ���� */
} GAME_STATE;

/* �ؿ��ץ�ȥ�������� */
void initialize(GAME_STATE *state);
void hangman(GAME_STATE *state);
void endscreen(GAME_STATE *state);

int main(void)
{
  GAME_STATE state;
  int select = FALSE;
  int i;

  /* ����������Ӥ˴ؤ����ѿ��ν���� */
  state.right_count = state.wrong_count = 0;

  for (i = 0; i < NUM; i++) {
    state.miss_words[i][0] = '\0';
  }

  do {
    initialize(&state);

    printf("\n ans:%s\n", state.word_ans);
    
    /* �ᥤ��롼�� */
    while (1) {
      hangman(&state);

      if (state.hit == state.length) {
	state.right_count++;
	printf("����Ǥ� %s\n", state.word_ans);
	printf("³���ޤ���(y/n)?");
	select = getChar();
	break;
      }
      else if (state.mistake == 7) {
	strcpy(&(state.miss_words[state.wrong_count][0]), state.word_ans);
	state.wrong_count++;
	printf("��ǰ ����� %s �Ǥ���\n", state.word_ans);
	printf("³���ޤ���(y/n)?");
	select = getChar();
	break;
      }
    }

    printf("\n\n");

  } while(select == 'y');


  endscreen(&state);

  return 0;
}

/* ����� */
void initialize(GAME_STATE *state)
{
  int i, num;
  char tmp[NUM];
  FILE *fp;

  srand((unsigned)time(NULL));

  /* �ե�����Υ����ץ� */
  fp = fopen("words", "r");
  if (fp == NULL) {
    printf("Cannot open words file.\n");
    exit(1);
  }

  state->hit = 0;
  state->mistake = 0;

  /* words��Ŭ���ʹԿ�ʬ�ɤ����Ф��������ñ����Ǽ */
  num = rand() % WORD_SIZE;
  for (i = 0; i < num; i++) {
    fscanf(fp, "%s", tmp);
  }
  fscanf(fp, "%s", state->word_ans);

  /* �����ñ���ʸ������Ĵ�٤� */
  state->length = strlen(state->word_ans);

  /* -------�ν���� */
  for (i = 0; i < state->length; i++) {
    state->word_disp[i] = '-';
  }
  state->word_disp[i] = '\0';

  /* ���Ϥ���ʸ�������˻Ȥ��Ƥ��ʤ���Ƚ�ꤹ������ν���� */
  for (i = 0; i <= 'z'-'a'; i++) {
    state->used_words[i] = FALSE;
  }

  fclose(fp);

}


void hangman(GAME_STATE *state)
{
  int i, hit_flag, skip;
  char c;
  
  hit_flag = FALSE;
  skip = FALSE;

  printf("ñ��:%s\n", state->word_disp);

  printf("�Ȥ�줿ʸ��:");
  for (i = 0; i <= 'z'-'a'; i++) {
    if (state->used_words[i] == TRUE) {
      printf("%c ", 'a'+i);
    }
  }
  printf("\n");

  printf("�Ĥ���:%d\n", RETRY-(state->mistake));

  printf("ʸ�������Ϥ��Ʋ�����:");
  c = getChar();

  if (islower(c)) {
    printf("%c\n", c);
  }
  else {
    printf("�Ѿ�ʸ�������Ϥ��Ʋ�������\n");
    skip = TRUE;
  }
  printf("\n\n");

  /* ���Ǥ����Ϥ���ʸ�����Ȥ��Ƥ��ʤ����γ�ǧ */
  if (state->used_words[c-'a'] == TRUE) {
    printf("���Ǥ˻Ȥ��Ƥ��ޤ�.\n");
    skip = TRUE;
  }

  /* �Ȥ�줿ʸ�����Ǽ������ */
  if (skip == FALSE) {
    state->used_words[c-'a'] = TRUE;
  }

  /* �ҥåȤ��Ƥ��뤫��Ƚ�� */
  for (i = 0; i < state->length && skip == FALSE; i++ ) {
    if (state->word_ans[i] == c || state->word_ans[i] == c - ('a'-'A')) {
      state->word_disp[i] = state->word_ans[i];
      state->hit++;
      hit_flag = TRUE;
    }
  }

  /* ���Ԥ�������Υ������ */
  if (hit_flag == FALSE && skip == FALSE) {
    state->mistake++;
  }

}


void endscreen(GAME_STATE *state)
{
  int t_total, t_right, t_wrong; /* ���Ѥ����ӷ׻��� */
  int i;
  FILE *fp;

  t_total = t_right = t_wrong = 0;

  printf("\n\n*** ������ñ����� ***\n");
  for (i = 0; i < state->wrong_count; i++) {
    printf("��%s\n", &state->miss_words[i][0]);
  }
  printf("**********************\n");

  fp = fopen("record.dat", "r");
  if (fp != NULL) {
    fscanf(fp, "%d %d %d", &t_total, &t_right, &t_wrong); /* �ǡ������ɤ߹��� */
    fclose(fp);

    /* �Ź沽����Ƥ���ǡ��������椹�� */
    t_total ^= XORKEY;
    t_right ^= XORKEY;
    t_wrong ^= XORKEY;
  }

  /* ���Ѥ����Ӥη׻� */
  t_total += (state->right_count + state->wrong_count);
  t_right += state->right_count;
  t_wrong += state->wrong_count;

  printf("\n--------------------------------------\n");
  printf("|          | ��������� | ���Ѥ����� |\n");
  printf("|------------------------------------|\n");
  printf("| ������� |  %4d��    |  %4d��    |\n", (state->right_count + state->wrong_count), t_total);
  printf("|  �����  |  %4d��    |  %4d��    |\n", state->right_count, t_right);
  printf("| ������� |  %4d��    |  %4d��    |\n", state->wrong_count, t_wrong);
  printf("|  ����Ψ  |  %4d\%���� |  %4d\% ��  |\n", (int)((double)state->right_count / (state->right_count + state->wrong_count)*100),  (int)(((double)t_right / t_total*100)));
  printf("--------------------------------------\n");

  fp = fopen("record.dat", "w");
  if (fp == NULL) {
    printf("Can't open file!\n");
    exit(1);
  }

  fprintf(fp, "%d %d %d", t_total^XORKEY, t_right^XORKEY, t_wrong^XORKEY); /* �Ź沽���ƥե�����˽񤭹��� */

  printf("\n�ޤ���\n");

  fclose(fp);

}

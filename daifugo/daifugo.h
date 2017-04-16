#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "network.h"



// ---------------------------------
//       ���� �ޥ������� ����
// ---------------------------------

#define TRUE 1
#define FALSE 0

// check_input()�������
#define ERROR 1    //�������ʤ�����
#define CORRECT 0  //����������

// ������γˤȤʤ���(POINT�ʳ����Ѥ��������)
#define POINT  6            /* ���Υݥ���Ȥ�ï������ã���������ǽ�λ */
#define PLAYER_NUM 4		/* �ץ쥤��οͿ�(4�ʳ��ϥޥ���...) */
#define MAX_CARD_NUM 54  	/* �����ɤκ������(13*4+2) */
#define MAX_MARK_NUM 13		/* 1�ĤΥޡ����ˤĤ�13�� */
#define MAX_PLAYER_CARD 14	/* �ץ쥤��μ껥�κ������ */
#define MAX_FIELD_CARD 14	/* �ե�����ɤ˰��٤˽Ф������(3 4 5 ... K A 2 JK) */

/* ����(�������ä˰�̣�ʤ�) */
#define DAIFUGO 30		/* ���ٹ� */
#define FUGO 20			/* �ٹ� */
#define HINMIN 10		/* ��̱ */
#define DAIHINMIN 0		/* ����̱ */
#define HEIMIN -10		/* ʿ̱ */

// ����ξ��֤�ɽ��(�ص���)
#define EMPTY -1
#define NOBODY -10
#define ALL_PLAYERS 1000

/* �ץ쥤��ξ��� */
#define PLAYING 100      // ���ץ쥤���Ƥ���
#define END 200          // ���������
#define DIA3 300         // ������3����äƤ���
#define FOUL_PLAY 400    // ȿ§������򤷤�
#define MIYAKO_OCHI 500  // ���������

/* �ե�����ɤξ��� */
#define ORDINARY 0  // �Ρ��ޥ����
#define KAIDAN 1    // ����
#define KAKUMEI 2   // ��̿
#define SHIBARI 3   // ���Ф�


/* ���������ץ�������(������) */
/* ʸ���� */
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define DEFAULT_COLOR "\x1b[39m"

/* °�� */
#define CLEAR_ATTRIBUTE "\x1b[0m"
#define BOLD "\x1b[1m"
#define UNDER_LINE "\x1b[4m"
#define HANTEN "\x1b[7m"

/* ���������ץ�������(��������) */
#define CLEAR_DISPLAY "\x1b[2J"	/* ���̥��ꥢ */




// ---------------------------------
//       ���� ��¤�Τ���� ����
// ---------------------------------

/* �����ɣ���ξ��� */
typedef struct {
  int i_mark;	    /* �ޡ����ζ���(0~4,J->S->H->D->C) */
  char c_mark;      /* ɽ���� */
  int i_num;        /* ������(����)�ζ���(2->1->13->...->3) */
  char c_num[3];    /* ɽ���� */
} CARD_DATA;

/* �ץ쥤��ξ��� */
typedef struct {
  int card_num;	    /* ���ߤμ껥����� */
  CARD_DATA card[MAX_PLAYER_CARD + 4];  /* ���äƤ륫���ɤΥǡ��� */
  int status;	    /* �ץ쥤����(PLAYING, END) */
  int pass;	        /* �ѥ�������(TRUE:�ѥ�����, FALSE:�ѥ����Ƥʤ�) */
  int old_rank;	    /* old����(���ٹ�, �ٹ�, ��̱, ����̱) */
  int new_rank;	    /* new����(���ٹ�, �ٹ�, ��̱, ����̱) */
  int point;	    /* �ݥ���Ȥ�Ͽ */
  int rule_flag;    /* �롼��ط��ξ�����Ǽ */
} PLAYER_DATA;




// ---------------------------------
//    ���� �ؿ��ץ�ȥ�������� ����
// ---------------------------------

// ���� card.c ����
// �����ɤ�ʬ�ۤ���
void distribute_card(PLAYER_DATA *player);

// �����ɤ򥽡��Ȥ���(3��2,(JK)��S��H��D��C)
void sort_card(PLAYER_DATA *player, int no);

// �����ɤ����򤵤���
int select_card(PLAYER_DATA *player, CARD_DATA select[]);

// �ե�����ɤ˽Ф��������ɤ�껥������
void delete_used_card(PLAYER_DATA *player, CARD_DATA select[]);

// �����ɸ�
void change_card(PLAYER_DATA *player, int player_no);

// ���ꤷ���ץ쥤��˥����ɤ�����
void send_card(PLAYER_DATA *player, CARD_DATA *select);

// �����ɥǡ����ν����
void init_card_data(CARD_DATA data[]);

// ���򤷤������ɤν����
void init_select_card(CARD_DATA *select);


// ���� disp.c ����
// �����ץ˥󥰥�å�����
void opening(void);

// �ե�����ɤ�ɽ��
void disp_field(PLAYER_DATA *player, CARD_DATA *field, int num, int turn, int field_status);

// �����μ껥��ɽ��(�����С�����)
void disp_card_all(PLAYER_DATA *player);

// ��ʬ�μ껥����ɽ��(���饤����ȸ���)
void disp_my_card(PLAYER_DATA *player);

// ����η�̤�ɽ��
void disp_result(PLAYER_DATA *player);

// "ALL Players PASS!!!"��ɽ��
void disp_all_pass_message(void);

// "PASS"��ɽ��
void disp_pass_message(void);

// "8�ڤ�!!"��ɽ��
void disp_yagiri_message(void);

// "��̿!!!"��ɽ��
void disp_kakumei_message(void);


// ���� rule.c ����
// ���硼������õ��
int joker_search(CARD_DATA select[], int num, int pos);

// ���򤷤������ɤ��ե�����ɤ˽Ф��뤫��ǧ
int check_input (CARD_DATA field[], CARD_DATA select[], int num, int old_num);

// ȿ§����������å�
int check_foul_play(CARD_DATA *field, int field_status, int select_num);

// ��̿�򵯤���
void kakumei(PLAYER_DATA *data, int field_status);

// 8�ڤ�
int yagiri(CARD_DATA *select);


// ���� daifugo_server.c ����
// �����
void initialization(PLAYER_DATA *player, int count, int s[]);

/* �ݥ���Ȥ�׻� */
int calc_point(PLAYER_DATA *player);

// ï���饲����򳫻Ϥ��뤫����
int set_first_player(PLAYER_DATA *player, int game_count, int s[]);

// ���ٹ�Υᥤ��롼��
void game(PLAYER_DATA *player, int game_count, int s[], fd_set *readfds);

/* ���οͤΥ�����ˤ��� */
int set_next_turn(PLAYER_DATA *player, int turn);

/* �����Ƚ�� */
void judge_rank(PLAYER_DATA *player, int turn, int count, int foul_play_count, int miyako_ochi);


// ���� rule.c ����
/* ���餫��ץ쥤��No�����(new_rank) */
int get_rank_to_playerNo_new(PLAYER_DATA *player, int rank);

/* ���餫��ץ쥤��No�����(old_rank) */
int get_rank_to_playerNo_old(PLAYER_DATA *player, int rank);

// �ѥ��ե饰�ν����
void init_pass_flag(PLAYER_DATA *player);

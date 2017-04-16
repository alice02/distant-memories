//-----------------------------------------------------------------------
//    �ե�����̾   ��  client.c
//    ����        ��  ���饤����Ƚ����˴ؤ���⥸�塼��
//    �ܺ�        ��  ���饤�����¦�Υ�����ʹԤʤɤ�Ԥ���
//
//    ����        ��  2014/02/18    Kouta ASAI          ��������
//-----------------------------------------------------------------------


#include "sugoroQ.h"

int proc_flag = FALSE;


//-----------------------------------------------------------------------
//  �ؿ�̾  ��   print_dot
//  ����    ��  ��...�פ�"����äݤ�"ɽ������ؿ�
//  �����  ��  �ʤ�
//  ����    ��  �ʤ�
//
//  ����    ��  2014/02/18    Kouta ASAI
//-----------------------------------------------------------------------
void print_dot(void)
{
  int i = 0;

  while (proc_flag == FALSE) {
    printf(".");
    usleep(DOT_WAIT_TIME_US);
    fflush(NULL);
    i++;
    if (i == 3) {
      printf("\x1b[3D");
      printf("\x1b[K");
      i = 0;
    }
  }
  proc_flag = TRUE;
}


//-----------------------------------------------------------------------
//  �ؿ�̾  ��   set_client_data
//  ����    ��  �ޥåפ�ɽ������ݤ˻��Ѥ���ǡ����ν����
//  �����  ��  �ʤ�
//  ����    ��  struct board board
//        ���� ���������Τξ����������Ƥ��빽¤��
//  ����    ��  char station[][]
//        ���� ��̾���Ǽ����
//  ����    ��  int money
//        ���� �ؤβ��ͤ��Ǽ
//  ����    ��  int stay
//        ���� ���αؤ�ï���ߤޤäƤ��뤫��Ǽ
//  ����    ��  int have
//        ���� ���αؤ�ï�����äƤ��뤫

//
//  ����    ��  2014/02/17    Yoshitaka TSUMITA, Hikaru NAKASONE
//-----------------------------------------------------------------------
void set_client_data(struct board board, char station[MAP_SIZE][BUF_SIZE], int money[MAP_SIZE], int stay[MAP_SIZE][PLAYER_NUM], int have[MAP_SIZE])
{
  struct station *tmp;
  int i, j;

  tmp = board.s;
  for(i = 0; i < MAP_SIZE; i++){

    strcpy(station[i],tmp->place_name);
    money[i] = tmp->value;
    have[i] = tmp->who_have;
    tmp = tmp->next;
  }

  for(j=0; j<PLAYER_NUM; j++){
    stay[board.p[j].place_id][j] = TRUE;
  }
}


//-----------------------------------------------------------------------
//  �ؿ�̾  ��   input_name
//  ����    ��  �ץ쥤��̾�����Ϥ�����ؿ�
//  �����  ��  �ʤ�
//  ����    ��  struct board board
//        ���� ���������Τξ����������Ƥ��빽¤��
//  ����    ��  int id
//        ���� �ץ쥤��ID
//
//  ����    ��  2014/02/18    Kouta ASAI
//-----------------------------------------------------------------------
void input_name(struct board *board, int id)
{
  char str[BUF_SIZE];

  do {
    printf("̾�������Ϥ��Ƥ�������!!!(���ѣ�ʸ����Ⱦ�ѣ�ʸ���ޤ�): ");
    scanf("%s", str);
  } while(strlen(str) > MAX_NAME_LENGTH);

  strcpy(board->p[id].name ,str);
}

/*---------------------------------------------------
   �ؿ�̾�� hyouji
   ���ס� ������¦�˳ƥץ쥤��ν�̤Ƚ�����ɽ��
   ����͡� �ʤ�
   ������ struct board *board
       ���� ���Ƥι�¤�Τ�ޤȤ᤿���
   ������ 2014/02/03  Shintaro Ota  ��������
---------------------------------------------------*/
void hyouji(struct board *board){
  int i;

  /*
    �ƥץ쥤��ν�̤Ƚ�����ɽ��
   */
  for(i=0; i<PLAYER_NUM; i++){
    printf("%8s: ",board->p[i].name);
    printf("Rank %d  ",board->p[i].rank);
    printf("Money %d\n",board->p[i].money);
  }

}

//-----------------------------------------------------------------------
//  �ؿ�̾  ��   dice
//  ����    ��  ��������򿶤�ؿ�
//  �����  ��  �����������
//  ����    ��  �ʤ�
//
//  ����    ��  2014/02/18    Kouta ASAI
//-----------------------------------------------------------------------
int dice(void)
{
  int i;
  char ch;
  int num;

  init_keyboard();

  printf("\x1b[%d;%dH", 19, 20);
  printf("����������ޤ��衼����  Are you OK? Plase push Enter key.\n");
  do {
    if ( kbhit() ) {
      ch = readkey();
    }
  } while(ch != '\n');

  close_keyboard();

  num = rand()%6+1;

  printf("\x1b[%d;%dH", 21, 20);
  for (i = 0; i < 5; i++) {
    printf(".");
    usleep(DOT_WAIT_TIME_US);
    fflush(NULL);
  }
  printf(" %d !!!\n", num);
  sleep(2);

  return num;
}


int main(void)
{
  struct board board;
  struct client_network_data cnd;
  int player_id;
  int i, j, k;
  char station[MAP_SIZE][BUF_SIZE];
  int money[MAP_SIZE];
  int stay[MAP_SIZE][PLAYER_NUM] = {{FALSE}};
  int have[MAP_SIZE]={-1};
  pthread_t tid;
  int num;

  srand((unsigned)time(NULL));

  // �����Ф���³
  network_connect_client(&cnd);

  printf("¾�Υץ쥤��λ��ä��ԤäƤ��ޤ�������\n\n");

  // playerID�����
  num = network_set_player_id_client(&cnd, &player_id);
  network_check_error(num);
  board.p[player_id].id = player_id;
  printf("Your playerID: %d\n", player_id);

  // ̾��������
  input_name(&board, player_id);

  num = network_send_player_data_client(&cnd, &board, player_id);
  network_check_error(num);

  // �����Ф���ǡ����μ���
  printf("\nConnecting...\n");

  for (i = 0; i < MAX_TURN; i++) {
    // �����
    proc_flag = FALSE;
    printf("%c[2J",ESC);

    // �����Ф���ǡ����μ���
    num = network_recv_station_data_client(&cnd, &board);
    network_check_error(num);

    num = network_recv_player_quiz_data_client(&cnd, &board);
    network_check_error(num);

    // �ǡ����Υ��å�
    for(k=0;k<MAP_SIZE;k++){
      for(j=0;j<PLAYER_NUM;j++){
	stay[k][j]=FALSE;
      }
    }
    set_client_data(board, station, money, stay, have);

    printf("%c[2J",ESC);
    DispMap(station,money,have,stay);
    Status(board);

    // ��������򿶤�
    board.p[player_id].dice = dice();

    printf("%c[2J",ESC);
    DispMap(station,money,have,stay);
    Status(board);
    quiz(&board, player_id);
    sleep(1);
    printf("%c[2J",ESC);

    printf("�̿���Ǥ�\n");
    pthread_create(&tid, NULL, print_dot, NULL);
    num = network_send_player_data_client(&cnd, &board, player_id);
    network_check_error(num);
    proc_flag = TRUE;
    pthread_join(tid, NULL);
    free_station(&board);
    printf("%c[2J",ESC);
  }

  num = network_recv_player_quiz_data_client(&cnd, &board);
  network_check_error(num);
  hyouji(&board);
  return 0;
}

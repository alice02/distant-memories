/*---------------------------------------------------
   �ե�����̾�� server.c
   ���ס� �����Ф����򤹤�⥸�塼��
   �ܺ١� �ƥ��饤����Ȥ���ǡ����������ꡤ������οʹԤ�Ԥ�
   ���� 2014/02/18  Shintaro Ota  ��������
---------------------------------------------------*/

#include "sugoroQ.h"

/*---------------------------------------------------
   �ؿ�̾�� p_keisan
   ���ס� �ƥץ쥤��β��������򤫳�ǧ��Ԥ���
         ����Ǥ���Х�������νФ��ܤ����ʤ�
   ����͡� �ʤ�
   ������ struct board *board
       ���� ���Ƥι�¤�Τ�ޤȤ᤿���
   ������ 2014/02/18  Shintaro Ota  ��������
---------------------------------------------------*/
void p_keisan(struct board *board){
  int i;
  struct station *tmp;

  /*
    ������������ǧ��������Ǥ���Х�������򿶤�
  */
  printf("\n*** player quiz status ***\n");
  for(i=0; i<PLAYER_NUM; i++){
    if(board->p[i].p_answer==(board->q.answer-'0')){
      board->p[i].p_point = board->p[i].dice;
      board->p[i].p_point += (10-board->p[i].answer_time)/2;
      board->p[i].money += (10-board->p[i].answer_time)*10;
      printf("player %d is correct!!\n", i);
      printf("forward %d stations\n", board->p[i].p_point);
    }
    else{
      board->p[i].p_point=0;
    }
  }


  /*
    �ƥץ쥤��ϥ�������νФ��ܤ����ʤ�
  */
  for(i=0; i<PLAYER_NUM; i++){
    board->p[i].place_id += board->p[i].p_point;
    board->p[i].place_id %= MAP_SIZE;
  }

}

/*---------------------------------------------------
   �ؿ�̾�� init
   ���ס� ��¤�ΤΥ��Ф�����
   ����͡� �ʤ�
   ������ struct board *board
       ���� ���Ƥι�¤�Τ�ޤȤ᤿���
   ������ 2014/01/27  Shintaro Ota  ��������
---------------------------------------------------*/
void init(struct board *board){
  int i;
  char str[BUF_SIZE];
  int start_place_id[4]={3,12,18,27};
  /*
    ��¤�ΤΥ��Ф�����
  */
  for(i=0; i<PLAYER_NUM; i++){
    board->p[i].p_answer=0;
    board->p[i].answer_time=0;
    board->p[i].place_id=start_place_id[i];
    board->p[i].rank=1;
    board->p[i].money=5000;
  }

}

/*---------------------------------------------------
   �ؿ�̾�� ranking
   ���ס� �ƥץ쥤��ν����Ƚ���ؤ������դ�
   ����͡� �ʤ�
   ������ struct board *board
       ���� ���Ƥι�¤�Τ�ޤȤ᤿���
   ������ 2014/01/27  Shintaro Ota  ��������
---------------------------------------------------*/
void ranking(struct board *board){
  int i,j;
  struct station *tmp;
  tmp = board->s;

  /*
    �ƥץ쥤��ν���ؤ�����˴���
   */
  for(i=0; i<PLAYER_NUM; i++){
    for(j=0; j<MAP_SIZE; j++){
      tmp=r_access_station(tmp,j);
      if(tmp->who_have==i){
	board->p[i].money+=tmp->value;
      }
    }
  }

  /*
    �ƥץ쥤��ν���⤫�����դ�
  */
  for(i=0; i<PLAYER_NUM; i++){
    for(j=0; j<PLAYER_NUM; j++){
      if(i!=j){
	if(board->p[i].money<board->p[j].money){
	  board->p[i].rank++;
	}
      }
    }
  }
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
    printf("%s: ",board->p[i].name);
    printf("rank %d  ",board->p[i].rank);
    printf("money %d\n",board->p[i].money);
  }

}

/*---------------------------------------------------
   �ؿ�̾�� baibai
   ���ס� �ƥץ쥤�䤬��ư��αؤ��㤦�褦�ˤ���
         �西�������ؤ��餪�⤬����
   ����͡� �ʤ�
   ������ struct board *board
       ���� ���Ƥι�¤�Τ�ޤȤ᤿���
   ������ 2014/02/03  Shintaro Ota  ��������
---------------------------------------------------*/
void baibai(struct board *board){
  int i;
  struct station *tmp;

  /*
    �ƥץ쥤�䤬��ư��αؤ��㤦
   */
  for(i=0; i<PLAYER_NUM; i++){
    //������ξ�硤��ư���ʤ�����ؤ����ʤ��褦�ˤ���
    if(board->p[i].p_answer==(board->q.answer-'0')){
      tmp = board->s;
      tmp=r_access_station(tmp,board->p[i].place_id);
      //��ư��αؤ�ï�������Ƥ��ʤ����
      if(tmp->who_have==-1){
	board->p[i].money-=tmp->value;
	tmp->who_have=i;
      }
      //¾�Υץ쥤�䤬������Ƥ������
      else if(tmp->who_have!=i){
	tmp->value*=1.5;
	board->p[i].money-=tmp->value;
	board->p[tmp->who_have].money+=tmp->value*0.8;
	tmp->who_have=i;
      }
      //��ʬ�ν�����Ƥ���ؤξ��
      else if(tmp->who_have==i){
	board->p[i].money+=tmp->value;
      }
    }
  }

  tmp = board->s;
  /*
    �ƥץ쥤����西�������ؤ��餪�⤬����
   */
  for(i=0; i<MAP_SIZE; i++){
    if(tmp->who_have!=-1){
      board->p[tmp->who_have].money+=tmp->value*0.2;
    }
    tmp=tmp->next;
  }

}

int main(void)
{
  struct server_network_data snd;
  int place=0;
  struct board board;
  int num;
  int i, j;

  srand((unsigned)time(NULL));

  network_init_server(&snd);

  printf("�ץ쥤��μ��դ�λ���ޤ�����\n");
  printf("Sending data...\n");

  num = network_send_player_id_server(&snd);
  network_check_error(num);

  init_station_server(&board);

  num = network_recv_player_data_server(&snd, &board);
  network_check_error(num);

  init(&board);


  /*
    ������λ�ޤǥ������Ԥ�
  */
  printf("Start GAME!!\n\n");
  for (i = 0; i < MAX_TURN; i++) {
    SetQuiz(&board);
    board.q.turn=i+1;
    printf("turn : %2d\n", board.q.turn, i);

    printf("\n*** player ***\n");
    print_player_all(board);
    printf("\n*** station ***\n");
    print_station(board);
    printf("\n*** quiz ***\n");
    printf("quiz: %s\n", board.q.mondai);
    printf("selection:\n");
    for (j = 0; j < SELECTION_NUM; j++) {
      printf("%d. %s\n", j+1, board.q.sentaku[j]);
    }
    printf("answer: %c\n", board.q.answer);


    printf("Sending data...\n");
    num = network_send_station_data_server(&snd, &board);
    network_check_error(num);

    num = network_send_player_quiz_data_server(&snd, &board);
    network_check_error(num);

    printf("Receiving data...\n");
    num = network_recv_player_data_server(&snd, &board);
    network_check_error(num);

    p_keisan(&board);

    baibai(&board);
  }

  ranking(&board);
  num = network_send_player_quiz_data_server(&snd, &board);
  network_check_error(num);

  hyouji(&board);

  return 0;
}

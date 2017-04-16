//-----------------------------------------------------------------------
//    �ե�����̾  ��  network.c
//    ����        ��  �����å��̿��˴ؤ���⥸�塼��
//    �ܺ�        ��  �����С����饤����Ȥ��餳�Υ⥸�塼��δؿ���
//                    �ƤӽФ����Ȥˤ�ꡤ�����å��̿����ǽ�ˤ���
//
//    ����        ��  2014/01/06    Kouta ASAI          ��������
//-----------------------------------------------------------------------


#include "sugoroQ.h"


//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_init_server
//  ����    ��  ������¦�Υ����å��̿����������
//              PLAYER_NUM���ͤޤǥ��饤����Ȥ���³����Τ��Ԥ�
//  �����  ��  �ʤ�
//  ����    ��  struct server_network_data *snd
//        ����  �����Фǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//
//  ����    ��  2014/01/06    Kouta ASAI
//-----------------------------------------------------------------------
void network_init_server(struct server_network_data *nd)
{
  fd_set readfds2;
  int max = 0;         // max num of used socket
  int n = 0;
  int len;
  int clilen;               /* client length */
  struct sockaddr_in saddr; /* ������¦(��ʬ)�Υ��ɥ쥹���� */
  struct sockaddr_in caddr; /* ���饤�����¦�Υ��ɥ쥹����������Ȥ��� */
  char str[1024];           /* string buffer */
  int i, j;                 /* loop counter */
  int msglen;
  int count;
  int yes = 1;

  // �����åȤ��롣
  // ���Υ����åȤ�INET�ɥᥤ��ǥ��ȥ꡼�෿(���ͥ������) ��
  if ((nd->s[0] = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  // saddr����Ȥ�0�ˤ��Ƥ����ʤ��ȡ�bind()�ǥ��顼�������뤳�Ȥ�����
  bzero((char *)&saddr, sizeof(saddr));

  // �����åȤ�̾����Ĥ��� bind()
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = INADDR_ANY;
  saddr.sin_port = htons(PORT); // ���PORT��#define�������

  // connection refused�ˤʤ�ʤ��褦�ˤ���
  setsockopt(nd->s[0], SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(yes));

  if ((bind(nd->s[0], (struct sockaddr *)&saddr, sizeof(saddr))) == -1) {
    perror("bind");
    exit(1);
  }

  // ��³�����Τ��Ԥ� listen()
  // ��2�������ͤ��礭������
  if ((listen(nd->s[0], SOCK_MAX)) == -1) {
    perror("listen");
    exit(1);
  }
  max = 1;   // s[0] is ready


  // PLAYER_NUM���ͤޤ�client����³�����顢�������λ
  while (max < PLAYER_NUM+1) {

    FD_ZERO(&(nd->readfds));    // fds�ν����

    // ���Ǥ˥��饤����Ȥ���³����Ƥ��륽���åȤΥӥåȤ�
    // ���åȤ���select()�θ����оݤˤ��롣
    for (i = 0; i < max; i++) {
      if (nd->s[i] != UNUSED) {
	FD_SET(nd->s[i], &(nd->readfds));
      }
    }

    // ��������³�׵᤬���ä����ϡ�s[0]�ΥӥåȤ�Ω�ġ�
    // �ʲ��ǤϿ�������³�μ����դ���Ԥ���
    if (FD_ISSET(nd->s[0], &(nd->readfds)) != 0) {
      printf("Waiting for connection...\n");
      // ��³���Ω���� accept()
      len = sizeof(caddr);
      nd->s[max] = accept(nd->s[0], (struct sockaddr *)&caddr, &len);
      if (nd->s[max] == -1) {
	perror(NULL);
	exit(1);
      }
      if (max < SOCK_MAX) {
	printf("client accepted : %d  (%d/%d)\n", max, max, PLAYER_NUM);
	max++;
      } else {
	printf("refuse connection.\n");
	strcpy(str, "Server is too busy.\n");
	write(nd->s[max], str, strlen(str));
	close(nd->s[max]);
      }
    }
  }
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_connect_client
//  ����    ��  ���饤����Ȥ��饵���Фؤ���³����
//              �����ФΥۥ���̾�����Ϥ����������Ф���³����
//              �ۥ���̾�����Ϥ������塤network_init_client()��ƤӽФ�
//  �����  ��  �ʤ�
//  ����    ��  struct client_network_data *cnd
//        ����  ���饤����Ȥǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//
//  ����    ��  2014/01/06    Kouta ASAI
//-----------------------------------------------------------------------
void network_connect_client(struct client_network_data *cnd)
{
  int i_ret;
  char buf[255];

  do {
    // �ۥ���̾������
    printf("�����С��Υۥ���̾�����Ϥ��Ƥ���������(q �ǽ�λ)\n");
    fgets(buf, sizeof(buf), stdin);

    // 'q'�����Ϥ��줿��ץ�����λ����
    if (strcmp(buf, "q") == TRUE) {
      exit(EXIT_FAILURE);
    }

    sscanf(buf, "%s", cnd->host);

    i_ret = network_init_client(cnd);  // �����Ф���³���ߤ�
  } while(i_ret == EXIT_FAILURE);  // ���ꤷ���ۥ��Ȥ���³�Ǥ��ʤ����ϥ롼��

}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_init_client
//  ����    ��  ���饤����ȤΥ����å��̿����������
//              ���饤����Ȥ��饵���Ф���³���ߤ�
//  �����  ��  EXIT_FAILURE:��³���ԡ�EXIT_SUCCESS:��³����
//  ����    ��  struct client_network_data *cnd
//        ����  ���饤����Ȥǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//
//  ����    ��  2014/01/06    Kouta ASAI
//-----------------------------------------------------------------------
int network_init_client(struct client_network_data *cnd)
{
  struct sockaddr_in    addr;
  struct hostent *hp;


  /*
   *  �����åȤ��롣���Υ����åȤ�UNIX�ɥᥤ��ǡ����ȥ꡼�෿�����åȡ�
   */
  if ((cnd->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  /* 
   * addr����Ȥ�0�ˤ��Ƥ����ʤ��ȡ�bind()�ǥ��顼�������뤳�Ȥ�����
   */
  bzero((char *)&addr, sizeof(addr));

  /*
   * �����åȤ�̾��������Ƥ���
   */

  hp = gethostbyname(cnd->host);
  if (hp == NULL) {
    perror("No such host");
    return EXIT_FAILURE;
  }
  bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);

  /*
   *  �����С��Ȥ���³���ߤ롣���줬�������뤿��ˤϡ������С������Ǥ�
   *  ���Υ��ɥ쥹��bind()���ơ�listen()��ȯ�Ԥ��Ƥ��ʤ���Фʤ�ʤ���
   */

  if (connect((cnd->fd), (struct sockaddr *)&addr, sizeof(addr)) < 0){
    perror("connect");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_recv_player_quiz_data_client
//  ����    ��  �����Ф���player��¤��(���ץ쥤��Υǡ���)��quiz��¤�Τ�������
//              ���饤����Ȥ���ƤӽФ��ؿ�
//  �����  ��  -1:�������ԡ�0:��³���ǡ�����¾:�Ǹ�˼��������ǡ����ΥХ��ȿ�
//  ����    ��  struct client_network_data *cnd
//        ����  ���饤����Ȥǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//  ����    ��  struct board *board
//        ����  ���������Τξ�����Ǽ���Ƥ���board��¤��(�ݥ���)
//
//  ����    ��  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
// player��¤�Τ�quiz��¤�Τ����(client��)
int network_recv_player_quiz_data_client(struct client_network_data *cnd, struct board *board)
{
  int i;
  int size;

  // player��¤�Τ����
  for (i = 0; i < PLAYER_NUM; i++) { // player��¤�Τ����ץ쥤��ʬ����
    size = recv(cnd->fd, &(board->p[i]), sizeof(struct player), 0);
    if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // �����˼��Ԥ�����return
      return size;
    }
    usleep(WAIT_TIME);  // ���줬������̿�������(?)
  }
  // quiz��¤�Τ����
  size = recv(cnd->fd, &(board->q), sizeof(struct quiz), 0);

  return size;
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_send_player_data_client
//  ����    ��  �����Ф�player��¤�Τ�����(��ʬ�Υץ쥤�ǡ����Τ�)
//              ���饤����Ȥ���ƤӽФ��ؿ�
//  �����  ��  -1:�������ԡ�0:��³���ǡ�����¾:���������ǡ����ΥХ��ȿ�
//  ����    ��  struct client_network_data *cnd
//        ����  ���饤����Ȥǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//  ����    ��  struct board *board
//        ����  ���������Τξ�����Ǽ���Ƥ���board��¤��(�ݥ���)
//  ����    ��  int id
//        ����  �ץ쥤��ID(0��3�Τɤ줫)
//
//  ����    ��  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_send_player_data_client(struct client_network_data *cnd, struct board *board, int id)
{
  int recv_id;
  int size;
  int i;

  for (i = 0; i < PLAYER_NUM; i++) { // ���桼�����Ф����̿���Ԥ��Τǡ�PLAYER_NUM���ͤ����롼��
    // �����Ф��׵ᤷ�Ƥ���ץ쥤��ID
    size = recv(cnd->fd, &recv_id, sizeof(int), 0);
    if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // �����˼��Ԥ�����return
      return size;
    }

    // ��������ID�ȥץ쥤��ID�����פ����ԤΤߥǡ����������
    // ����Τϼ�ʬ�Υץ쥤�ǡ����Τ�(board.p[player_id])
    if (recv_id == id) {
      size = send(cnd->fd, &(board->p[id]), sizeof(struct player), 0);
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_recv_player_data_server
//  ����    ��  �ƥ��饤����Ȥ���player��¤�Τ�������
//              �����Ф���ƤӽФ��ؿ�
//  �����  ��  -1:�������ԡ�0:��³���ǡ�����¾:�Ǹ�˼��������ǡ����ΥХ��ȿ�
//  ����    ��  struct server_network_data *snd
//        ����  �����Фǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//  ����    ��  struct board *board
//        ����  ���������Τξ�����Ǽ���Ƥ���board��¤��(�ݥ���)
//
//  ����    ��  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_recv_player_data_server(struct server_network_data *snd, struct board *board)
{
  int i, j;
  int size;
  int id;

  for (i = 0; i < PLAYER_NUM+1; i++) {
    if (snd->s[i] != UNUSED) {
      FD_SET(snd->s[i], &(snd->readfds));
    }
  }


  for (i = 0; i < PLAYER_NUM; i++) {
    id = i;  // �����Ф��׵᤹��ץ쥤��ID

    // �����饤����Ȥ˥����Ф��׵ᤷ�Ƥ���ץ쥤��ID���Τ餻��
    for (j = 0; j < PLAYER_NUM; j++) {
      if (snd->s[j+1] != UNUSED) {
	size = send(snd->s[j+1], &id, sizeof(int), 0);
	if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // �����˼��Ԥ�����return
	  return size;
	}

      }
    }

    if (snd->s[id+1] != UNUSED) {
      if (FD_ISSET(snd->s[id+1], &(snd->readfds))) {
	// ���ꤷ��player�Υǡ����Τ߼������
	size = recv(snd->s[i+1], &(board->p[id]), sizeof(struct player), 0);
	if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // �����˼��Ԥ�����return
	  return size;
	}

      }
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_send_player_quiz_data_server
//  ����    ��  �ƥ��饤����Ȥ�player��¤��(���ץ쥤�ǡ���)��quiz��¤�Τ�����
//              �����Ф���ƤӽФ��ؿ�
//  �����  ��  -1:�������ԡ�0:��³���ǡ�����¾:�Ǹ�����������ǡ����ΥХ��ȿ�
//  ����    ��  struct server_network_data *snd
//        ����  �����Фǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//  ����    ��  struct board *board
//        ����  ���������Τξ�����Ǽ���Ƥ���board��¤��(�ݥ���)
//
//  ����    ��  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_send_player_quiz_data_server(struct server_network_data *snd, struct board *board)
{
  int size;
  int i, j;

  for (i = 0; i < PLAYER_NUM; i++) {  // �����饤����Ȥ��Ф�����������
    if (snd->s[i+1] != UNUSED) {
      for (j = 0; j < PLAYER_NUM; j++) {  // ���ץ쥤��Υץ쥤�ǡ���������
	size = send(snd->s[i+1], &(board->p[j]), sizeof(struct player), 0);
	if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // �����˼��Ԥ�����return
	  return size;
	}
	usleep(WAIT_TIME);
      }
      send(snd->s[i+1], &(board->q), sizeof(struct quiz), 0);
      if (size == NETWORK_ERROR || size == NETWORK_DISCONNECTED) {  // �����˼��Ԥ�����return
	return size;
      }
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_set_player_id_client
//  ����    ��  �ץ쥤��ID�򥵡��Ф���������
//              ���饤����Ȥ���ƤӽФ��ؿ�
//  �����  ��  -1:�������ԡ�0:��³���ǡ�����¾:���������ǡ����ΥХ��ȿ�
//  ����    ��  struct client_network_data *cnd
//        ����  ���饤����Ȥǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//  ����    ��  int *id
//        ����  �ץ쥤��ID(�ݥ���)
//
//  ����    ��  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_set_player_id_client(struct client_network_data *cnd, int *id)
{
  int size;

  size = recv(cnd->fd, id, sizeof(int), 0);
  
  return size;
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_send_player_id_server
//  ����    ��  �ץ쥤��ID�򥯥饤����Ȥ���������
//              �����Ф���ƤӽФ��ؿ�
//  �����  ��  -1:�������ԡ�0:��³���ǡ�����¾:�Ǹ�����������ǡ����ΥХ��ȿ�
//  ����    ��  struct server_network_data *snd
//        ����  �����Фǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//
//  ����    ��  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_send_player_id_server(struct server_network_data *snd)
{
  int i;
  int size;

  for (i = 0; i < PLAYER_NUM; i++) {
    if (snd->s[i+1] != UNUSED) {
      size = send(snd->s[i+1], &i, sizeof(int), 0);
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_send_station_data_server
//  ����    ��  ��̾�ʤɤαؤΥǡ����򥯥饤����Ȥ���������
//             �����Ф���ƤӽФ��ؿ�
//  �����  ��  -1:�������ԡ�0:��³���ǡ�����¾:���������ǡ����ΥХ��ȿ�
//  ����    ��  struct server_network_data *snd
//        ����  �����Фǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//  ����    ��  struct board *board
//        ����  ���������Τξ�����Ǽ���Ƥ���board��¤��(�ݥ���)
//
//  ����    ��  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_send_station_data_server(struct server_network_data *snd, struct board *board)
{
  int i, j;
  struct station *station;
  int size;

  for (i = 0; i < PLAYER_NUM; i++) {
    station = board->s;
    if (snd->s[i+1] != UNUSED) {
      for (j = 0; j < MAP_SIZE; j++) {
	size = send(snd->s[i+1], &(station->place_name), sizeof(char)*256, 0);
	size = send(snd->s[i+1], &(station->value), sizeof(int), 0);
	size = send(snd->s[i+1], &(station->who_have), sizeof(int), 0);
	usleep(WAIT_TIME);  // ���줬������̿�������(?)
	station = station->next;
      }
    }
  }

  return size;
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_recv_station_data_client
//  ����    ��  ��̾�ʤɤαؤΥǡ����򥵡��Ф����������
//             ���饤����Ȥ���ƤӽФ��ؿ�
//  �����  ��  -1:�������ԡ�0:��³���ǡ�����¾:���������ǡ����ΥХ��ȿ�
//  ����    ��  struct client_network_data *cnd
//        ����  ���饤����Ȥǥ����å��̿���ɬ�פʥǡ���(�ݥ���)
//  ����    ��  struct board *board
//        ����  ���������Τξ�����Ǽ���Ƥ���board��¤��(�ݥ���)
//
//  ����    ��  2014/01/20    Kouta ASAI
//-----------------------------------------------------------------------
int network_recv_station_data_client(struct client_network_data *cnd, struct board *board)
{
  int j;
  char name[MAP_SIZE][BUF_SIZE];
  int value[MAP_SIZE];
  int have[MAP_SIZE];
  int size;


  for (j = 0; j < MAP_SIZE; j++) {
    size = recv(cnd->fd, name[j], sizeof(char)*256, 0);
    size = recv(cnd->fd, &(value[j]), sizeof(int), 0);
    size = recv(cnd->fd, &(have[j]), sizeof(int), 0);
    usleep(WAIT_TIME);  // ���줬������̿�������(?)
  }

  init_station_client(board, name, value, have);

  return size;
}



//-----------------------------------------------------------------------
//  �ؿ�̾  ��  network_check_error
//  ����    ��  �̿��ǥ��顼��ȯ���������å�������ɽ����������λ����
//  �����  ��  �ʤ�
//  ����    ��  int num
//        ����  recv or send�ؿ��������
//
//  ����    ��  2014/02/17    Kouta ASAI
//-----------------------------------------------------------------------
void network_check_error(int num)
{
  if (num == NETWORK_ERROR) {
    printf("�̿����顼��ȯ�����ޤ������ץ�����λ���ޤ���\n");
    exit(100);
  }
  else if (num == NETWORK_DISCONNECTED) {
    printf("�����С��Ȥ���³�����Ǥ���ޤ������ץ�����λ���ޤ���\n");
    exit(101);
  }
}

/*
  FILE NAME: network.c

  DESCRIPTION:
  �ͥåȥ���̿��˴ؤ������
*/


#include "daifugo.h"


void network_init_server(int s[], fd_set* readfds)
{
  //  int s[SOCK_MAX + 1]; // array of socket descriptors
  int max = 0;         // max num of used socket
  int n = 0;
  int len;
  //  fd_set readfds;
  int clilen;               /* client length */
  struct sockaddr_in saddr; /* ������¦(��ʬ)�Υ��ɥ쥹���� */
  struct sockaddr_in caddr; /* ���饤�����¦�Υ��ɥ쥹����������Ȥ��� */
  char str[1024];           /* string buffer */
  int i, j;                 /* loop counter */
  int msglen;
  int count;
  int on = 1;
  
  // �����åȤ��롣
  // ���Υ����åȤ�INET�ɥᥤ��ǥ��ȥ꡼�෿(���ͥ������) ��
  if ((s[0] = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }
  
  // saddr����Ȥ�0�ˤ��Ƥ����ʤ��ȡ�bind()�ǥ��顼�������뤳�Ȥ�����
  bzero((char *)&saddr, sizeof(saddr));
  
  // �����åȤ�̾����Ĥ��� bind()
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = INADDR_ANY;
  saddr.sin_port = htons(PORT); // ���PORT��#define�������
  
  /// !!!!!!!!
  setsockopt(s[0], SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  /// !!!!!!!!

  if ((bind(s[0], (struct sockaddr *)&saddr, sizeof(saddr))) == -1) {
    perror("bind");
    exit(1);
  }
  
  // ��³�����Τ��Ԥ� listen()
  // ��2�������ͤ��礭������
  if ((listen(s[0], SOCK_MAX)) == -1) {
    perror("listen");
    exit(1);
  } 
  max = 1;   // s[0] is ready
  
  // �ᥤ��롼��
  /// 4�ͽ��ޤä��顢�������λ
  while (max < PLAYER_NUM+1) {

    FD_ZERO(readfds);    // fds�ν����
    printf("max: %d\n", max);

    // ���Ǥ˥��饤����Ȥ���³����Ƥ��륽���åȤΥӥåȤ�
    // ���åȤ���select()�θ����оݤˤ��롣
    for (i = 0; i < max; i++) {
      if (s[i] != UNUSED) {
	FD_SET(s[i], readfds);
      }
    }


    // ��������³�׵᤬���ä����ϡ�s[0]�ΥӥåȤ�Ω�ġ�
    // �ʲ��ǤϿ�������³�μ����դ���Ԥ���
    if (FD_ISSET(s[0], readfds) != 0) {
      printf("Accept New one.\n");
      // ��³���Ω���� accept()
      len = sizeof(caddr);
      s[max] = accept(s[0], (struct sockaddr *)&caddr, &len);
      printf("%d = accept()\n", s[max]);
      if (s[max] == -1) {
	perror(NULL);
	exit(1);
      }
      if (max < SOCK_MAX) {
	printf("client accepted(%d).\n", max);
	max++;
      } else {
	printf("refuse connection.\n");
	strcpy(str, "Server is too busy.\n");
	write(s[max], str, strlen(str));
	close(s[max]);
      }
    }
  }
}



void network_init_client(int *fd, char *host[])
{
  struct sockaddr_in    addr;
  struct hostent *hp;


  /*
   *  �����åȤ��롣���Υ����åȤ�UNIX�ɥᥤ��ǡ����ȥ꡼�෿�����åȡ�
   */
  if ((*fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }

  /* 
   * addr����Ȥ�0�ˤ��Ƥ����ʤ��ȡ�bind()�ǥ��顼�������뤳�Ȥ�����
   */
  bzero((char *)&addr, sizeof(addr));

  /*
   * �����åȤ�̾��������Ƥ���
   */

  hp = gethostbyname(host[1]);
  if (hp == NULL) {
    perror("No such host");
    exit(1);
  }
  bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);

  /*
   *  �����С��Ȥ���³���ߤ롣���줬�������뤿��ˤϡ������С������Ǥ�
   *  ���Υ��ɥ쥹��bind()���ơ�listen()��ȯ�Ԥ��Ƥ��ʤ���Фʤ�ʤ���
   */

  if (connect((*fd), (struct sockaddr *)&addr, sizeof(addr)) < 0){
    perror("connect");
    exit(1);
  }

}



// ���饤����Ȥ�control_data������
void send_control_data(int s[], int control)
{
  int i;

  for (i = 0; i < PLAYER_NUM; i++) {
	if (s[i+1] != UNUSED) {
	  send(s[i+1], &control, sizeof(int), 0);
	}
  }

}

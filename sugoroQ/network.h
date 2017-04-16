#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <sys/time.h>
#include <unistd.h>
#include <netdb.h>


#define PORT 8765       // サーバーが使うポート番号
#define SOCK_MAX 5      // 最大ソケット数をここで決めた (最大32)
#define UNUSED (-1)
#define WAIT_TIME 10000  // データを送受信するときの待ち時間[us](これがないと安定しない...)
#define NETWORK_ERROR -1
#define NETWORK_DISCONNECTED 0



struct server_network_data
{
  int s[PLAYER_NUM+1];
  fd_set readfds;
  int id[PLAYER_NUM];
};


struct client_network_data
{
  int fd;
  char host[256];
};


void network_init_server(struct server_network_data *nd);
int network_init_client(struct client_network_data *cnd);
void network_connect_client(struct client_network_data *cnd);
int network_recv_player_quiz_data_client(struct client_network_data *cnd, struct board *board);
int network_send_player_data_client(struct client_network_data *cnd, struct board *board, int id);
int network_recv_player_data_server(struct server_network_data *snd, struct board *board);
int network_send_player_quiz_data_server(struct server_network_data *snd, struct board *board);
int network_set_player_id_client(struct client_network_data *cnd, int *id);
int network_send_player_id_server(struct server_network_data *snd);
int network_send_station_data_server(struct server_network_data *snd, struct board *board);
void network_check_error(int num);

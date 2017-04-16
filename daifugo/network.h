#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> 
#include <sys/time.h>   /* selectシステムコール */
#include <unistd.h>
#include <netdb.h>


#define PORT 8765       // サーバーが使うポート番号
#define SOCK_MAX 5      // 最大ソケット数をここで決めた (最大32)
#define UNUSED (-1)

#define FIELD_DATA  100
#define SELECT_CARD 200
#define PASS        300
#define ALL_PASS    400
#define YAGIRI      500
#define KAKUMEI_MSG 600
#define RESULT      700
#define END_GAME    800


// 関数プロトタイプ宣言
void network_init_server(int s[], fd_set* readfs);
void network_init_client(int *fd, char *host[]);
void send_control_data(int s[], int control);

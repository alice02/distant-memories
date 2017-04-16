#define MAX_NAME_LENGTH 8
#define DOT_WAIT_TIME_US 400000

void print_dot(void);
void set_client_data(struct board board, char station[MAP_SIZE][BUF_SIZE], int money[MAP_SIZE], int stay[MAP_SIZE][PLAYER_NUM], int have[MAP_SIZE]);
void input_name(struct board *board, int id);
int dice(void);

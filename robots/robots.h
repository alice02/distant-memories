#define X_SIZE 60
#define Y_SIZE 20
#define TRUE 1
#define FALSE 0
#define ALIVE 0
#define DEAD 1
#define WAIT_FOR_END -1
#define NORMAL 0
#define SAVE_DATA_COUNT 10


struct zahyou {
  struct zahyou *next;
  int x;
  int y;
};


struct save_data {
  int score;
  char name[20+1];
  int level;
  int num;
};


/* 関数プロトタイプ宣言 */
void initialization(struct zahyou *header, struct zahyou *last, struct zahyou *player, int level, int *robot_num, int *remaining);
void disp_field(struct zahyou *r_header, struct zahyou player, struct zahyou *s_header);
struct zahyou *set_robots(struct zahyou *x, int table[][X_SIZE]);
void teleport(struct zahyou *player, struct zahyou *robo_header, struct zahyou *scrap_header);
void move_robots(struct zahyou *header, struct zahyou player);
int move_player(struct zahyou *player, struct zahyou *r_header, struct zahyou *s_header);
int crash_judge(struct zahyou *r_header, struct zahyou player, struct zahyou *s_header, struct zahyou *s_last, int r_num, int *remaining, int *score);
int delete_robots(struct zahyou *header, int x, int y);
int min(int , int );
struct zahyou *set_scrap(struct zahyou *tmp, int x, int y);
void game_over(void);
void stage_clear(void);

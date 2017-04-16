#define CHKFIELDFLAG(name, x, y) (name->field_flag[y][x])
#define CHKFIELD(name, x, y) (name->field[y][x])
#define TRUE 1
#define FALSE 0
#define MINE -1
#define CLOSE 0
#define OPEN 1
#define MFLAG 2
#define QFLAG 3
#define BEGINNING 1
#define INTERMEDIATE 2
#define ADVANCED 3
#define CUSTOM 4
#define ALIVE 1
#define DEAD 0
#define EDGE 1

typedef struct {
  int **field;
  int **field_flag;
  int dead_flag;
  int x_size;
  int y_size;
  int mines;
  int mflag_count;
  int open_count;
  int play_level;
} PARAMETER;

typedef struct {
  int first;
  int second;
  int third;
} SAVE_DATA;


/* 関数プロトタイプ宣言 */
void game_over(void);
void game_clear(int time);
void see_you(void);
void opening_message(void);
void disp_level_select(void);
void disp_record(void);
void save_record(int time, int level);
void judge_new_record(SAVE_DATA *record, int time, int level);
void draw_cursor(PARAMETER *data, int x, int y, int *oldc);
char flag_2_char(int flag);
void cursor_range_limit(PARAMETER *data, int *x, int *y);
void allocate_field(PARAMETER *data);
void set_values(PARAMETER *data, int x, int y, int num);
void set_custom(PARAMETER *data);
void level_select(PARAMETER *data);
void set_mines(PARAMETER *data);
void set_value_and_flag(PARAMETER *data);
void refresh_field(PARAMETER *data, int x, int y);
void init_curses(void);
void init(PARAMETER *data);
void msweeper(PARAMETER *data);
void judge(PARAMETER *data, int time);
int check_mine(PARAMETER *data, int x, int y, int i, int j);
int check_around_mines(PARAMETER *data, int x, int y);
void draw_field(PARAMETER *data);
void range_limit(PARAMETER *data, int x, int y, int i, int j);
void open_field(PARAMETER *data, int x, int y);
int check_mflag(PARAMETER *data, int x, int y, int i, int j);
void agree_around_flags(PARAMETER *data, int x, int y);
void key_proc(PARAMETER *data, int *x, int*y, int *oldc);
int retry(void);
void my_free(PARAMETER *data);

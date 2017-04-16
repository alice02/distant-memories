#define RED    "\x1b[31m"
#define BLUE   "\x1b[34m"
#define GREEN  "\x1b[32m"
#define PURPLE "\x1b[35m"
#define DEFAULT_COLOR "\x1b[39m"

#define ESC 0x1B

void quiz(struct board *board, int id);
void set_quiz(struct quiz *q);
void disp_quiz(struct quiz q);
void disp_selection(struct quiz q);
void input(struct player *p);
void disp_time_bar(void);  //スレッド
void count_time(void);  //スレッド
void judge(struct board board, int id);
void init_keyboard();
void close_keyboard();
int kbhit();
int readkey();
void DispMap();

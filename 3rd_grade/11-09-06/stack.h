// 構造体の宣言

struct stack
{
  int  i_size;  // スタックのサイズ
  int  i_sp;  // スタックポインタ
  int  *ia_stack;  // データを格納する領域の先頭番地
};


// 関数プロトタイプ宣言

void  my_make_stack(struct stack  *ss,
		    int  i_size);

int  my_push(struct stack  *ss,
	     int  i_num);

int  my_pop(struct stack  *ss,
	    int  *ip_num);

/*
  FILE NAME: rule.c

  DESCRIPTION:
  ルールに関する関数
*/


#include "daifugo.h"


/* 選択したカードがフィールドに出せるか確認 */
int check_input (CARD_DATA field[], CARD_DATA select[], int num, int old_num)
{
  //  int ct_f,ct_s;
  // int ct_step = 0;
  int i,j;
  int tmp = CORRECT;
  CARD_DATA card_tmp;
  int num_flag  = FALSE;
  int j_flag = FALSE;
  int dum = 0;

  //場に出すカードの枚数をチェック

  /*  if(num != old_num){
      return ERROR;
      }
  */

  //  return CORRECT;

  if(old_num == 0 || num == old_num){
    if(num != 1){

      //カードを数字の小さい順並び替えて判定しやすく
      for (i = 0; i < num-1; i++) {
	for (j = num-1; i < j; j--) {
	  if(select[j].i_num > select[j-1].i_num) {
	    card_tmp = select[j];
	    select[j] = select[j-1];
	    select[j-1] = card_tmp;
	  }
	}
      }
      printf("select\n");
      for(i = 0; i < num; i++){
	printf("%c-%s",select[i].c_mark,select[i].c_num);
      }
      printf("\n");
      printf("field\n");
      for(i = 0; i < num; i++){
	printf("%c-%s",field[i].c_mark,field[i].c_num);
      }
      printf("\n");
      
      
      for(i = 1; i < num; i++){
	if(select[i-1].i_mark != select[i].i_mark){
	  if(select[i-1].i_num != select[i].i_num && select[i].i_num != 0){
	    /*0はJOKER*/
	    printf("error1\n");
	    return ERROR;
	  }else{
	    num_flag = TRUE;
	  }
	}else{
	  num_flag = FALSE;
	  break;
	}
      }


      if(num_flag == FALSE){
	if(num >= 3){
	  for(i = 1; i < num; i++){
	    printf("i = %d\n",i);
	    if(select[i-1].i_mark == select[i].i_mark || select[i].i_mark == 0){
	      if(select[i-1].i_num != select[i].i_num+1 && select[i].i_num != 0){
		j_flag = joker_search(select,num,i);
		if(j_flag != TRUE){
		  printf("error2\n");
		  return ERROR;
		}
	      }
	    }else{
	      printf("error3\n");
	      return ERROR;
	    }
	  }
	}else{
	  return ERROR;
	}
      }


      if(field[num-1].i_num == 0){
	dum = 2;
	
      }else{
	dum = 1;
      }

      if(old_num != 0 && select[0].i_num > field[num-dum].i_num+dum-1 && j_flag != TRUE){
	return ERROR;
      }      
       
    }else{

      if(field[0].i_num == 0 && old_num != 0){
	if(select[0].i_mark != 1 || strcmp(select[0].c_num,"3 ") != 0){
	  printf("error_supe3\n");
	  return ERROR;
	}else{
	  return CORRECT; 
	}
      }else if(old_num != 0 && field[num-1].i_num < select[0].i_num){
	return ERROR;
      }
    }
  }else{
    return ERROR;
  }

  return tmp;
}


int joker_search(CARD_DATA select[], int num, int pos)
{

  int tmp = 0;
  
  printf("%c-%s\n",select[num].c_mark,select[num].c_num);
  
  if(select[num-1].i_num == 0){
    if(select[pos].i_num+2 == select[pos-1].i_num){
      if(select[pos].i_num-2 == select[pos+1].i_num || select[pos+1].i_num == 0)
      tmp = 1;
    }
  }
  
  return tmp;
}


/* ↓↓↓↓↓↓  ルール ↓↓↓↓↓↓ */

/* 反則あがりチェック */
int check_foul_play(CARD_DATA *field, int field_status, int select_num)
{
  int flag;
  int i;

  flag = FALSE;

  for (i = 0; field[i].i_mark != EMPTY; i++) {
    /* 最後に出したカードに「8」が含まれている(階段の場合を除く) */
    if (field_status != KAIDAN && strcmp(field[i].c_num, "8 ") == 0) {
      init_card_data(field);
      flag = TRUE;
    }
    /* 最後に出したカードに「ジョーカー」が含まれている */
    else if (field[i].c_mark == 'J') {
      flag = TRUE;
    }
    /* 最後に出したカードが「スペ3」の1枚 */
    else if (select_num == 1 && field[i].c_mark == 'S' && strcmp(field[i].c_num, "3 ") == 0) {
      flag = TRUE;
    }
    /* 革命が起きていない状態で、最後に出したカードに「2」が含まれている */
    else if (field_status != KAKUMEI && strcmp(field[i].c_num, "2 ") == 0) {
      flag = TRUE;
    }
    /* 革命が起きている状態で、最後に出したカードに「3」が含まれている */
    else if (field_status == KAKUMEI && strcmp(field[i].c_num, "3 ") == 0) {
      flag = TRUE;
    }
  }

  return flag;
}



/* 革命を起こす */
void kakumei(PLAYER_DATA *data, int field_status)
{
  int i, j, k;
  /*                                    A  , 2  , 3  ,  4 ,  5 ,  6 , 7 , 8 , 9 ,10 , J ,  Q ,  K */
  int kakumei_table[MAX_MARK_NUM]  =  { 12 , 13 ,  1 ,  2 ,  3 ,  4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 };
  int ordinary_table[MAX_MARK_NUM] =  {  2 ,  1 , 13 , 12 , 11 , 10 , 9 , 8 , 7 , 6 , 5 ,  4 ,  3 };

  for (i = 0; i < PLAYER_NUM; i++) {
    for (j = 0; j < data[i].card_num; j++) {
      for (k = 0; k < MAX_MARK_NUM; k++) {
		// フィールドの状態が通常状態なら革命状態にする
		if (field_status == ORDINARY) {
		  if (data[i].card[j].i_num == ordinary_table[k]) {
			data[i].card[j].i_num = kakumei_table[k];
			break;
		  }
		}
		// フィールドの状態が革命状態なら通常状態にする
		else {
		  if (data[i].card[j].i_num == kakumei_table[k]) {
			data[i].card[j].i_num = ordinary_table[k];
			break;
		  }
		}
      }
    }
  }

}


/* 8切り */
int yagiri(CARD_DATA *select)
{
  int i, flag = FALSE;
  
  for (i = 0; select[i].i_mark != EMPTY; i++) {
    if(strcmp(select[i].c_num, "8 ") == 0){
      //      *flag = 1;
      flag = TRUE;
      break;
    }
  }

  return flag;
}


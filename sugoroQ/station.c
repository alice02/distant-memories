//-----------------------------------------------------------------------
//    �ե�����̾  ��  station_client.c
//    ����        ��  station�˴ؤ���⥸�塼��
//    �ܺ�        ��  ���δؿ���ƤӽФ����Ȥ�station�ν����
//                    ���֤μ������Ԥ��롥
//
//    ����        ��  2014/02/17    Shingo SEKIYA          ��������
//-----------------------------------------------------------------------


#include "sugoroQ.h"

/*
//test�ѤΥإå��ե�����
#include"station.h"
#include"test_print.h"
*/

//-----------------------------------------------------------------------
//  �ؿ�̾  ��  init_station_server
//  ����    ��  �����С�¦��station������ؿ�
//              �������۴ĥꥹ�ȤǤκ���
//  �����  ��  �ʤ�
//  ����    ��  struct board 
//        station����Ƭ���Ϥ�ޤॲ����ǡ���
//
//  ����    ��  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
void init_station_server(struct board *board){
  int i;
  char string[BUF_SIZE];
  struct station *p;
  FILE *fp;


  fp=fopen("station.txt","r");

  p=(struct station*)malloc(sizeof(struct station));
  //�ΰ�γ��ݤ��Ǥ��Ƥ��ʤ��ä��鶯����λ
  if(p==NULL)exit(1);

  board->s=p;
  p->next=p;
  p->prev=p;

  p->place_id=0;
  p->who_have=-1;
  fgets(string,BUF_SIZE,fp);
  convert_CSV(p,string);

  //�إꥹ�Ȥν�����ְʳ��������Ԥ��롼��
  for(i=1;i<MAP_SIZE;i++){
    p=insert_station(p);
    p->place_id=i;
    p->who_have=-1;
    fgets(string,BUF_SIZE,fp);
    convert_CSV(p,string);
  }
}


//-----------------------------------------------------------------------
//  �ؿ�̾  ��  init_station_client
//  ����    ��  ���饤�����¦��station������ؿ�
//              �������۴ĥꥹ�ȤǤκ���
//  �����  ��  �ʤ�
//  ����    ��  struct board*,char st_name[][],int value[]
//        station����Ƭ���Ϥ�ޤॲ����ǡ���
//        ���ؤ�̾��
//        ���ؤ�����
//  ����    ��  char st_name
//        ��̾������Ǽ����Ƥ�������
//
//  ����    ��  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
void init_station_client(struct board *board,char st_name[MAP_SIZE][BUF_SIZE], int value[MAP_SIZE], int have[MAP_SIZE]){
  int i;
  struct station *p;

  p=(struct station*)malloc(sizeof(struct station));
  //�ΰ�γ��ݤ��Ǥ��Ƥ��ʤ��ä��鶯����λ
  if(p==NULL)exit(1);

  board->s=p;
  p->next=p;
  p->prev=p;

  p->place_id=0;
  p->who_have=have[0];
  strcpy(p->place_name,st_name[0]);
  p->value = value[0];

  //�إꥹ�Ȥν�����ְʳ��������Ԥ��롼��
  for(i=1;i<MAP_SIZE;i++){
    p=insert_station(p);
    p->place_id=i;
    p->who_have=have[i];
    strcpy(p->place_name,st_name[i]);
    p->value = value[i];
  }
}


//-----------------------------------------------------------------------
//  �ؿ�̾  ��  free_station
//  ����    ��  station�γ�����Ԥ��ؿ�
//              
//  �����  ��  �ʤ�
//  ����    ��  struct board *board 
//        ������ǡ���
//
//  ����    ��  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
void free_station(struct board *board){
  int i;
  struct station *p,*tmp;

  p=board->s;
  board->s=NULL;
  //0~29���ܤαؤγ���
  for(i=0;i<MAP_SIZE-1;i++){
    tmp=p->next;
    free(p);
    p=tmp;
  }
  free(p);
}


//-----------------------------------------------------------------------
//  �ؿ�̾  ��  convert_CSV
//  ����    ��  station�ν�����Τ����csv������ʸ���󤫤��̾��
//              �ؤ����ʤ���롥
//  �����  ��  �ʤ�
//  ����    ��   struct station *dat,char string[256]
//        1�ĤαؤΥǡ����ؤΥݥ���
//        CSV�ե����뤫���ɤ߹�������ʬ��ʸ����
//
//  ����    ��  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
void convert_CSV(struct station *p,char string[BUF_SIZE]){
  int i;

  //CSV�ե����뤬"��̾(ʸ����),����(������)"�η��ˤʤäƤ���
  //','�ޤǤα�̾������
  for(i=0;string[i]!=',';i++){
    p->place_name[i]=string[i];
  }

  p->place_name[i]='\0';
  p->value=0;
  i++;

  //'\n'�ޤǤο��������ͤ��Ѵ���������
  for(;string[i]!='\n';i++){
    p->value*=10;
    p->value+=string[i]-'0';
  }
}


//-----------------------------------------------------------------------
//  �ؿ�̾  ��  insert_station
//  ����    ��  station���ɲä�Ԥ��ؿ�
//              
//  �����  ��  struct station*
//        ���������������ؤΥݥ���
//  ����    ��  struct station *p 
//        station���ɲä�������ļ����Υݥ���
//
//  ����    ��  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
struct station *insert_station(struct station *p){
  struct station *new;

  new=(struct station*)malloc(sizeof(struct station));
  //�ΰ�γ��ݤ��Ǥ��Ƥ��ʤ��ä��鶯����λ
  if(new==NULL)exit(1);

  new->next=p->next;
  new->prev=p;
  p->next=new;

  return new;
}


//-----------------------------------------------------------------------
//  �ؿ�̾  ��  s_access_station
//  ����    ��  station�֤ΰ�ư�ؿ�
//             �������Ϥ��줿�ݥ��󥿤ΰ��֤���n�Ŀʤ� 
//  �����  ��  struct station*
//        ��ư��αإݥ���
//  ����    ��  struct station *p,int n 
//        station�Υݥ��󥿤Ǥ���ľ����Ȥ򤤤���ʤ�����
//           board��αؤ���Ƭ����s������Ȥ��ư�����
//        �ʤޤ���ؤο�n
//
//  ����    ��  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
struct station *s_access_station(struct station *p,int n){
  int i;
  struct station *foo;

  foo=p;
  //�������󥷥�륢�������Ǥν���������������n>0������������������n<0�Ȥ��Ƥ���
  if(n>0){
    //n�������Ͳ�ʤ�
    for(i=0;i<n;i++)foo=foo->next;
  }else{
    //n�������Ͳ����
    for(i=0;i>n;i--)foo=foo->prev;
  }

  return foo;  
}


//-----------------------------------------------------------------------
//  �ؿ�̾  ��  r_access_station
//  ����    ��  station�֤ΰ�ư�ؿ�
//             id�ΰ��֤˰�ư���� 
//  �����  ��  struct station*
//        ��ư��αإݥ���
//  ����    ��  struct station *p,int id 
//        station�Υݥ��󥿤Ǥ���ľ����Ȥ򤤤���ʤ�����
//           board��αؤ���Ƭ����s������Ȥ��ư�����
//        �ʤޤ���ؤ�id
//
//  ����    ��  2014/02/17    Shingo SEKIYA
//-----------------------------------------------------------------------
struct station *r_access_station(struct station *p,int id){
  struct station *foo;

  foo=p;
  //���ꤷ��id���ΰ賰�Ǥ���н������ʤ�
  if(0<=id&&id<MAP_SIZE){
    //���ꤷ��id�����Ĥ���ޤǿʤ�
    while(foo->place_id!=id){
      foo=foo->next;
    }
  }
  return foo;
}

/*
//test�Ѥ�main�ؿ�
int main(void){
  struct board board;

  init_station_server(&board);
  print_station(board);
  free_station(&board);
  return 0;
}  
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

void opening(void);
int get_number(void);
int distinction(int);
int escape1(void);
int escape2(void);


int main(void)
{
  int score_1, score_2;

  srand((unsigned)time(NULL));

  opening();

  score_1 = escape1();

  if(score_1!=0){
    sleep(1);
    score_2 = escape2();
  }else{
    printf("\nGame Over!! �������λ���ޤ�...\n\n");
    sleep(1);
    return 0;
  }

  if(score_2!=0){
    printf("\x1b[7m"); //ȿž
    printf("all stage complete!!!\n\n");
    printf("\x1b[0m"); //°�����ꥢ
    sleep(1);
  }else{
    printf("\nGame Over!! �������λ���ޤ�...\n\n");
    sleep(1);
  }

  if(score_1!=0){
    printf("+----------------------------------+\n");
    printf("|  ��Escape 1�פΥ����� �� %5d   |\n", score_1);
  }
  if(score_2!=0){
    printf("|  ��Escape 2�פΥ����� �� %5d   |\n", score_2);
  }
  printf("+----------------------------------+\n\n");

  return 0;
}

void opening(void)
{
  printf("\n\n***********************************\n");
  printf("*                                 *\n");
  printf("*          Strange House          *\n");
  printf("*                                 *\n");
  printf("* �ٹ�:�����ο����ƥ�����Ǥ�(��) *\n");
  printf("*                                 *\n");
  printf("***********************************\n\n");

  printf("��|���|������������������������������������������\n"); 
  printf("�� ���������Ϥ�����̤Ǥϡ�                      ��\n");
  printf("�� �����ʳ������Ϥ��ʤ��Ǥ���������              ��\n");
  printf("�� ʸ���ʤɤ����Ϥ���ȡ�̵�¥롼�פ��ޤ���      ��\n");
  printf("�� �⤷��̵�¥롼�פ��Ƥ��ޤä����ϡ�          ��\n");
  printf("�� [Ctrl + c]�ǥץ���������λ���Ƥ�����������\n");
  printf("��������������������������������������������������\n\n"); 

  printf("Press Enter to Start Game!!\n");
  getc(stdin);
}

int get_number(void)
{
  int number;

  do{
    printf("������?:");
    scanf("%d", &number);
    
    if(number<0 || number>100){
      printf("input error!!\n");
    } 
  } while(number<0 || number>100);

  return number;
}

int distinction(int ans)
{
  int flag , input_ans;
  
  input_ans = get_number();
    
  if(input_ans==ans){
    flag = TRUE;
  }else if(input_ans<ans){
    printf("\x1b[4m"); //��������饤��
    printf("�ֹ�Ϥ�ä��礭���褦�ʵ��������\n");
    printf("\x1b[0m"); //°�����ꥢ
    flag = FALSE;
    printf("\n");
  }else if(input_ans>ans){
    printf("\x1b[4m"); //��������饤��
    printf("�ֹ�Ϥ�äȾ������褦�ʵ��������\n");
    printf("\x1b[0m"); //°�����ꥢ
    flag = FALSE;
    printf("\n");
  }  

  return flag;
}

int escape1(void)
{
  int ans, flag=FALSE, count=10, score=0;
  
  ans = rand() % 100;
  
  printf("\n##################\n");
  printf("#                #\n");
  printf("#    Escape 1    #\n");
  printf("#                #\n");
  printf("##################\n\n");

  usleep(500000);
  printf("��������������������������������������������������������������\n"); 
  printf("�ðռ���ۯ۰�Ȥ��Ƥ���...                                   ��\n");
  printf("�������ϰ��β���ʤΤ�����...                             ��\n");
  printf("���դ�򸫲󤷤Ƥ����ʤ�...                               ��\n");
  printf("��ͣ��,���Τ����ä��ɥ������������                         ��\n");
  printf("�÷���ͽ��������...                                         ��\n");
  printf("���ɤ����̩�����Ĥ�������Ƥ��ޤä��褦����              ��\n");
  printf("�ä��!!�ɥ��Ⱦ��η�֤˻椬����Ǥ���!                     �� \n");
  printf("�����λ�ˤ��ȡ����Υɥ��θ����ֹ��,0��99�Τɤ줫�餷������\n");
  printf("�ä����⡢10��ְ㤨��Ȱ��������ʤ��ʤäƤ��ޤ��褦��...   ��\n");
  printf("���ʤ�Ȥ��Ƥ⤳����������æ�Ф��ͤ�!!                      ��\n");
  printf("��������������������������������������������������������������\n\n"); 
  usleep(500000);
  
  printf("Enter�����򲡤���,������򳫻Ϥ��ޤ�.\n");
  getc(stdin);

  while(flag==FALSE && count>0){
    printf("�Ĥ�%d��\n", count);
    flag = distinction(ans);
    if(flag == FALSE){
      count--;
    }
  }

  score = count * (rand() % 300 + 150); //�������η׻�

  if(flag == TRUE){
    printf("\n�ĥ�����!! �ɥ���������!!  æ�Ф��뤳�Ȥ���������!!!\n\n");
    printf("******************\n");
    printf("*  score��%5d  *\n", score);
    printf("******************\n\n");
    sleep(1);
    printf("���Υ��ơ����˿ʤߤޤ�...\n");
  }else{
    printf("10��ְ㤨�Ƥ��ޤä���\n");
    printf("�⤦����������������Ф뤳�ȤϽ���ʤ��Τ�������\n");
    printf("�ܤ��������ðŤˤʤä�... [���ʤߤˡ�������%d�Ǥ���]\n", ans); 
 }

  return score;
}

int escape2(void)
{
  int ans, flag=FALSE, count=5, score=0;

  ans = rand() % 100;

  printf("\n##################\n");
  printf("#                #\n");
  printf("#    Escape 2    #\n");
  printf("#                #\n");
  printf("##################\n\n");

  usleep(500000);
  printf("����������������������������������������������������������\n"); 
  printf("�äʤ�Ȥ�������������æ�Ф��뤳�Ȥ���������...          ��\n");
  printf("���֤Ȥꤢ���������δ�̯�ʲȤ���Ф褦�ġ�               ��\n");
  printf("�ä����פäơ��Ȥꤢ�������ؤ�õ���Ƥߤ���               ��\n");
  printf("�������ơ��ʤ�Ȥ����ؤˤ��ɤ��夤���Τ���...            ��\n");
  printf("�äʤ�ȸ��ؤˤϻ������Ƥ����åȤ���Ƥ���!!!            ��\n");
  printf("���ɤ���餳�λ������Ƥ�������ˤϥѥ���ɤ�ɬ�פǡ� ��\n");
  printf("�ä��Υѥ���ɤ�0��99�Τ����Τɤ줫�Τ褦��...         �� \n");
  printf("����������5��ְ㤨�����ȯ��������ˤʤäƤ��롣        ��\n");
  printf("�û������Ƥ����Ǥ���ȡ����ؤθ��⾡��˳����ߤ���...  ��\n");
  printf("���ʤ�Ȥ��Ƥ⤳�δ�̯�ʲȤ���æ�Ф��ͤ�!!               ��\n");
  printf("����������������������������������������������������������\n\n"); 
  usleep(500000);
  
  printf("Enter�����򲡤���,������򳫻Ϥ��ޤ�.\n");
  getc(stdin);
  getc(stdin);

  while(flag==FALSE && count>0){

    printf("�Ĥ�%d��\n", count);

    flag = distinction(ans);

    if(flag == FALSE){
      count--;
    }
  }
  
  score = count * (rand() % 1000 + 850); //�������η׻�

  if(flag == TRUE){
    printf("\n����!! �ɤ���� �������Ƥβ�������������褦��!!!\n\n");
    printf("******************\n");
    printf("*  score��%5d  *\n", score);
    printf("******************\n\n");
  }else{
    printf("�֡�����������Фá�\n\n");
    sleep(1);
    printf("[������%d�Ǥ���]\n", ans);
  }
  return score;
}

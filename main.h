#ifndef _MAIN_
#define _MAIN_
#include<stdio.h>
#pragma comment(lib,"Winmm.lib")

#define HEIGHT 750 // ��Ϸ����ߴ� 
#define WIDTH 1126

#define S_LAG 700//���������ʱ����

#define SKILL_LAG 20000//����ʹ�õ���ȴʱ��
#define SKILL_TIME 3000//ʱͣʱ��

#define Awidth 70
#define Ahigh 68
#define Azidanwidth 20
#define Azidanhigh 20
typedef struct hero {
	bool life;//�Ƿ���
	int HP;//����ֵ
	int x;
	int y;
	int speed;
	int dongzuo;
	int dir;
	int shoot;
}HERO;

typedef struct button {
	int x1;
	int y1;
	int x2;
	int y2;
	int state;
}BUTTON;

typedef struct monster {
	int x;
	int y;
	int Health_point;//�Զ��׼�
	int type;//��������
}MONSTER;
struct node_monster {
	MONSTER inf;
	node_monster* next;
};

typedef struct bk {
	int x;
	int y;
}BK;

typedef struct zidanA {
	int x, y;
	int vx, vy;//�ٶ�
	int damage;
	int isExist;//�ӵ��Ƿ񻹴���
	zidanA* pnext;
}list;

typedef struct zhangai {
	int x1;
	int y1;
	int x2;
	int y2;
	zhangai* next;
}BARRIER;//���ϰ�������


//��ʼ��
void loadImg();
void gameDraw();
void gameInit();


//��ť��غ���
int InWhichBotton(int x, int y);
void DrawButton();
void DrawButtonState(int num);

//������غ���
void CreatAMonster(int x, int y, int type);
void DrawMonster(int herox, int heroy, int bkx, int bky, int bkpx, int bkpy);//Ҫ�ģ�������
void DrawMonster1(int bkx, int bky,int bkpx, int bkpy);//����ʱͣ�еĹ���

//������
void MouseControl(ExMessage m, int* num);//Ҫ�ģ�����

//�����ƶ�����ʾ
void bkDraw(int speed, int x, int y);

//HERO��غ���
void playerMove(int speed, int x, int y);
void listPushBack(list** pplist, list* newNode);
list* creatAzidan(int vx, int vy);
void listChangeXY(list** pplist);
void listRemoveNode(list** pplist);
void showAzidan();
void playerAshoot();
void playerAskill();
int IfHit(int m_x,int m_y,int type, int z_x,int z_y);//�ӵ��Ƿ���й���


//�ͷ�����
void FreeMonster(node_monster* head_m);
void FreeZiDan(list* head_m);

void ctrlFps(int start_time);
#endif 

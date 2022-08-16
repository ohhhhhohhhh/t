#ifndef _MAIN_
#define _MAIN_
#include<stdio.h>
#pragma comment(lib,"Winmm.lib")

#define HEIGHT 750 // 游戏画面尺寸 
#define WIDTH 1126

#define S_LAG 700//两次射击的时间间隔

#define SKILL_LAG 20000//技能使用的冷却时间
#define SKILL_TIME 3000//时停时间

#define Awidth 70
#define Ahigh 68
#define Azidanwidth 20
#define Azidanhigh 20
typedef struct hero {
	bool life;//是否存活
	int HP;//生命值
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
	int Health_point;//显而易见
	int type;//怪物类型
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
	int vx, vy;//速度
	int damage;
	int isExist;//子弹是否还存在
	zidanA* pnext;
}list;

typedef struct zhangai {
	int x1;
	int y1;
	int x2;
	int y2;
	zhangai* next;
}BARRIER;//有障碍的区域


//初始化
void loadImg();
void gameDraw();
void gameInit();


//按钮相关函数
int InWhichBotton(int x, int y);
void DrawButton();
void DrawButtonState(int num);

//怪兽相关函数
void CreatAMonster(int x, int y, int type);
void DrawMonster(int herox, int heroy, int bkx, int bky, int bkpx, int bkpy);//要改！！！！
void DrawMonster1(int bkx, int bky,int bkpx, int bkpy);//画出时停中的怪物

//鼠标控制
void MouseControl(ExMessage m, int* num);//要改！！！

//背景移动及显示
void bkDraw(int speed, int x, int y);

//HERO相关函数
void playerMove(int speed, int x, int y);
void listPushBack(list** pplist, list* newNode);
list* creatAzidan(int vx, int vy);
void listChangeXY(list** pplist);
void listRemoveNode(list** pplist);
void showAzidan();
void playerAshoot();
void playerAskill();
int IfHit(int m_x,int m_y,int type, int z_x,int z_y);//子弹是否打中怪兽


//释放链表
void FreeMonster(node_monster* head_m);
void FreeZiDan(list* head_m);

void ctrlFps(int start_time);
#endif 

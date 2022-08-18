#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include<time.h>
#include"main.h"

struct node_monster* head_m;//怪兽链表的头指针
BK bk;
HERO hero;
list* zidanA_list = NULL;//子弹链表的头指针
BARRIER* blist = NULL;
int bkpx, bkpy;//上一时刻背景的坐标
int vx, vy;//子弹速度

int main()
{
	// 创建绘图窗口
	initgraph(WIDTH, HEIGHT);
	gameInit();

	int num = 0;
	ExMessage m;
	clock_t start_time;


	BeginBatchDraw();
	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE)) {
			system("Pause");
		}
		cleardevice();
		start_time = clock();
		peekmessage(&m, EM_MOUSE | EM_KEY);//获取鼠标信息
		MouseControl(m, &num);//GOD的鼠标控制按钮函数
		bkpx = bk.x, bkpy = bk.y;//记录下上一时刻的背景坐标

		playerMove(hero.speed, hero.x, hero.y);
		bkDraw(hero.speed, hero.x, hero.y);
		playerAshoot();
		gameDraw();//输出背景图和角色图片
		DrawButton();
		DrawButtonState(num);
		DrawMonster(hero.x, hero.y, bk.x, bk.y, bkpx, bkpy);//画怪兽，就是一个圈，有图片了再改
		showAzidan();
		ctrlFps(start_time);
		FlushBatchDraw();
		playerAskill();
	}
	EndBatchDraw();

	//释放链表内存
	FreeMonster(head_m);
	FreeZiDan(zidanA_list);

	return 0;
}
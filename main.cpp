#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include<time.h>
#include"main.h"

struct node_monster* head_m;//���������ͷָ��
BK bk;
HERO hero;
list* zidanA_list = NULL;//�ӵ������ͷָ��
BARRIER* blist = NULL;
int bkpx, bkpy;//��һʱ�̱���������
int vx, vy;//�ӵ��ٶ�

int main()
{
	// ������ͼ����
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
		peekmessage(&m, EM_MOUSE | EM_KEY);//��ȡ�����Ϣ
		MouseControl(m, &num);//GOD�������ư�ť����
		bkpx = bk.x, bkpy = bk.y;//��¼����һʱ�̵ı�������

		playerMove(hero.speed, hero.x, hero.y);
		bkDraw(hero.speed, hero.x, hero.y);
		playerAshoot();
		gameDraw();//�������ͼ�ͽ�ɫͼƬ
		DrawButton();
		DrawButtonState(num);
		DrawMonster(hero.x, hero.y, bk.x, bk.y, bkpx, bkpy);//�����ޣ�����һ��Ȧ����ͼƬ���ٸ�
		showAzidan();
		ctrlFps(start_time);
		FlushBatchDraw();
		playerAskill();
	}
	EndBatchDraw();

	//�ͷ������ڴ�
	FreeMonster(head_m);
	FreeZiDan(zidanA_list);

	return 0;
}
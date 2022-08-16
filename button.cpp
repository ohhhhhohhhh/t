#include <graphics.h>
#include <conio.h>
#include<windows.h>
#include<time.h>
#include<math.h>
#include"main.h"
extern struct node_monster* head_m;
extern BK bk;
extern HERO hero;
extern list* zidanA_list;

//判断⿏标点击在哪个按钮
int InWhichBotton(int x, int y)
{
	int a = 0;
	if (x < 1120 && x > 1060 && y < 98 && y > 50)
		a = 1;
	if (x < 1120 && x > 1060 && y < 148 && y > 100)
		a = 2;
	if (x < 1120 && x > 1060 && y < 198 && y > 150)
		a = 3;
	if (x < 1120 && x > 1060 && y < 248 && y > 200)
		a = 4;
	if (x < 1120 && x > 1060 && y < 298 && y > 250)
		a = 5;
	if (x < 1120 && x > 1060 && y < 348 && y > 300)
		a = 6;
	if (x < 1120 && x > 1060 && y < 398 && y > 350)
		a = 7;
	if (x < 1120 && x > 1060 && y < 448 && y > 400)
		a = 8;
	if (x < 1120 && x > 1060 && y < 498 && y > 450)
		a = 9;
	if (x < 1120 && x > 1060 && y < 548 && y > 500)
		a = 10;
	if (x < 1120 && x > 1060 && y < 598 && y > 550)
		a = 11;
	if (x < 1120 && x > 1060 && y < 648 && y > 600)
		a = 12;
	return a;
}

//画按钮
void DrawButton() {
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
	setlinecolor(RGB(0, 150, 200));
	roundrect(1060, 50, 1120, 98, 12, 12);
	outtextxy(1080, 68, _T("M1"));
	roundrect(1060, 100, 1120, 148, 12, 12);
	outtextxy(1080, 118, _T("M2"));
	roundrect(1060, 150, 1120, 198, 12, 12);
	outtextxy(1080, 168, _T("M3"));
	roundrect(1060, 200, 1120, 248, 12, 12);
	outtextxy(1085, 218, _T("Z"));
	roundrect(1060, 250, 1120, 298, 12, 12);
	roundrect(1060, 300, 1120, 348, 12, 12);
	roundrect(1060, 350, 1120, 398, 12, 12);
	roundrect(1060, 400, 1120, 448, 12, 12);
	roundrect(1060, 450, 1120, 498, 12, 12);
	roundrect(1060, 500, 1120, 548, 12, 12);
	roundrect(1060, 550, 1120, 598, 12, 12);
	roundrect(1060, 600, 1120, 648, 12, 12);
}

//画出按钮被按下的状态
void DrawButtonState(int num) {
	setfillcolor(WHITE);
	if (num == 1)
		fillroundrect(1060, 50, 1120, 98, 12, 12);
	if (num == 2)
		fillroundrect(1060, 100, 1120, 148, 12, 12);
	if (num == 3)
		fillroundrect(1060, 150, 1120, 198, 12, 12);
	if (num == 4)
		fillroundrect(1060, 200, 1120, 248, 12, 12);
	if (num == 5)
		fillroundrect(1060, 250, 1120, 298, 12, 12);
	if (num == 6)
		fillroundrect(1060, 300, 1120, 348, 12, 12);
	if (num == 7)
		fillroundrect(1060, 350, 1120, 398, 12, 12);
	if (num == 8)
		fillroundrect(1060, 400, 1120, 448, 12, 12);
	if (num == 9)
		fillroundrect(1060, 450, 1120, 498, 12, 12);
	if (num == 10)
		fillroundrect(1060, 500, 1120, 548, 12, 12);
	if (num == 11)
		fillroundrect(1060, 550, 1120, 598, 12, 12);
	if (num == 12)
		fillroundrect(1060, 600, 1120, 648, 12, 12);
}
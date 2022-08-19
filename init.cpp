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
extern int vx, vy;//子弹速度

IMAGE img_zidanA;
IMAGE img_hero1;
IMAGE img_hero2;
IMAGE img_move1[5];
IMAGE img_move2[5];
IMAGE img_book[5];
IMAGE img_book2[5];
IMAGE img_monster;
IMAGE img_bk;
IMAGE temp_bk;
//图⽚加载程序
void loadImg()
{
	//加载背景图
	loadimage(&img_bk, _T("res/bk.png"));
	loadimage(&temp_bk, _T("res/bk.png"));
	//人物朝右的图
	loadimage(&img_hero1, _T("res/hero2.png"));
	//人物朝左的图
	loadimage(&img_hero2, _T("res/hero1.png"));
	//怪物
	loadimage(&img_monster, _T("res/怪物/月亮111.png"));
	//子弹的图
	loadimage(&img_zidanA, _T("res/子弹.png"));
	//主角移动的图
	loadimage(&img_move1[0], _T("res/跑步/跑步1.png"));
	loadimage(&img_move1[1], _T("res/跑步/跑步2.png"));
	loadimage(&img_move1[2], _T("res/跑步/跑步3.png"));
	loadimage(&img_move1[3], _T("res/跑步/跑步4.png"));
	loadimage(&img_move1[4], _T("res/跑步/跑步5.png"));
	loadimage(&img_move2[0], _T("res/跑步/跑步1l.png"));
	loadimage(&img_move2[1], _T("res/跑步/跑步2l.png"));
	loadimage(&img_move2[2], _T("res/跑步/跑步3l.png"));
	loadimage(&img_move2[3], _T("res/跑步/跑步4l.png"));
	loadimage(&img_move2[4], _T("res/跑步/跑步5l.png"));
	//书的图片
	loadimage(&img_book[0], _T("res/书/书1.png"));//*************************
	loadimage(&img_book[1], _T("res/书/书2.png"));
	loadimage(&img_book[2], _T("res/书/书3.png"));
	loadimage(&img_book[3], _T("res/书/书4.png"));
	loadimage(&img_book[4], _T("res/书/书5.png"));
	loadimage(&img_book2[0], _T("res/书/书1l.png"));
	loadimage(&img_book2[1], _T("res/书/书2l.png"));
	loadimage(&img_book2[2], _T("res/书/书3l.png"));
	loadimage(&img_book2[3], _T("res/书/书4l.png"));
	loadimage(&img_book2[4], _T("res/书/书5l.png"));
}

//初始化数据
void gameInit() {
	loadImg();
	hero.x = WIDTH / 2;
	hero.y = HEIGHT / 2;
	hero.life = true;
	hero.HP = 5;
	hero.speed = 6;
	hero.dir = 2;
	hero.shoot = 0;
	bk.x = 0;
	bk.y = 0;
}

//游戏绘制函数
void gameDraw()
{
	//输出背景图⽚到指定位置
	putimage(bk.x, bk.y, &temp_bk);
	drawAlpha1(&temp_bk, 0, 0, &img_bk);
	static int count_move;
	static int count_shoot;
	//输出怪物
	struct node_monster* p;
	p = head_m;
	while (p) {
		if (p->inf.type == 1) {
			drawAlpha(&temp_bk, p->inf.x - 50 - bk.x, p->inf.y - 100 - bk.y, &img_monster);
		}
		if (p->inf.type == 2) {
		}
		if (p->inf.type == 3) {
		}
		if (p->inf.type == 4) {
		}
		p = p->next;
	}
	//输出⻆⾊A图⽚
	if (hero.dir == 2 && hero.dongzuo == 0) {
		count_move = 0;
		drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 42 - bk.y, &img_hero1);
	}
	if (hero.dir == 1 && hero.dongzuo == 0) {
		count_move = 0;
		drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 42 - bk.y, &img_hero2);
	}
	
	//移动时的动画
	if (hero.dongzuo == 1  && hero.dir == 2) {
		if (count_move <= 11) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move1[0]);
		}
		else if (count_move <= 22) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move1[1]);
		}
		else if (count_move <= 33) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move1[2]);
		}
		else if (count_move <= 44) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move1[3]);
			count_move = 0;
		}
		else if (count_move <= 55) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move1[4]);
			count_move = 0;
		}
		count_move++;
	}
	if (hero.dongzuo == 1 && hero.dir == 1) {
		if (count_move <= 11) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move2[0]);
		}
		else if (count_move <= 22) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move2[1]);
		}
		else if (count_move <= 33) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move2[2]);
		}
		else if (count_move <= 44) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move2[3]);
			count_move = 0;
		}
		else if (count_move <= 55) {
			drawAlpha(&temp_bk, hero.x - 40 - bk.x, hero.y - 40 - bk.y, &img_move2[4]);
			count_move = 0;
		}
		count_move++;
	}
	//书的动画
	if (hero.dir == 1 && hero.shoot == 0) {
		drawAlpha(&temp_bk, hero.x - 9 - bk.x, hero.y + 4 - bk.y, &img_book2[0]);
	}
	if (hero.dir == 2 && hero.shoot == 0) {
		drawAlpha(&temp_bk, hero.x - 18 - bk.x, hero.y + 4 - bk.y, &img_book[0]);
	}
	//施法动作
	if (hero.dir == 1 && hero.shoot == 1) {
		if (count_shoot <= 5) {
			drawAlpha(&temp_bk, hero.x - 11 - bk.x, hero.y + 4 - bk.y, &img_book2[0]);
		}
		else if (count_shoot <= 11) {
			drawAlpha(&temp_bk, hero.x - 11 - bk.x, hero.y + 4 - bk.y, &img_book2[1]);
		}
		else if (count_shoot <= 17) {
			drawAlpha(&temp_bk, hero.x - 11 - bk.x, hero.y + 4 - bk.y, &img_book2[2]);
		}
		else if (count_shoot <= 24) {
			drawAlpha(&temp_bk, hero.x - 11 - bk.x, hero.y + 4 - bk.y, &img_book2[3]);
		}
		else if (count_shoot < 30) {
			drawAlpha(&temp_bk, hero.x - 11 - bk.x, hero.y + 4 - bk.y, &img_book2[4]);
		}
		else if (count_shoot == 30) {
			drawAlpha(&temp_bk, hero.x - 11 - bk.x, hero.y + 4 - bk.y, &img_book2[4]);
			listPushBack(&zidanA_list, creatAzidan(vx, vy));
		}
		else if (count_shoot <= 34) {
			drawAlpha(&temp_bk, hero.x - 11 - bk.x, hero.y + 4 - bk.y, &img_book2[2]);
		}
		if (count_shoot == 34) {
			hero.shoot = 0;
			count_shoot = 0;
		}
		count_shoot++;
	}
	if (hero.dir == 2 && hero.shoot == 1) {
		if (count_shoot <= 5) {
			drawAlpha(&temp_bk, hero.x - 16 - bk.x, hero.y + 4 - bk.y, &img_book[0]);
		}
	    else if (count_shoot <=11) {
			drawAlpha(&temp_bk, hero.x - 16 - bk.x, hero.y + 4 - bk.y, &img_book[1]);
		}
		else if (count_shoot <= 17) {
			drawAlpha(&temp_bk, hero.x - 16 - bk.x, hero.y + 4 - bk.y, &img_book[2]);
		}
		else if (count_shoot <= 24) {
			drawAlpha(&temp_bk, hero.x - 16 - bk.x, hero.y + 4 - bk.y, &img_book[3]);
		}
		else if (count_shoot < 30) {
			drawAlpha(&temp_bk, hero.x - 16 - bk.x, hero.y + 4 - bk.y, &img_book[4]);
		}
		else if (count_shoot == 30) {
			drawAlpha(&temp_bk, hero.x - 16 - bk.x, hero.y + 4 - bk.y, &img_book[4]);
			listPushBack(&zidanA_list, creatAzidan(vx, vy));
		}
		else if (count_shoot <= 34) {
			drawAlpha(&temp_bk, hero.x - 16 - bk.x, hero.y + 4 - bk.y, &img_book[2]);
		}
		if (count_shoot == 34) {
			hero.shoot = 0;
			count_shoot = 0;
		}
		count_shoot++;
	}
	//输出子弹
	for (list* cur = zidanA_list; cur != NULL; cur = cur->pnext) {
		if (cur->isExist) {
			drawAlpha(&temp_bk, cur->x - bk.x, cur->y - bk.y, &img_zidanA);
		}
	}
	
}
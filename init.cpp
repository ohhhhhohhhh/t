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

extern IMAGE img_zidanA[2];
IMAGE img_hero1[2];
IMAGE img_hero2[2];
IMAGE img_move1[5];
IMAGE img_move11[5];
IMAGE img_move2[5];
IMAGE img_move21[5];
IMAGE img_book[5];
IMAGE img_book1[5];
IMAGE img_book2[5];
IMAGE img_book21[5];
IMAGE img_monster[2];
IMAGE img_bk;
//图⽚加载程序
void loadImg()
{
	//加载背景图
	loadimage(&img_bk, _T("res/bk.jpg"));
	//人物朝右的图
	loadimage(&img_hero1[0], _T("res/hero21.jpg"));
	loadimage(&img_hero1[1], _T("res/hero2.jpg"));
	//人物朝左的图
	loadimage(&img_hero2[0], _T("res/hero11.jpg"));
	loadimage(&img_hero2[1], _T("res/hero1.jpg"));
	//怪物
	loadimage(&img_monster[0], _T("res/怪物/月亮1.jpg"));
	loadimage(&img_monster[1], _T("res/怪物/月亮11.jpg"));
	//子弹的图
	loadimage(&img_zidanA[0], _T("res/子弹1.jpg"));
	loadimage(&img_zidanA[1], _T("res/子弹.jpg"));
	//主角移动的图
	loadimage(&img_move1[0], _T("res/跑步/跑步1.jpg"));
	loadimage(&img_move11[0], _T("res/跑步/跑步11.jpg"));
	loadimage(&img_move1[1], _T("res/跑步/跑步2.jpg"));
	loadimage(&img_move11[1], _T("res/跑步/跑步21.jpg"));
	loadimage(&img_move1[2], _T("res/跑步/跑步3.jpg"));
	loadimage(&img_move11[2], _T("res/跑步/跑步31.jpg"));
	loadimage(&img_move1[3], _T("res/跑步/跑步4.jpg"));
	loadimage(&img_move11[3], _T("res/跑步/跑步41.jpg"));
	loadimage(&img_move1[4], _T("res/跑步/跑步5.jpg"));
	loadimage(&img_move11[4], _T("res/跑步/跑步51.jpg"));
	loadimage(&img_move2[0], _T("res/跑步/跑步1l.jpg"));
	loadimage(&img_move21[0], _T("res/跑步/跑步11l.jpg"));
	loadimage(&img_move2[1], _T("res/跑步/跑步2l.jpg"));
	loadimage(&img_move21[1], _T("res/跑步/跑步21l.jpg"));
	loadimage(&img_move2[2], _T("res/跑步/跑步3l.jpg"));
	loadimage(&img_move21[2], _T("res/跑步/跑步31l.jpg"));
	loadimage(&img_move2[3], _T("res/跑步/跑步4l.jpg"));
	loadimage(&img_move21[3], _T("res/跑步/跑步41l.jpg"));
	loadimage(&img_move2[4], _T("res/跑步/跑步5l.jpg"));
	loadimage(&img_move21[4], _T("res/跑步/跑步51l.jpg"));
	//书的图片
	loadimage(&img_book[0], _T("res/书/书1.jpg"));
	loadimage(&img_book1[0], _T("res/书/书11.jpg"));
	loadimage(&img_book[1], _T("res/书/书2.jpg"));
	loadimage(&img_book1[1], _T("res/书/书21.jpg"));
	loadimage(&img_book[2], _T("res/书/书3.jpg"));
	loadimage(&img_book1[2], _T("res/书/书31.jpg"));
	loadimage(&img_book[3], _T("res/书/书4.jpg"));
	loadimage(&img_book1[3], _T("res/书/书41.jpg"));
	loadimage(&img_book[4], _T("res/书/书5.jpg"));
	loadimage(&img_book1[4], _T("res/书/书51.jpg"));
	loadimage(&img_book2[0], _T("res/书/书1l.jpg"));
	loadimage(&img_book21[0], _T("res/书/书11l.jpg"));
	loadimage(&img_book2[1], _T("res/书/书2l.jpg"));
	loadimage(&img_book21[1], _T("res/书/书21l.jpg"));
	loadimage(&img_book2[2], _T("res/书/书3l.jpg"));
	loadimage(&img_book21[2], _T("res/书/书31l.jpg"));
	loadimage(&img_book2[3], _T("res/书/书4l.jpg"));
	loadimage(&img_book21[3], _T("res/书/书41l.jpg"));
	loadimage(&img_book2[4], _T("res/书/书5l.jpg"));
	loadimage(&img_book21[4], _T("res/书/书51l.jpg"));
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
	putimage(bk.x, bk.y, &img_bk);
	static int count_move;
	static int count_shoot;
	//输出⻆⾊A图⽚
	if (hero.dir == 2 && hero.dongzuo == 0) {
		count_move = 0;
		putimage(hero.x - 40, hero.y - 42, &img_hero1[0], NOTSRCERASE);
		putimage(hero.x - 40, hero.y - 42, &img_hero1[1], SRCINVERT);
	}
	if (hero.dir == 1 && hero.dongzuo == 0) {
		count_move = 0;
		putimage(hero.x - 40, hero.y - 42, &img_hero2[0], NOTSRCERASE);
		putimage(hero.x - 40, hero.y - 42, &img_hero2[1], SRCINVERT);
	}
	//移动时的动画
	if (hero.dongzuo == 1  && hero.dir == 2) {
		if (count_move <= 11) {
			putimage(hero.x - 40, hero.y - 40, &img_move11[0], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move1[0], SRCINVERT);
		}
		else if (count_move <= 22) {
			putimage(hero.x - 40, hero.y - 40, &img_move11[1], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move1[1], SRCINVERT);
		}
		else if (count_move <= 33) {
			putimage(hero.x - 40, hero.y - 40, &img_move11[2], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move1[2], SRCINVERT);
		}
		else if (count_move <= 44) {
			putimage(hero.x - 40, hero.y - 40, &img_move11[3], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move1[3], SRCINVERT);
			count_move = 0;
		}
		else if (count_move <= 55) {
			putimage(hero.x - 40, hero.y - 40, &img_move11[4], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move1[4], SRCINVERT);
			count_move = 0;
		}
		count_move++;
	}
	if (hero.dongzuo == 1 && hero.dir == 1) {
		if (count_move <= 11) {
			putimage(hero.x - 40, hero.y - 40, &img_move21[0], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move2[0], SRCINVERT);
		}
		else if (count_move <= 22) {
			putimage(hero.x - 40, hero.y - 40, &img_move21[1], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move2[1], SRCINVERT);
		}
		else if (count_move <= 33) {
			putimage(hero.x - 40, hero.y - 40, &img_move21[2], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move2[2], SRCINVERT);
		}
		else if (count_move <= 44) {
			putimage(hero.x - 40, hero.y - 40, &img_move21[3], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move2[3], SRCINVERT);
			count_move = 0;
		}
		else if (count_move <= 55) {
			putimage(hero.x - 40, hero.y - 40, &img_move21[4], NOTSRCERASE);
			putimage(hero.x - 40, hero.y - 40, &img_move2[4], SRCINVERT);
			count_move = 0;
		}
		count_move++;
	}
	//书的动画
	if (hero.dir == 1 && hero.shoot == 0) {
		putimage(hero.x - 11, hero.y + 4, &img_book21[0], NOTSRCERASE);
		putimage(hero.x - 11, hero.y + 4, &img_book2[0], SRCINVERT);
	}
	if (hero.dir == 2 && hero.shoot == 0) {
		putimage(hero.x - 15, hero.y + 4, &img_book1[0], NOTSRCERASE);
		putimage(hero.x - 15, hero.y + 4, &img_book[0], SRCINVERT);
	}
	//施法动作
	if (hero.dir == 1 && hero.shoot == 1) {
		if (count_shoot <= 5) {
			putimage(hero.x - 11, hero.y + 4, &img_book21[0], NOTSRCERASE);
			putimage(hero.x - 11, hero.y + 4, &img_book2[0], SRCINVERT);
		}
		else if (count_shoot <= 11) {
			putimage(hero.x - 11, hero.y + 4, &img_book21[1], NOTSRCERASE);
			putimage(hero.x - 11, hero.y + 4, &img_book2[1], SRCINVERT);
		}
		else if (count_shoot <= 17) {
			putimage(hero.x - 11, hero.y + 4, &img_book21[2], NOTSRCERASE);
			putimage(hero.x - 11, hero.y + 4, &img_book2[2], SRCINVERT);
		}
		else if (count_shoot <= 24) {
			putimage(hero.x - 11, hero.y + 4, &img_book21[3], NOTSRCERASE);
			putimage(hero.x - 11, hero.y + 4, &img_book2[3], SRCINVERT);
		}
		else if (count_shoot < 30) {
			putimage(hero.x - 11, hero.y + 4, &img_book21[4], NOTSRCERASE);
			putimage(hero.x - 11, hero.y + 4, &img_book2[4], SRCINVERT);
		}
		else if (count_shoot == 30) {
			putimage(hero.x - 11, hero.y + 4, &img_book21[4], NOTSRCERASE);
			putimage(hero.x - 11, hero.y + 4, &img_book2[4], SRCINVERT);
			listPushBack(&zidanA_list, creatAzidan(vx, vy));
		}
		else if (count_shoot <= 34) {
			putimage(hero.x - 11, hero.y + 4, &img_book21[2], NOTSRCERASE);
			putimage(hero.x - 11, hero.y + 4, &img_book2[2], SRCINVERT);
		}
		if (count_shoot == 34) {
			hero.shoot = 0;
			count_shoot = 0;
		}
		count_shoot++;
	}
	if (hero.dir == 2 && hero.shoot == 1) {
		if (count_shoot <= 5) {
			putimage(hero.x - 15, hero.y + 4, &img_book1[0], NOTSRCERASE);
			putimage(hero.x - 15, hero.y + 4, &img_book[0], SRCINVERT);
		}
	    else if (count_shoot <=11) {
			putimage(hero.x - 15, hero.y + 4, &img_book1[1], NOTSRCERASE);
			putimage(hero.x - 15, hero.y + 4, &img_book[1], SRCINVERT);
		}
		else if (count_shoot <= 17) {
			putimage(hero.x - 15, hero.y + 4, &img_book1[2], NOTSRCERASE);
			putimage(hero.x - 15, hero.y + 4, &img_book[2], SRCINVERT);
		}
		else if (count_shoot <= 24) {
			putimage(hero.x - 15, hero.y + 4, &img_book1[3], NOTSRCERASE);
			putimage(hero.x - 15, hero.y + 4, &img_book[3], SRCINVERT);
		}
		else if (count_shoot < 30) {
			putimage(hero.x - 15, hero.y + 4, &img_book1[4], NOTSRCERASE);
			putimage(hero.x - 15, hero.y + 4, &img_book[4], SRCINVERT);
		}
		else if (count_shoot == 30) {
			putimage(hero.x - 15, hero.y + 4, &img_book1[4], NOTSRCERASE);
			putimage(hero.x - 15, hero.y + 4, &img_book[4], SRCINVERT);
			listPushBack(&zidanA_list, creatAzidan(vx, vy));
		}
		else if (count_shoot <= 34) {
			putimage(hero.x - 15, hero.y + 4, &img_book1[2], NOTSRCERASE);
			putimage(hero.x - 15, hero.y + 4, &img_book[2], SRCINVERT);
		}
		if (count_shoot == 34) {
			hero.shoot = 0;
			count_shoot = 0;
		}
		count_shoot++;
	}

	
}
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
extern IMAGE img_monster;
extern IMAGE temp_bk;
extern int vx, vy;
extern int bkpx, bkpy;


//创造⼀个怪兽倒序链表
void CreatAMonster(int x, int y, int type) {
	struct node_monster* p;
	if ((p = (struct node_monster*)malloc(sizeof(struct node_monster))) ==
		NULL) {
		printf("内存分配失败");
		exit(1);
	}
	else {
		p->inf.x = x;
		p->inf.y = y;
		p->inf.type = type;
		//各种怪物的生命值
		switch (type) {
		    case 1:p->inf.Health_point = 1;
				break;
			case 2://p->inf.Health_point = 1;
				break;
			default:
				break;
		}
		if (head_m == NULL) {
			p->next = NULL;
			head_m = p;
		}
		else {
			p->next = head_m;
			head_m = p;
		}
	}
}

//遍历怪兽链表并画出并改变其状态，这个函数还需要改
void DrawMonster(int herox, int heroy, int bkx, int bky, int bkpx, int bkpy) {
	if (head_m == NULL) {
		;
	}
	else {
		struct node_monster* p;
		p = head_m;
		static int start;
		while (p) {
			if (p->inf.type == 1) {
				if (p->inf.Health_point != 0) {
					start = -1;
					double tsin;
					double tcos;
					int herox1 = herox - bkpx;
					int heroy1 = heroy - bkpy;
					int px = p->inf.x - bkpx;
					int py = p->inf.y - bkpy;
					double t = sqrt((px - herox1) * (px - herox1) + (py - heroy1) * (py - heroy1));
					if (t != 0) {
						tsin = (px - herox1) / t;
						tcos = (py - heroy1) / t;
						px -= (int)(tsin * 5);
						py -= (int)(tcos * 5);
					}
					p->inf.x = px + bkx;
					p->inf.y = py + bky;
					//putimage(p->inf.x - 100, p->inf.y - 100, &img_monster[0], NOTSRCERASE);
					//putimage(p->inf.x - 100, p->inf.y - 100, &img_monster[1], SRCINVERT);
					drawAlpha(&temp_bk, p->inf.x - 50 - bk.x, p->inf.y - 100 - bk.y, &img_monster);
				}

				if (p->inf.Health_point == 0) {
					if (start == -1) {
						start = clock();
					}
					if (clock() - start >= 3000) {
						p->inf.Health_point = 1;
					}
					p->inf.x = p->inf.x - bkpx + bkx;
					p->inf.y = p->inf.y - bkpy + bky;
					//putimage(p->inf.x - 100, p->inf.y - 100, &img_monster[0], NOTSRCERASE);
					//putimage(p->inf.x - 100, p->inf.y - 100, &img_monster[1], SRCINVERT);
					drawAlpha(&temp_bk, p->inf.x - 50 - bk.x, p->inf.y - 100 - bk.y, &img_monster);
				}
			}
			if (p->inf.type == 2) {
			}
			if (p->inf.type == 3) {
			}
			if (p->inf.type == 4) {
				p->inf.x = p->inf.x - bkpx + bkx;
				p->inf.y = p->inf.y - bkpy + bky;
				setfillcolor(WHITE);
				fillrectangle(p->inf.x - 20, p->inf.y - 20, p->inf.x + 20, p->inf.y + 20);
			}
			p = p->next;
		}
	}
}

//遍历怪兽链表并画出(时停中)，这个函数还需要改
void DrawMonster1(int bkx, int bky, int bkpx, int bkpy) {
	if (head_m == NULL) {
		;
	}
	else {

		struct node_monster* p;
		p = head_m;
		while (p) {
			if (p->inf.type == 1) {
				setfillcolor(BLACK);
				p->inf.x = p->inf.x - bkpx + bkx;
				p->inf.y = p->inf.y - bkpy + bky;
				//putimage(p->inf.x - 100, p->inf.y - 100, &img_monster[0], NOTSRCERASE);
				//putimage(p->inf.x - 100, p->inf.y - 100, &img_monster[1], SRCINVERT);
				drawAlpha(&temp_bk, p->inf.x - 50 - bk.x, p->inf.y - 100 - bk.y, &img_monster);
			}
			if (p->inf.type == 4) {
				p->inf.x = p->inf.x - bkpx + bkx;
				p->inf.y = p->inf.y - bkpy + bky;
				setfillcolor(WHITE);
				fillrectangle(p->inf.x - 20, p->inf.y - 20, p->inf.x + 20, p->inf.y + 20);
			}
			p = p->next;
		}
	}
}

void FreeMonster(node_monster* head_m) {
	node_monster* p;
	if (head_m == NULL)
		return;
	else {
		while (head_m) {
			p = head_m;
			head_m = head_m->next;
			free(p);
		}
	}
}

void FreeZiDan(list* head_m) {
	list* p;
	if (head_m == NULL)
		return;
	else {
		while (head_m) {
			p = head_m;
			head_m = head_m->pnext;
			free(p);
		}
	}
}


//⿏标控制，这个函数也还要改
void MouseControl(ExMessage m, int* num) {
	static int flag = 0;
	switch (m.message) {
	case WM_MOUSEMOVE:
		if (*num)
			solidcircle(m.x, m.y, 20);
		break;
	case WM_LBUTTONDOWN:
		*num = InWhichBotton(m.x, m.y);
		if (*num <= 12 && *num != 0) {
			flag = 1;
			solidcircle(m.x, m.y, 20);
		}
		break;
	case WM_LBUTTONUP:
		if (InWhichBotton(m.x, m.y) == 0 && *num <= 12 && flag) {
			CreatAMonster(m.x, m.y, *num);
		}
		flag = 0;
		*num = 0;
		break;
	}
}

//背景移动
void bkDraw(int speed, int x, int y) {
	if (GetAsyncKeyState(87) && y <= 370)
	{
		bk.y += speed;
		hero.dongzuo = 1;
	}
	if (GetAsyncKeyState(83) && y >= 380)
	{
		bk.y -= speed;
		hero.dongzuo = 1;
	}
	if (GetAsyncKeyState(65) && x <= 556)
	{
		bk.x += speed;
		hero.dir = 1;
		hero.dongzuo = 1;
	}
	if (GetAsyncKeyState(68) && x >= 570)
	{
		bk.x -= speed;
		hero.dir = 2;
		hero.dongzuo = 1;
	}
}

//HERO移动
void playerMove(int speed, int x, int y)
{
	hero.dongzuo = 0;
	if (GetAsyncKeyState(87) && y > 370)//W
	{
		hero.y -= speed;
		hero.dongzuo = 1;
	}
	if (GetAsyncKeyState(83) && y < 380)//S
	{
		hero.y += speed;
		hero.dongzuo = 1;
	}
	if (GetAsyncKeyState(65) && x > 556)//A
	{
		hero.dir = 1;
		hero.x -= speed;
		hero.dongzuo = 1;
	}
	if (GetAsyncKeyState(68) && x < 570)//D
	{
		hero.dir = 2;
		hero.x += speed;
		hero.dongzuo = 1;
	}
}

void listPushBack(list** pplist, list* newNode)
{
	if (*pplist == NULL)//如果链表为空，那么新增节点就是第⼀个
	{
		*pplist = newNode;
		return;
	}
	list* cur = *pplist;
	while (cur->pnext != NULL)//找到最后⼀个节点
	{
		cur = cur->pnext;
	}
	cur->pnext = newNode;//插⼊新的节点
}

list* creatAzidan(int vx, int vy) {
	list* p = (list*)malloc(sizeof(list));
	p->x = hero.x - Azidanwidth / 2;
	p->y = hero.y - Azidanhigh / 2;
	p->vx = vx;
	p->vy = vy;
	p->isExist = 1;
	p->pnext = NULL;
	return p;
}

//⼦弹移动
void listChangeXY(list** pplist) {
	if (*pplist == NULL)
		return;
	list* cur = *pplist;
	while (cur != NULL)
	{
		cur->x += cur->vx - bkpx + bk.x;
		cur->y += cur->vy - bkpy + bk.y;
		//判断⼦弹是否消失
		if ((cur->y > hero.y + HEIGHT/2) || (cur->y < hero.y - HEIGHT/2) ||
			(cur->x > hero.x + WIDTH/2) || (cur->x < hero.x - WIDTH/2))
			cur->isExist = 0;
		struct node_monster* cur_m = head_m;
		while (cur_m != NULL) {
			if (cur_m->inf.Health_point) {
				cur->isExist = IfHit(cur_m->inf.x, cur_m->inf.y, cur_m->inf.type,cur->x,cur->y);
				if (cur->isExist == 0)
					cur_m->inf.Health_point--;
			}
			cur_m = cur_m->next;
		}
		cur = cur->pnext;
	}
}

int IfHit(int m_x, int m_y, int type, int z_x, int z_y)
{
	int r = 1;
	switch (type)
	{
	case 1:
		if (z_x <= m_x && z_x >= m_x - 100 && z_y >= m_y - 85 && z_y <= m_y + 100)
			r = 0;
		break;
	default:
		break;
	}
	return r;
}

void listRemoveNode(list** pplist)
{
	if (*pplist == NULL)
		return;
	list* cur = *pplist;
	list* prev = NULL;
	while (cur != NULL)
	{
		if (cur->isExist == 0)
		{
			if (*pplist == cur)
			{
				*pplist = cur->pnext;
				free(cur);
				cur = *pplist;
				prev = *pplist;
			}
			else
			{
				prev->pnext = cur->pnext;
				free(cur);
				cur = prev;
			}
		}
		else
		{
			prev = cur;
			cur = cur->pnext;
		}
	}
}

IMAGE img_zidanA;

void showAzidan()
{
	listChangeXY(&zidanA_list);
	listRemoveNode(&zidanA_list);
	for (list* cur = zidanA_list; cur != NULL; cur = cur->pnext) {
		if (cur->isExist) {
			drawAlpha(&temp_bk, cur->x - bk.x, cur->y-bk.y , &img_zidanA);
		}
	}
}

void playerAshoot() {
	static int shoot = 1;
	static int start = 0;
	if (GetAsyncKeyState(74))
	{
		if (clock() - start > S_LAG) {
			shoot = 1;
			hero.shoot = 1;
		}
		if (shoot == 1) {
			shoot = 0;
			start = clock();
			vx = 0;
			vy = 0;
			if (GetAsyncKeyState(65))
				vx = -8;
			if (GetAsyncKeyState(68)) {
				vx = 8;
				vy = 0;
			}
			if (GetAsyncKeyState(87)) {
				vy = -8;
			}
			if (GetAsyncKeyState(83))
				vy = 8;
			if (vx == 0 && vy == 0 && hero.dir == 2) {
				vx = 8;
			}
			if (vx == 0 && vy == 0 && hero.dir == 1) {
				vx = -8;
			}
		}
	}
}

void playerAskill() {
	if (GetAsyncKeyState(76))
	{
		int t;
		static int shunyi = 1;
		static clock_t begin = 0;
		static clock_t jishi = 0;
		t = hero.speed;
		if (clock() - begin > SKILL_LAG)
			shunyi = 1;
		if (shunyi == 1) {
			mciSendString(_T("open res/dio.mp3 alias bk"), NULL, 0, NULL);
			mciSendString(_T("play bk"), NULL, 0, NULL);
			shunyi = 0;
			begin = clock();
			jishi = clock();
			while (clock() - jishi < SKILL_TIME) {
				clock_t start_time = clock();
				flushmessage();
				cleardevice();
				hero.speed = 6;
				bkpx = bk.x, bkpy = bk.y;//记录上⼀时刻的背景坐标
				playerMove(hero.speed, hero.x, hero.y);
				bkDraw(hero.speed, hero.x, hero.y);
				playerAshoot();
				gameDraw();//输出背景图和⻆⾊图⽚
				DrawButton();
				DrawMonster1(bk.x, bk.y, bkpx, bkpy);
				showAzidan();
				ctrlFps(start_time);
				FlushBatchDraw();
			}
			mciSendString(_T("close bk"), NULL, 0, NULL);
			hero.speed = t;
		}
	}
}

void ctrlFps(int start_time)
{
	clock_t running_time = clock() - start_time;
	if ((13 - running_time) >= 0)//防⽌睡眠函数使⽤负数
		Sleep(13 - running_time);//动态睡眠
}

// 根据透明度绘图
void drawAlpha(IMAGE *dstimg, int x, int y, IMAGE *srcimg) {
	// 变量初始化
	DWORD *dst = GetImageBuffer(dstimg);
	DWORD *src = GetImageBuffer(srcimg);
	int src_width = srcimg->getwidth();
	int src_height = srcimg->getheight();
	int dst_width = (dstimg == NULL ? getwidth() : dstimg->getwidth()); 
	int dst_height = (dstimg == NULL ? getheight() : dstimg->getheight());
	// 计算贴图的实际长宽
	int iwidth = (x + src_width > dst_width) ? dst_width - x : src_width; // 处理超出右边界
	int iheight = (y + src_height > dst_height) ? dst_height - y : src_height; // 处理超出下边界
	if (x < 0) { src += -x; iwidth -= -x; x = 0; } // 处理超出左边界
	if (y < 0) { src += src_width * -y; iheight -= -y; y = 0; } // 处理超出上边界
	// 修正贴图起始位置
	dst += dst_width * y + x;
	// 实现透明贴图
	for (int iy = 0; iy < iheight; ++iy) {
		for (int i = 0; i < iwidth; ++i)
		{
			int sa = ((src[i] & 0xff000000) >> 24);//获取阿尔法值 if (sa != 0)//假如是完全透明就不处理
			if (sa == 255)//假如完全不透明则直接拷贝
				dst[i] = src[i];
			else//真正需要阿尔法混合计算的图像边界才进行混合
				dst[i] = ((((src[i] & 0xff0000) >> 16) + ((dst[i] & 0xff0000) >> 16) * (255 - sa) / 255) << 16) | ((((src[i] & 0xff00) >> 8) + ((dst[i] & 0xff00) >>8) * (255 - sa) / 255) << 8) | ((src[i] & 0xff) + (dst[i] & 0xff) * (255 - sa) / 255);
		}
		dst += dst_width;
		src += src_width;
	}
}

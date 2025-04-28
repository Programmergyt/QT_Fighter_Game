#pragma once

#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QMovie>
#include "myPushButton.h"
#include <QPropertyAnimation>
#include <QLabel>
#include <QDebug>
#include <Windows.h>

class charact:public QLabel
{
public:
	charact(QLabel* echr, int Enum, int ex, int ey, int edirection);//direction:0为左，1为右边.num为1至4的角色编号
	~charact();
	bool doskill(int sec, int fmovx, int fmovy, int smovx, int smovy, int damage, int range, int ptime, int mystate, char c);//如果为真就返回
	void zoomrole(int prex, int prey, int aftx, int afty, int dur = 400);
	void setmove1();
	void setmove2();
	void labmove(int ex, int ey);
	QLabel* chr;
	QMovie* chr_mov;
	charact* target;
	QString walk[4][2]={":/battle/battle/e_walk_l.gif",":/battle/battle/e_walk_r.gif",
	                    "","",
		                ":/myres/kong.png",":/myres/kong.png",
	                    ":/battle/battle/bear.png",":/battle/battle/student.png"
	                   };//走路动图
	QString run[4][2]={":/battle/battle/e_run_l.gif",":/battle/battle/e_run_r.gif",
		               "","",
		               ":/myres/kong.png",":/myres/kong.png",
		               ":/battle/battle/leimu.png",":/myres/kong.png"
	                  };//跑步动图
	QString stand[4][2]={":/battle/battle/e_stand_l.gif",":/battle/battle/e_stand_r.gif",
		                 "","",
		                 ":/myres/kong.png",":/myres/kong.png",
		                 ":/myres/yang.png",":/myres/yang.png"
	                    };//站立动图
	QString skill[4][5][2]={":/battle/battle/e_jumpfire_l.gif",":/battle/battle/e_jumpfire_r.gif",
		                    ":/battle/battle/e_runball_l.gif",":/battle/battle/e_runball_r.gif",
		                    ":/battle/battle/e_jump_l.gif",":/battle/battle/e_jump_r.gif",
		                    ":/battle/battle/e_handball_l.gif",":/battle/battle/e_handball_r.gif",
		                    ":/battle/battle/e_light_l.gif",":/battle/battle/e_light_r.gif",
		                    "","","","","",//第11个至第15个（包含11和15）
		                    "","","","","","","","","","","","","",//第16个至第28个
		                    "","","","","","","","","","","",""//第29个至第40个
	                       };//技能动图
	QMovie* _walk[4][2];
	QMovie* _run[4][2];
	QMovie* _stand[4][2];
	QMovie* _skill[4][5][2];
	QTimer* timer;
	int _width[4][5] = {239,667,228,260,477};
	int x, y;
	int num;
	int hp=10;
	int skillnum = 0;
	int direction=1;//0向左，1向右
	int wspeed=1;//走路速度
	int rspeed=3;//跑步速度
	int state=0;//0表示站立，1表示走或跑，2及之后表示技能
	bool isover=false;
	int winner;
private:
};

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
	charact(QLabel* echr, int Enum, int ex, int ey, int edirection);//direction:0Ϊ��1Ϊ�ұ�.numΪ1��4�Ľ�ɫ���
	~charact();
	bool doskill(int sec, int fmovx, int fmovy, int smovx, int smovy, int damage, int range, int ptime, int mystate, char c);//���Ϊ��ͷ���
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
	                   };//��·��ͼ
	QString run[4][2]={":/battle/battle/e_run_l.gif",":/battle/battle/e_run_r.gif",
		               "","",
		               ":/myres/kong.png",":/myres/kong.png",
		               ":/battle/battle/leimu.png",":/myres/kong.png"
	                  };//�ܲ���ͼ
	QString stand[4][2]={":/battle/battle/e_stand_l.gif",":/battle/battle/e_stand_r.gif",
		                 "","",
		                 ":/myres/kong.png",":/myres/kong.png",
		                 ":/myres/yang.png",":/myres/yang.png"
	                    };//վ����ͼ
	QString skill[4][5][2]={":/battle/battle/e_jumpfire_l.gif",":/battle/battle/e_jumpfire_r.gif",
		                    ":/battle/battle/e_runball_l.gif",":/battle/battle/e_runball_r.gif",
		                    ":/battle/battle/e_jump_l.gif",":/battle/battle/e_jump_r.gif",
		                    ":/battle/battle/e_handball_l.gif",":/battle/battle/e_handball_r.gif",
		                    ":/battle/battle/e_light_l.gif",":/battle/battle/e_light_r.gif",
		                    "","","","","",//��11������15��������11��15��
		                    "","","","","","","","","","","","","",//��16������28��
		                    "","","","","","","","","","","",""//��29������40��
	                       };//���ܶ�ͼ
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
	int direction=1;//0����1����
	int wspeed=1;//��·�ٶ�
	int rspeed=3;//�ܲ��ٶ�
	int state=0;//0��ʾվ����1��ʾ�߻��ܣ�2��֮���ʾ����
	bool isover=false;
	int winner;
private:
};

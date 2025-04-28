#include "character.h"

charact::charact(QLabel* echr,int Enum,int ex, int ey,int edirection)
{
	chr = echr;
	num = Enum-1;
	direction = edirection;
	//初始化技能movie
	for (int i = 0; i < 2; i++)_walk[num][i] = new QMovie(walk[num][i]);
	for (int i = 0; i < 2; i++)_run[num][i] = new QMovie(run[num][i]);
	for (int i = 0; i < 2; i++)_stand[num][i] = new QMovie(stand[num][i]);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++)
			_skill[num][i][j] = new QMovie(skill[num][i][j]);
	timer = new QTimer(this); timer->start(10);//10毫秒一刷新
	chr->setMovie(_stand[num][direction]); _stand[num][direction]->start();
	chr->setFixedSize(700, 350);
	if (direction == 0)//朝左
	{
		chr->move(700, 550);
		this->x = 700; this->y = 550;
		setmove2();
	}	
	else//朝右
	{
		chr->move(100, 550);
		this->x = 100; this->y = 550;
		setmove1();
	}
}

charact::~charact()
{

}

void charact::setmove1()//人物动作
{
	connect(timer, &QTimer::timeout, [=]() {
		if (this->hp == 1)
		{
			this->isover = true;
			timer->stop();
			return;
		}
		//技能编号，先后两组坐标变换，伤害，范围，延迟击飞，技能state号，按键
		if (doskill(0, -55, -80, 55, 80, 10,220, 500, 2,'Q'))return;
		if (doskill(1, -155, -20, 455, 20, 3,700, 7000, 3,'R'))return;
		if (doskill(2, -5, -80, 5, 80, 0, 0, 0, 4, ' '))return;
		if (doskill(3, -10, -15, 10, 25, 2, 300, 2500, 5, 'E'))return;
		if (doskill(4, -35, -60, 35, 60, 1, 700, 3600, 6, 'X'))return;
		if (GetAsyncKeyState('A') && GetAsyncKeyState('F'))//左跑
		{
			state = 1;
			chr->setMovie(_run[num][0]); _run[num][0]->start();
			labmove(-rspeed, 0);
			direction = 0;
			return;
		}
		if (GetAsyncKeyState('A'))//左走
		{
			state = 1;
			chr->setMovie(_walk[num][0]); _walk[num][0]->start();
			labmove(-wspeed, 0);
			direction = 0;
			return;
		}
		if (GetAsyncKeyState('D') && GetAsyncKeyState('F'))//右跑
		{
			state = 1;
			chr->setMovie(_run[num][1]); _run[num][1]->start();
			labmove(rspeed, 0);
			direction = 1;
			return;
		}
		if (GetAsyncKeyState('D'))//右走
		{
			state = 1;
			chr->setMovie(_walk[num][1]); _walk[num][1]->start();
			labmove(wspeed, 0);
			direction = 1;
			return;
		}
		if (GetAsyncKeyState('S'))//下走
		{
			state = 1;
			chr->setMovie(_walk[num][direction]); _walk[num][direction]->start();
			labmove(0, wspeed);
			return;
		}
		if (GetAsyncKeyState('W'))//上走
		{
			state = 1;
			chr->setMovie(_walk[num][direction]); _walk[num][direction]->start();
			labmove(0, -wspeed);
			return;
		}
		if (state == 0 || state == 1)//站立
		{
			state = 0;
			chr->setMovie(_stand[num][direction]);_stand[num][direction]->start();
			//qDebug() << chr->x() << "  " << chr->y()<<"  "<<direction;
			return;
		}
		});
}

void charact::setmove2()//人物行走
{
	connect(timer, &QTimer::timeout, [=]() {
		if (this->hp == 1)
		{
			timer->stop();
			this->isover = true;
			return;
		}
		if (GetAsyncKeyState('J') && GetAsyncKeyState('H'))//左跑
		{
			state = 1;
			chr->setMovie(_run[num][0]); _run[num][0]->start();
			labmove(-rspeed, 0);
			direction = 0;
			return;
		}
		if (GetAsyncKeyState('J'))//左走
		{
			state = 1;
			chr->setMovie(_walk[num][0]); _walk[num][0]->start();
			labmove(-wspeed, 0);
			direction = 0;
			return;
		}
		if (GetAsyncKeyState('L') && GetAsyncKeyState('H'))//右跑
		{
			state = 1;
			chr->setMovie(_run[num][1]); _run[num][1]->start();
			labmove(rspeed, 0);
			direction = 1;
			return;
		}
		if (GetAsyncKeyState('L'))//右走
		{
			state = 1;
			chr->setMovie(_walk[num][1]); _walk[num][1]->start();
			labmove(wspeed, 0);
			direction = 1;
			return;
		}
		if (GetAsyncKeyState('K'))//下走
		{
			state = 1;
			chr->setMovie(_walk[num][direction]); _walk[num][direction]->start();
			labmove(0, wspeed);
			return;
		}
		if (GetAsyncKeyState('I'))//上走
		{
			state = 1;
			chr->setMovie(_walk[num][direction]); _walk[num][direction]->start();
			labmove(0, -wspeed);
			return;
		}
		if(state!=2)//站立
		{
			state = 0;
			chr->setMovie(_stand[num][direction]); _stand[num][direction]->start();
			return;
		}
		});
	/*
	    DEBUG用
		connect(timertest, &QTimer::timeout, [=]() {
		for(int i=0;i<30;i++)
		qDebug() << chr->x() << "  " << chr->y()<<"  "<<num;
		});
	*/
}

void charact::labmove(int ex, int ey)
{
	chr->move(chr->x() + ex, chr->y() + ey);
	this->x += ex; this->y += ey;
}

void charact::zoomrole(int prex,int prey,int aftx,int afty,int dur)
{
	QPropertyAnimation* animation = new QPropertyAnimation(this->chr, "geometry");
	animation->setDuration(dur);
	animation->setStartValue(QRect(this->x+prex, this->y + prey, 350, 350));//起始位置
	animation->setEndValue(QRect(this->x+aftx, this->y + afty, 350, 350));//结束位置
	animation->setEasingCurve(QEasingCurve::OutBounce);//设置运动曲线
	animation->start();
}

bool charact::doskill(int sec, int fmovx, int fmovy, int smovx, int smovy, int damage,int range,int ptime,int mystate, char c)
{
	if (_skill[num][sec][direction]->state() == QMovie::Running)
	{
		return true;//如果正在释放技能就什么也不做直接返回
	}
	else if (state == mystate && _skill[num][sec][direction]->state() == QMovie::NotRunning)
	{
		if (direction == 1)labmove(smovx, smovy);//坐标系变换回去
		else labmove(_width[num][sec]-120-smovx, smovy);//如果向左，则需考虑图像宽度和人物宽度来改变坐标
		state = 0;
	}
	if (GetAsyncKeyState(c))
	{
		state = mystate;//改变状态以便之后识别状态
		if (direction == 1)labmove(fmovx, fmovy);//坐标系变换
		else labmove(-_width[num][sec]+120 - fmovx, fmovy);//如果向左，则需考虑图像宽度和人物宽度来改变坐标
		if (target->x - this->x<range && target->x - this->x>(-1*range))
		{
			if(damage!=0)//如果是攻击技能再击飞并扣血
			QTimer::singleShot(ptime, this, [=]() {
				if (target->hp < damage + 1)target->hp = 1;
				else target->hp -= damage;
				target->zoomrole(0, 0, 0, -140, 500);
				target->zoomrole(0, -140, 0, 0, 500);
				});
		}
		skillnum++;//计算释放技能的数目
		chr->setMovie(_skill[num][sec][direction]);//设置技能movie
		_skill[num][sec][direction]->start();//开始movie
		return true;
	}
}
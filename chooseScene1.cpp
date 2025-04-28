#include "chooseScene1.h"

chooseScene1::chooseScene1(QWidget* emainmenu,QWidget* parent)
    : QWidget(parent)
{
    this->setFixedSize(1280, 960);
    setWindowIcon(QIcon(":/myres/good.png"));
    setWindowTitle("GYT's Battle Game");
    this->mainmenu = emainmenu;

    //左上角用于填充背景的标签
    QLabel* bkgrounds = new QLabel(this);
    bkgrounds->setFixedSize(300, 128); bkgrounds->move(0,-10);
    bkgrounds->setPixmap(QPixmap(":/myres/menusmall.png")); bkgrounds->show();

    //背景图
    QLabel* bkground = new QLabel(this);
    bkground->setFixedSize(1280, 960); bkground->move(0, 0);
    bkground->setPixmap(QPixmap(":/myres/menu.png")); bkground->show();
    
    //标题
    QLabel* title2 = new QLabel(this);
    title2->setFixedSize(567, 170); title2->move(350,-28);
    title2->setPixmap(QPixmap(":/myres/title2.png")); title2->show();

    //返回主菜单的按钮
    rtbtn = new myPushButton(":/myres/rtbtn.png");
    rtbtn->setParent(this); rtbtn->move(0,0); rtbtn->show();

    //前往下一个页面的按钮
    nxbtn = new myPushButton(":/myres/nxbtn.png");
    nxbtn->setParent(this); nxbtn->move(980, 0); nxbtn->show();
    cm = new chooseMap(this->mainmenu); cm->mainmenu = this->mainmenu;
    connect(nxbtn, &myPushButton::clicked, [=]() {nxbtn->zoom(0, 10); nxbtn->zoom(10, 0);
    QTimer::singleShot(1000, this, [=]() {this->hide(); cm->show();}); });//选择角色窗口的返回键

    //选择角色的控件
    cw = new chooseWidget(this); cw->move(280, 150); cw->show();

    //”玩家1“标签
    QLabel* player1 = new QLabel(this);
    player1->move(-100, 120); player1->setPixmap(QPixmap(":/myres/lab_player1.png"));

    //玩家2标签
    QLabel* player2 = new QLabel(this);
    player2->move(-100, 520); player2->setPixmap(QPixmap(":/myres/lab_player2.png"));

    //八神庵标签
    QLabel* eight = new QLabel(this); eight->move(280, 150);
    eight->setFixedSize(200, 200);
    QMovie* movie_eight = new QMovie(":/myres/eightstand.gif");
    eight->setMovie(movie_eight); movie_eight->start();

    //不知火舞标签
    QLabel* nofire = new QLabel(this); nofire->move(280, 350);
    nofire->setFixedSize(200, 200);
    QMovie* movie_nofire = new QMovie(":/myres/nofirestand.gif");
    nofire->setMovie(movie_nofire); movie_nofire->start();

    //老好人标签
    QLabel* lhr = new QLabel(this);
    lhr->setFixedSize(200, 200); lhr->move(280, 550);
    lhr->setPixmap(QPixmap(":/myres/kong.png"));

    //牛头人标签
    QLabel* ntr = new QLabel(this);
    ntr->setFixedSize(200, 200); ntr->move(280, 750);
    ntr->setPixmap(QPixmap(":/myres/yang.png"));

    //八神庵按钮与标签移动的连接
    connect(cw->role1, &myPushButton::clicked, [=]() {
        cw->role1->zoom(0, 10); cw->role1->zoom(10, 0); choosenum++;
        if (choosenum == 1)
        {
            zoom(eight, 0, 0, -250, 170);
            cm->chooserole1 = 1;
        }
        else if (choosenum == 2)
        {
            zoom(eight, 0, 0, -250, 570);
            cm->chooserole2 = 2;
        }
        });

    //不知火舞按钮与标签移动的连接
    connect(cw->role2, &myPushButton::clicked, [=]() {
        cw->role2->zoom(0, 10); cw->role2->zoom(10, 0); choosenum++;
        if (choosenum == 1)
        {
            zoom(nofire, 0, 0, -250, -30);
            cm->chooserole1 = 2;
        }
        else if (choosenum == 2)
        {
            zoom(nofire, 0, 0, -250, 370);
            cm->chooserole2 = 2;
        }
        });

    //老好人按钮与标签移动的连接
    connect(cw->role3, &myPushButton::clicked, [=]() {
        cw->role3->zoom(0, 10); cw->role3->zoom(10, 0); choosenum++;
        if (choosenum == 1)
        {
            zoom(lhr, 0, 0, -250, -230);
            cm->chooserole1 = 3;
        }
        else if (choosenum == 2)
        {
            zoom(lhr, 0, 0, -250, 170);
            cm->chooserole2 = 3;
        }
        });

    //牛头人按钮与标签移动的连接
    connect(cw->role4, &myPushButton::clicked, [=]() {
        cw->role4->zoom(0, 10); cw->role4->zoom(10, 0); choosenum++;
        if (choosenum == 1)
        {
            zoom(ntr, 0, 0, -250, -430);
            cm->chooserole1 = 4;
        }
        else if (choosenum == 2)
        {
            zoom(ntr, 0, 0, -250, -30);
            cm->chooserole2 = 4;
        }
        });

    //返回主菜单按钮
    connect(cm->rtbtn, &myPushButton::clicked, [=]() {
        cm->rtbtn->zoom(0, 10); cm->rtbtn->zoom(10, 0);
        QTimer::singleShot(1000, this, [=]() {this->show(); cm->hide();});
        });
}

chooseScene1::~chooseScene1()
{

}

void chooseScene1::zoom(QLabel* a, int prex, int prey, int aftx, int afty)
{
    QPropertyAnimation* animation = new QPropertyAnimation(a, "geometry");
    animation->setDuration(800);
    animation->setStartValue(QRect(a->x()+prex, a->y() + prey, a->width(), a->height()));//起始位置
    animation->setEndValue(QRect(a->x()+aftx, a->y() + afty, a->width(), a->height()));//结束位置
    animation->setEasingCurve(QEasingCurve::OutBounce);//设置运动曲线
    animation->start();
}





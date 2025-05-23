#include "chooseMap.h"

chooseMap::chooseMap(QWidget* emainmenu,QWidget* parent)
    : QWidget(parent)
{
    //窗口基本参数 
    this->setFixedSize(1280, 960);
    setWindowIcon(QIcon(":/myres/good.png"));
    setWindowTitle("GYT's Battle Game");
    this->mainmenu = emainmenu;

    //大背景
    QLabel* bkground = new QLabel(this);
    bkground->setFixedSize(1280, 960); bkground->move(0, 0);
    bkground->setPixmap(QPixmap(":/myres/menu.png")); bkground->show();

    //左上角小背景
    QLabel* bkgrounds = new QLabel(this);
    bkgrounds->setFixedSize(300, 128); bkgrounds->move(0, -10);
    bkgrounds->setPixmap(QPixmap(":/myres/menusmall.png")); bkgrounds->show();

    //标题
    QLabel* title3 = new QLabel(this);
    title3->setFixedSize(567, 170); title3->move(350, -28);
    title3->setPixmap(QPixmap(":/myres/title3.png")); title3->show();

    //”返回“的按钮
    rtbtn = new myPushButton(":/myres/rtbtn.png");
    rtbtn->setParent(this); rtbtn->move(0, 0); rtbtn->show();

    //背景1标签
    QLabel* bg1 = new QLabel(this); bg1->move(290, 130);
    bg1->setFixedSize(450, 350);
    QMovie* movie_bg1 = new QMovie(":/myres/bg1.gif");
    bg1->setMovie(movie_bg1); movie_bg1->start();

    //背景2标签
    QLabel* bg2 = new QLabel(this); bg2->move(790, 130);
    bg2->setFixedSize(450, 350);
    QMovie* movie_bg2 = new QMovie(":/myres/bg2.gif");
    bg2->setMovie(movie_bg2); movie_bg2->start();

    //背景3标签
    QLabel* bg3 = new QLabel(this); bg3->move(290, 550);
    bg3->setFixedSize(450, 350);
    QMovie* movie_bg3 = new QMovie(":/myres/bg3.gif");
    bg3->setMovie(movie_bg3); movie_bg3->start();

    //背景4标签
    QLabel* bg4 = new QLabel(this); bg4->move(790, 550);
    bg4->setFixedSize(450, 350);
    QMovie* movie_bg4 = new QMovie(":/myres/bg4.gif");
    bg4->setMovie(movie_bg4); movie_bg4->start();

    //绿色的勾标签
    QLabel* hook = new QLabel(this); hook->move(1285, 300);
    hook->setFixedSize(66, 56); hook->setPixmap(QPixmap(":/myres/hook.png"));

    //背景1按钮
    myPushButton* btn_bg1 = new myPushButton(":/myres/btn_map1.png");
    btn_bg1->setParent(this); btn_bg1->move(20, 150);
    connect(btn_bg1, &myPushButton::clicked, [=]() {
        btn_bg1->zoom(0, 10); btn_bg1->zoom(10, 0);
        choosenum++; if (choosenum == 1)
        {
            zoom(hook, 0, 0, -995, -170);
            bsnum = 1;
        }
        });

    //背景2按钮
    myPushButton* btn_bg2 = new myPushButton(":/myres/btn_map2.png");
    btn_bg2->setParent(this); btn_bg2->move(20, 350);
    connect(btn_bg2, &myPushButton::clicked, [=]() {
        btn_bg2->zoom(0, 10); btn_bg2->zoom(10, 0);
        choosenum++; if (choosenum == 1)
        {
            zoom(hook, 0, 0, -495, -170);
            bsnum = 2;
        }
        });

    //背景3按钮
    myPushButton* btn_bg3 = new myPushButton(":/myres/btn_map3.png");
    btn_bg3->setParent(this); btn_bg3->move(20, 550);
    connect(btn_bg3, &myPushButton::clicked, [=]() {
        btn_bg3->zoom(0, 10); btn_bg3->zoom(10, 0);
        choosenum++; if (choosenum == 1)
        {
            zoom(hook, 0, 0, -995, 250);
            bsnum = 3;
        }
        });
    //背景4按钮
    myPushButton* btn_bg4 = new myPushButton(":/myres/btn_map4.png");
    btn_bg4->setParent(this); btn_bg4->move(20, 750);
    connect(btn_bg4, &myPushButton::clicked, [=]() {
        btn_bg4->zoom(0, 10); btn_bg4->zoom(10, 0);
        choosenum++; if (choosenum == 1)
        {
            zoom(hook, 0, 0, -495, 250);
            bsnum = 4;
        }
        });

    //"下一步“按钮
    nxbtn = new myPushButton(":/myres/nxbtn.png");
    nxbtn->setParent(this); nxbtn->move(980, 0); nxbtn->show();
    connect(nxbtn, &myPushButton::clicked, [=]() {
        nxbtn->zoom(0, 10); nxbtn->zoom(10, 0);
        QTimer::singleShot(800, this, [=]() {
            bs = new battleScene(this->mainmenu,bsnum, chooserole1, chooserole2);
            bs->mainmenu = this->mainmenu;
            this->hide(); bs->show(); });
        });
}

chooseMap::~chooseMap()
{

}

void chooseMap::zoom(QLabel* a, int prex, int prey, int aftx, int afty,int dur)
{
    QPropertyAnimation* animation = new QPropertyAnimation(a, "geometry");
    animation->setDuration(dur);
    animation->setStartValue(QRect(a->x() + prex, a->y() + prey, a->width(), a->height()));//起始位置
    animation->setEndValue(QRect(a->x() + aftx, a->y() + afty, a->width(), a->height()));//结束位置
    animation->setEasingCurve(QEasingCurve::OutBounce);//设置运动曲线
    animation->start();
}




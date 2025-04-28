#include "battleScene.h"

battleScene::battleScene(QWidget* parent)
    : QWidget(parent)
{

}

battleScene::battleScene(QWidget* emainmenu,int battlemap, int role1, int role2)
{
    //���ڻ�������
    this->setFixedSize(1280, 960);
    setWindowIcon(QIcon(":/myres/good.png"));
    setWindowTitle("GYT's Battle Game");
    this->mainmenu = emainmenu;

    //����ͼƬ
    QLabel* bg = new QLabel(this); bg->move(0, 0); bg->setFixedSize(1280, 960);
    QMovie* bk = new QMovie(map[battlemap-1]); bg->setMovie(bk); bk->start();

    //��߿���������ͷ����������Ѫ��
    QLabel* frame1 = new QLabel(this); frame1->move(10, 10); frame1->setFixedSize(200, 200);
    frame1->setPixmap(QPixmap(":/myres/frame1.png"));
    QLabel* role1_Icon = new QLabel(this); role1_Icon->move(10, 10); role1_Icon->setFixedSize(200, 200);
    QMovie* role1_mov = new QMovie(name[role1 - 1]); role1_Icon->setMovie(role1_mov); role1_mov->start();
    QLabel* blood1 = new QLabel(this); blood1->setFixedSize(350, 350); blood1->move(210, -60);
    blood1->setPixmap(QPixmap(":/hp/HPBAR/hpbar10.png"));

    //�ұ߿���������ͷ����������Ѫ��
    QLabel* frame2 = new QLabel(this); frame2->move(990, 10); frame2->setFixedSize(200, 200);
    frame2->setPixmap(QPixmap(":/myres/frame1.png"));
    QLabel* role2_Icon = new QLabel(this); role2_Icon->move(990, 10); role2_Icon->setFixedSize(200, 200);
    QMovie* role2_mov = new QMovie(name[role2 - 1]); role2_Icon->setMovie(role2_mov); role2_mov->start();
    QLabel* blood2 = new QLabel(this); blood2->setFixedSize(350, 350); blood2->move(640, -60);
    blood2->setPixmap(QPixmap(":/hp/HPBAR/hpbarr10.png"));

    //vs��ǩ
    QLabel* vs_Icon = new QLabel(this); vs_Icon->move(535, 75); vs_Icon->setFixedSize(135, 86);
    vs_Icon->setPixmap(QPixmap(":/myres/lab_vs.png"));

    //ready��ǩ
    ready = new QLabel(this); ready->move(200, 380); ready->setFixedSize(905, 400);
    ready->setPixmap(QPixmap(":/myres/lab_ready.png")); ready->hide();

    //fight��ǩ
    fight = new QLabel(this); fight->move(100, 380); fight->setFixedSize(1086, 400);
    fight->setPixmap(QPixmap(":/myres/lab_fight.png")); fight->hide();

    //ko��ǩ
    ko = new QLabel(this); ko->move(280, 200); ko->setFixedSize(700, 455);
    ko->setPixmap(QPixmap(":/battle/battle/ko.png")); ko->hide();

    //��������
    QTimer::singleShot(1000, this, [=]()
        {
        ready->show();
        });
    QTimer::singleShot(3500, this, [=]() {
        ready->hide();
        fight->show();
        });
    QTimer::singleShot(4500, this, [=]() {
        fight->hide();
        });

    //���������ʼ��
    QLabel* b = new QLabel(this);
    QLabel* a = new QLabel(this);
    chr1 = new charact(a, role1, 100, 700, 1);
    chr2 = new charact(b, role2, 700, 700, 0);
    chr1->target = chr2; chr2->target = chr1;

    //��ͣ��
    myPushButton* pause = new myPushButton(":/myres/pause.png"); pause->move(1190, 10);
    pause->setParent(this); connect(pause, &myPushButton::clicked, [=]() {
        pause->zoom(0, 10); pause->zoom(10, 0); QTimer::singleShot(800, this, [=]() {
            if(chr1->state!=4&&chr2->state!=4)//�����Ī������İ��ո񵯳�������Ϣ������
            QMessageBox::critical(this, "YOU MUST DEFEND 401", "It's your destiny to teach them a lesson!Don't pause!");
            });
        });

    //��ʾѪ�����ж�ʤ���ļ�ʱ��
    QTimer* timer = new QTimer(this); timer->start(200);
    connect(timer, &QTimer::timeout, [=]() {
        timecount++;
        QString a=QString(":/hp/HPBAR/hpbar%1.png").arg(chr1->hp);
        QString b = QString(":/hp/HPBAR/hpbarr%1.png").arg(chr2->hp);
        blood1->setPixmap(QPixmap(a));
        blood2->setPixmap(QPixmap(b));
        if (chr2->isover)
        {
            ko->show();
            timer->stop();
            QTimer::singleShot(1800, this, [=]() {
                myscore = new score(this->mainmenu,timecount / 5, role1,role2,chr1->skillnum,chr2->skillnum,battlemap);
                myscore->show();
            this->hide();
                });
        }
        else if (chr1->isover)
        {
            ko->show();
            timer->stop();
            QTimer::singleShot(1800, this, [=]() {
                myscore = new score(this->mainmenu,timecount / 5, role2, role1, chr1->skillnum, chr2->skillnum, battlemap);
                myscore->show();
                this->hide();
                });
        }
        });
}

battleScene::~battleScene()
{

}

void battleScene::zooming(QLabel* a, int prex, int prey, int aftx, int afty,int dur)
{
    QPropertyAnimation* animation = new QPropertyAnimation(a, "geometry");
    animation->setDuration(dur);
    animation->setStartValue(QRect(a->x() + prex, a->y() + prey, a->width(), a->height()));//��ʼλ��
    animation->setEndValue(QRect(a->x() + aftx, a->y() + afty, a->width(), a->height()));//����λ��
    animation->setEasingCurve(QEasingCurve::Linear);//�����˶�����
    animation->start();
}



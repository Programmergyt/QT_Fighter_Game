#include "QtWidgetsApplication.h"
#include "myPushButton.h"
#include "chooseScene1.h"


QtWidgetsApplication::QtWidgetsApplication(QWidget *parent)
    : QMainWindow(parent)
{
    //���ڻ�������
    qDebug() << "ssssGridman";
    ui.setupUi(this);
    setWindowIcon(QIcon(":/myres/good.png"));
    setWindowTitle("GYT's Battle Game");
    this->setFixedSize(1280, 960);

    //(QLabel)��ȭ�ʡ�����
    ui.label->setFixedSize(1280, 426); ui.label->move(0, 0);
    QPixmap title; title.load(":/myres/plainstbtn.png"); ui.label->setPixmap(title);

    //����ͼƬ
    ui.label_2->move(QPoint(0,0)); ui.label_2->setFixedSize(1280,960);
    QMovie* menubk = new QMovie(":/myres/truefire.gif");
    ui.label_2->setMovie(menubk);
    menubk->start();

    //ѡ���ɫ���ڳ�ʼ��
    cs1 = new chooseScene1(this); cs1->mainmenu = this;
    connect(cs1->rtbtn, &myPushButton::clicked, [=]() {cs1->rtbtn->zoom(0, 10); cs1->rtbtn->zoom(10, 0);
        QTimer::singleShot(1000, this, [=]() {cs1->hide(); this->show(); }); });//ѡ���ɫ���ڵķ��ؼ�

    //���ô��ڳ�ʼ��
    ss = new settingScene(this);
    connect(ss->rtbtn, &myPushButton::clicked, [=]() {ss->rtbtn->zoom(0, 10); ss->rtbtn->zoom(10, 0);
    QTimer::singleShot(1000, this, [=]() {ss->hide(); this->show(); }); });//���ô��ڵķ��ؼ�

    //��ʼ��Ϸ��ť
    myPushButton* stbtn = new myPushButton(":/myres/stbtn.png");
    stbtn->setParent(this); stbtn->move(440, 350); stbtn->show();
    connect(stbtn, &myPushButton::clicked, [=]() {stbtn->zoom(0, 10); stbtn->zoom(10, 0);
        QTimer::singleShot(1000, this, [=]() {this->hide(); cs1->show(); });  });//˫��lambda���ʽʵ����ʱ�л�����

    //��Ϸ���ð�ť
    myPushButton* subtn = new myPushButton(":/myres/subtn.png");
    subtn->setParent(this); subtn->move(440, 550); subtn->show();
    connect(subtn, &myPushButton::clicked, [=]() {subtn->zoom(0, 10); subtn->zoom(10, 0);
    QTimer::singleShot(1000, this, [=]() {this->hide(); ss->show(); }); });
    
    //�˳���Ϸ��ť,���º��˳���Ϸ
    myPushButton* clbtn = new myPushButton(":/myres/clbtn.png");
    clbtn->setParent(this); clbtn->move(440, 750); clbtn->show();
    connect(clbtn, &myPushButton::clicked, [=]() {clbtn->zoom(0, 10); clbtn->zoom(10, 0);
        QTimer::singleShot(1000, this, [=]() {this->close(); });});

}

void QtWidgetsApplication::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap menubk;

}
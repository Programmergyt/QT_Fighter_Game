#include "chooseWidget.h"

chooseWidget::chooseWidget(QWidget* parent)
    : QWidget(parent)
{
    this->setFixedSize(1000, 800);
    
    //ѡ������ֵİ�ť,�����ֶ�ͼ��ǩ�Լ����ֽ��ܱ�ǩ
    role1 = new myPushButton(":/myres/btn_eight.png");
    role1->setParent(this);role1->move(600, 0);

    QLabel* introduction1 = new QLabel(this); introduction1->move(200, 0);
    introduction1->setFixedSize(400, 200);
    introduction1->setPixmap(QPixmap(":/myres/eight_introduction.png"));

    //ѡ��֪����
    role2 = new myPushButton(":/myres/btn_nofire.png");
    role2->setParent(this); role2->move(600,200);

    QLabel* introduction2 = new QLabel(this); introduction2->move(200, 200);
    introduction2->setFixedSize(400, 200);
    introduction2->setPixmap(QPixmap(":/myres/nofire_introduction.png"));

    //ѡ���Ϻ���
    role3 = new myPushButton(":/myres/btn_lhr.png");
    role3->setParent(this); role3->move(600, 400);

    QLabel* introduction3 = new QLabel(this); introduction3->move(200, 400);
    introduction3->setFixedSize(400, 200);
    introduction3->setPixmap(QPixmap(":/myres/lhr_introduction.png"));

    //ѡ��ţͷ��
    role4 = new myPushButton(":/myres/btn_ntr.png");
    role4->setParent(this); role4->move(600, 600);

    QLabel* introduction4 = new QLabel(this); introduction4->move(200, 600);
    introduction4->setFixedSize(400, 200);
    introduction4->setPixmap(QPixmap(":/myres/ntr_introduction.png"));

}

chooseWidget::~chooseWidget()
{

}




#include "myPushButton.h"

myPushButton::myPushButton(QWidget* parent)
    : QPushButton(parent)
{

}

myPushButton::~myPushButton()
{

}

myPushButton::myPushButton(QString normalImg, QString pressImg)
{
    this->normalPath = normalImg;
    this->pressPath = pressImg;
    QPixmap pix; pix.load(normalPath);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix); this->setIconSize(QSize(pix.width(), pix.height()));
}

void myPushButton::zoom(int pre,int aft, int flag, int duration)
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(duration);
    if (flag == 1)
    {
        animation->setStartValue(QRect(this->x(), this->y() + pre, this->width(), this->height()));//��ʼλ��
        animation->setEndValue(QRect(this->x(), this->y() + aft, this->width(), this->height()));//����λ��
    }
    else
    {
        animation->setStartValue(QRect(this->x()+pre, this->y(), this->width(), this->height()));//��ʼλ��
        animation->setEndValue(QRect(this->x()+aft, this->y(), this->width(), this->height()));//����λ��
    }
    animation->setEasingCurve(QEasingCurve::OutBounce);//�����˶�����
    animation->start();
}


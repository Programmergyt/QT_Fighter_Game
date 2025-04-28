#pragma once

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPropertyAnimation>

class myPushButton : public QPushButton
{
    Q_OBJECT//信号与槽的时候需要

public:
    myPushButton(QWidget* parent = 0);
    myPushButton(QString normalImg, QString pressImg = "");
    ~myPushButton();

    void zoom(int pre,int aft,int flag=1,int duration=400);//pre和aft表示始末坐标变化，flag为1表示纵向动，flag为0表示横向动
    QString normalPath;
    QString pressPath;
signals:
public slots:
private:
    QPushButton b1;
};


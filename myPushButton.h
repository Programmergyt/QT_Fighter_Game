#pragma once

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPropertyAnimation>

class myPushButton : public QPushButton
{
    Q_OBJECT//�ź���۵�ʱ����Ҫ

public:
    myPushButton(QWidget* parent = 0);
    myPushButton(QString normalImg, QString pressImg = "");
    ~myPushButton();

    void zoom(int pre,int aft,int flag=1,int duration=400);//pre��aft��ʾʼĩ����仯��flagΪ1��ʾ���򶯣�flagΪ0��ʾ����
    QString normalPath;
    QString pressPath;
signals:
public slots:
private:
    QPushButton b1;
};


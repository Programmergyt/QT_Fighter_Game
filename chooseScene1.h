#pragma once

#include <QWidget>
#include <QTimer>
#include "myPushButton.h"
#include <QLabel>
#include <QPropertyAnimation>
#include "chooseWidget.h"
#include "chooseMap.h"
//#include <QDebug>
#include <QString>

class chooseScene1 : public QWidget
{
    Q_OBJECT//信号与槽的时候需要

public:
    chooseScene1(QWidget* emainmenu,QWidget* parent = 0);
    ~chooseScene1();
    myPushButton* rtbtn;
    myPushButton* nxbtn;
    chooseWidget* cw;
    chooseMap* cm;
    QWidget* mainmenu;
    int choosenum = 0;
    void zoom(QLabel* a, int prex, int prey, int aftx, int afty);
signals:
public slots:
private:
};


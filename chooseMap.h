#pragma once

#include <QWidget>
#include <QPushButton>
#include <Windows.h>
#include <QTimer>
#include <QMovie>
#include "myPushButton.h"
#include "battleScene.h"
#include <QPropertyAnimation>
#include <QLabel>
//#include <QDebug>

class chooseMap : public QWidget
{
    Q_OBJECT//信号与槽的时候需要

public:
    chooseMap(QWidget* emainmenu,QWidget* parent = 0);
    ~chooseMap();
    void zoom(QLabel* a, int prex, int prey, int aftx, int afty,int dur=500);
    myPushButton* rtbtn;
    myPushButton* nxbtn;
    QWidget* mainmenu;
    int choosenum = 0;
    int chooserole1;
    int chooserole2;
    int bsnum;
    battleScene* bs;
signals:
public slots:
private:
};

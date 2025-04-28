#pragma once

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QMessageBox>
#include <QPainter>
#include <QTimer>
#include <QMovie>
#include <QKeyEventTransition>
#include <Windows.h>
#include <QPropertyAnimation>
#include <QLabel>
#include "myPushButton.h"
#include "character.h"
#include "score.h"

class battleScene : public QWidget
{
    Q_OBJECT//信号与槽的时候需要

public:
    battleScene(QWidget* parent = 0);
    battleScene(QWidget* emainmenu,int battlemap, int role1, int role2);
    ~battleScene();
    void zooming(QLabel* a, int prex, int prey, int aftx, int afty,int dur=500);
    QString name[4] = { ":/myres/eightstand.gif",":/myres/nofirestand.gif",":/myres/kong.png",":/myres/yang.png"};
    QString map[4] = { ":/myres/bg1_battle.gif",":/myres/bg2_battle.gif",":/myres/bg3_battle.gif",":/myres/bg4_battle.gif" };
    QLabel* ready;
    QLabel* fight;
    QLabel* ko;
    QWidget* mainmenu;
    charact* chr1;
    charact* chr2;
    score* myscore;
    int timecount = 0;
signals:
public slots:
private:
};
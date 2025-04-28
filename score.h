#pragma once

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QTimer>
#include <QMovie>
#include <Windows.h>
#include <QPropertyAnimation>
#include <QLabel>
#include <QPalette>
#include <QMessageBox>
#include <QTextBrowser>
#include "myPushButton.h"
#include "character.h"
#include <QTextCodec>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <mysql.h>
#include <QFont>
#pragma execution_character_set("utf-8")//设置执行字符集，指示char的执行字符集是UTF-8编码

using namespace std;

class score : public QWidget
{
    Q_OBJECT//信号与槽的时候需要

public:
    score(QWidget* parent = 0);
    score(QWidget* emainmenu,int duration, int winner,int loser,int skillnum1,int skillnum2,int emap);
    ~score();
    void connect_mysql(int duration, int winner, int loser, int skillnum1, int skillnum2,int map);
    QWidget* mainmenu;
    myPushButton* btn_close;
    myPushButton* btn_rtn;
    string map[4] = { "落日神社","磐石海岸","星辉宫殿","远海帆船"};
    string sql_name[4] = { "八神庵","不知火舞","老好人","牛头人" };
    QString name[4] = {"八神庵","不知火舞","老好人","牛头人"};
    string reason_win[8] = {"","","",""};
    string reason_lose[8] = {"","","",""};
    bool ret = false;
signals:
    void mysignal();
public slots:
private:
};

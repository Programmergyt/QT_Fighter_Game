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
#pragma execution_character_set("utf-8")//����ִ���ַ�����ָʾchar��ִ���ַ�����UTF-8����

using namespace std;

class score : public QWidget
{
    Q_OBJECT//�ź���۵�ʱ����Ҫ

public:
    score(QWidget* parent = 0);
    score(QWidget* emainmenu,int duration, int winner,int loser,int skillnum1,int skillnum2,int emap);
    ~score();
    void connect_mysql(int duration, int winner, int loser, int skillnum1, int skillnum2,int map);
    QWidget* mainmenu;
    myPushButton* btn_close;
    myPushButton* btn_rtn;
    string map[4] = { "��������","��ʯ����","�ǻԹ���","Զ������"};
    string sql_name[4] = { "������","��֪����","�Ϻ���","ţͷ��" };
    QString name[4] = {"������","��֪����","�Ϻ���","ţͷ��"};
    string reason_win[8] = {"","","",""};
    string reason_lose[8] = {"","","",""};
    bool ret = false;
signals:
    void mysignal();
public slots:
private:
};

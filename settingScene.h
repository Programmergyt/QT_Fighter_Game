#pragma once

#include <QWidget>
#include <QTimer>
#include <QSlider>
#include <QLabel>
#include <QMediaPlayer>
#include <QMediaPlayList>
#include <QVideoWidget>
#include <QSound>
#include <QTextBrowser>
#include <QPropertyAnimation>
#include <QDebug>
#include <QString>
#include "chooseWidget.h"
#include "chooseMap.h"
#include "myPushButton.h"

class volumeWidget :public QWidget
{
	Q_OBJECT;//�źźͲ��л��õ�
public:
	volumeWidget(QWidget* parent = Q_NULLPTR);
	~volumeWidget();
	QMediaPlayer* player ;
	QMediaPlaylist* playlist=nullptr ;
};

class sqlWidget :public QWidget
{
	Q_OBJECT;//�źźͲ��л��õ�
public:
	sqlWidget(QWidget* parent = Q_NULLPTR);
	~sqlWidget();
	void connect_mysql();
	QString *sqlresult;
};

class creatorWidget :public QWidget
{
	Q_OBJECT;//�źźͲ��л��õ�
public:
	creatorWidget(QWidget* parent = Q_NULLPTR);
	~creatorWidget();
};

class settingScene :public QWidget
{
	Q_OBJECT;//�źźͲ��л��õ�
public:
	settingScene(QWidget* parent = Q_NULLPTR);
	~settingScene();
	QWidget* currentWidget = nullptr;
	myPushButton* currentButton = nullptr;
	volumeWidget* vw = nullptr;
	sqlWidget* sw = nullptr;
	creatorWidget* cw = nullptr;
	myPushButton* rtbtn;
};


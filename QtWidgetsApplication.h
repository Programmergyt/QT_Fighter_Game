#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication.h"
#include "settingScene.h"
#include "chooseScene1.h"
#include <QPainter>
#include <QTimer>
#include <QPushButton>
#include <QMovie>
#include <QLabel>
#include <QDebug>

class QtWidgetsApplication : public QMainWindow
{
    Q_OBJECT//信号和槽中会用到

public:
    QtWidgetsApplication(QWidget *parent = Q_NULLPTR);
    void paintEvent(QPaintEvent*);
    chooseScene1* cs1;
    settingScene* ss;
private:
    Ui::QtWidgetsApplicationClass ui;
};

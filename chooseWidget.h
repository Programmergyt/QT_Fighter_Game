#pragma once
#include <QWidget>
#include "myPushButton.h"
#include <QLabel>
#include <QMovie>

class chooseWidget : public QWidget
{
    Q_OBJECT//信号与槽的时候需要

public:
    chooseWidget(QWidget* parent = 0);
    ~chooseWidget();
    myPushButton* role1;//八神庵
    myPushButton* role2;//不知火舞
    myPushButton* role3;//老好人
    myPushButton* role4;//牛头人

signals:
public slots:
private:
};

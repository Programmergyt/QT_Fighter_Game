#pragma once
#include <QWidget>
#include "myPushButton.h"
#include <QLabel>
#include <QMovie>

class chooseWidget : public QWidget
{
    Q_OBJECT//�ź���۵�ʱ����Ҫ

public:
    chooseWidget(QWidget* parent = 0);
    ~chooseWidget();
    myPushButton* role1;//������
    myPushButton* role2;//��֪����
    myPushButton* role3;//�Ϻ���
    myPushButton* role4;//ţͷ��

signals:
public slots:
private:
};

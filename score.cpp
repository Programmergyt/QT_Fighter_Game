#include "score.h"

score::score(QWidget* parent)
{

}

score::score(QWidget* emainmenu,int duration, int winner,int loser,int skillnum1,int skillnum2,int emap)
{
    //���ڻ�������
    this->setFixedSize(1280, 960);
    setWindowIcon(QIcon(":/battle/battle/win_icon.png"));
    setWindowTitle("GYT's Battle Game");
    this->mainmenu = emainmenu;

    //���ݿ����ս����¼
    connect_mysql(duration, winner, loser, skillnum1, skillnum2, emap);

    //����
    QLabel* bkground = new QLabel(this);
    bkground->setFixedSize(1280, 960); bkground->move(0, 0);
    bkground->setPixmap(QPixmap(":/myres/score_bk.png")); bkground->show();

    //�����ǩ
    QLabel* result = new QLabel;   result->setParent(this); result->move(375, 145); result->setFixedSize(535, 145);
    result->setPixmap(QPixmap(":/battle/battle/ending.png"));
    
    //���������
    QTextBrowser* record = new QTextBrowser(this); record->move(140, 290); record->setFixedSize(1000, 400);
    QFont resfont("����", 18); record->setFont(resfont);
    QPalette pl = record->palette();//��ɫ�帺����ı����͸��
    pl.setBrush(QPalette::Base, QBrush(QColor(255, 0, 0, 0)));
    record->setPalette(pl);record->setStyleSheet("QTextBrowser{ border:0px; }");
    QString comment = QString("    ����������ʱΪ%1�롣ʤ��Ϊ%2,���ͷ���%3������,������Ϊ%4�����ͷ���%5�����ܡ�����ȡ���ʤ������!").arg(duration).arg(name[winner-1]).arg(skillnum1).arg(name[loser-1]).arg(skillnum2);
    record->setText(comment);

    //������
    QLabel* win_icon = new QLabel(this); win_icon->setFixedSize(318, 306);
    win_icon->setPixmap(QPixmap(":/battle/battle/win_icon.png")); win_icon->move(481, 400);

    //���߻���
    QLabel* fire1 = new QLabel(this); fire1->setFixedSize(255, 288);
    fire1->move(150, 370); QMovie* mov_fire1 = new QMovie(":/battle/battle/cv1.GIF");
    fire1->setMovie(mov_fire1); mov_fire1->start();
    QLabel* fire2 = new QLabel(this); fire2->setFixedSize(264, 359);
    fire2->move(930, 340); QMovie* mov_fire2 = new QMovie(":/battle/battle/cv2.GIF");
    fire2->setMovie(mov_fire2); mov_fire2->start();

    //�˳���Ϸ��ť
    btn_close = new myPushButton(":/battle/battle/btn_close.png"); btn_close->setParent(this);
    btn_close->move(50, 720);
    btn_close->setFixedSize(427, 120);
    connect(btn_close, &myPushButton::clicked, [=]() {
        btn_close->zoom(0, 10); btn_close->zoom(10, 0);
        QTimer::singleShot(800, [=]() {
            this->close();
            });
        });

    //���ز˵���ť
    btn_rtn = new myPushButton(":/battle/battle/btn_ret.png"); btn_rtn->setParent(this);
    btn_rtn->move(803, 720);btn_rtn->setFixedSize(427, 120);
    connect(btn_rtn, &myPushButton::clicked, [=]() {
        btn_rtn->zoom(0, 10); btn_rtn->zoom(10, 0);
        QTimer::singleShot(800, this, [=]() {
            this->hide();
            this->mainmenu->show();
            });
        });
}

void score::connect_mysql(int duration, int winner, int loser, int skillnum1, int skillnum2,int emap)
{
    //��ǰƴ�Ӻ�sql���
    char myquery[200];
    sprintf_s(myquery, "insert into battle (time,duration,map,winner,win_skill,loser,los_skill)"
        "value(now(),%d,\"%s\",\"%s\",%d,\"%s\",%d);", duration, map[emap - 1].c_str(), sql_name[winner - 1].c_str(),
        skillnum1, sql_name[loser - 1].c_str(), skillnum2);

    //��ʼ�����ݿ�
    MYSQL mysql;//���ݿ���
    mysql_init(&mysql);

    //�������ݿ�
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", "123456", "test", 3306, NULL, 0) == NULL)
    {
        printf("����ԭ�� :%s\n", mysql_error(&mysql));
        printf("����ʧ�ܣ�\n");
        exit(-1);
    }

    //ִ�����ݿ�������
    mysql_query(&mysql, myquery);

    //�ر����ݿ�
    mysql_close(&mysql);
}

score::~score()
{

}

#include "settingScene.h"

//����ҳ���������ҳ��
settingScene::settingScene(QWidget* parent)
{
	//���ڻ�������
    this->setFixedSize(1280, 960);
    setWindowIcon(QIcon(":/myres/good.png"));
    setWindowTitle("GYT's Battle Game");

    //���Ͻ�������䱳���ı�ǩ
    QLabel* bkgrounds = new QLabel(this);
    bkgrounds->setFixedSize(300, 128); bkgrounds->move(0, -10);
    bkgrounds->setPixmap(QPixmap(":/myres/menusmall.png")); bkgrounds->show();

    //����ͼ
    QLabel* bkground = new QLabel(this);
    bkground->setFixedSize(1280, 960); bkground->move(0, 0);
    bkground->setPixmap(QPixmap(":/myres/menu.png")); bkground->show();

    //�������˵��İ�ť
    rtbtn = new myPushButton(":/myres/rtbtn.png");
    rtbtn->setParent(this); rtbtn->move(0, 0); rtbtn->show();

    //�����ؼ�,Ĭ����ʾ
    vw = new volumeWidget(this);
    vw->move(280, 120); currentWidget = vw;

    //��ʷ��¼�ؼ���Ĭ������
    sw = new sqlWidget(this);
    sw->move(280, 120); sw->hide();

    //��Ϸ�����ؼ���Ĭ������
    cw = new creatorWidget(this);
    cw->move(280, 120); cw->hide();

    //����������İ�ť
    myPushButton* btn_setup = new myPushButton(":/myres/btn_setup.png");
    btn_setup->setParent(this); currentButton = btn_setup;currentWidget = vw;
    btn_setup->setFixedSize(514, 100); btn_setup->move(-200, 250);
    connect(btn_setup, &myPushButton::clicked, [=]() {
        if (currentButton->x() > -230)currentButton->zoom(0, -30, 0);
        if (currentWidget == vw)
        {
            if (currentButton->x() == -230)currentButton->zoom(0, 30, 0);
            vw->show();
            return;
        }
        else
        {
            if (btn_setup->x() != -200)
                btn_setup->zoom(0, 30, 0);
            currentButton = btn_setup;
            currentWidget->hide(); vw->show();
            currentWidget = vw;
        }
        });

    //����ʷ��¼ҳ��İ�ť��ť
    myPushButton* btn_history = new myPushButton(":/myres/btn_history.png");
    btn_history->setParent(this);
    btn_history->setFixedSize(514, 100); btn_history->move(-230, 450);
    connect(btn_history, &myPushButton::clicked, [=]() {
        if (currentButton->x() > -230)currentButton->zoom(0, -30, 0);
        if (currentWidget == sw)
        {
            if (currentButton->x() == -230)currentButton->zoom(0, 30, 0);
            sw->show();
            return;
        }
        else
        {
            if (btn_history->x() != -200)
                btn_history->zoom(0, 30, 0);
            currentButton = btn_history;
            currentWidget->hide(); sw->show();
            currentWidget = sw;
        }
        });

    //����Ϸ��������İ�ť
    myPushButton* btn_creator = new myPushButton(":/myres/btn_creator.png");
    btn_creator->setParent(this);
    btn_creator->setFixedSize(514, 100); btn_creator->move(-230, 650);
    connect(btn_creator, &myPushButton::clicked, [=]() {
        if (currentButton->x() > -230)currentButton->zoom(0, -30, 0);
        if (currentWidget == cw)
        {
            if (currentButton->x() == -230)currentButton->zoom(0, 30, 0);
            cw->show();
            return;
        }
        else
        {
            if (btn_creator->x() != -200)
                btn_creator->zoom(0, 30, 0);
            currentButton = btn_creator;
            currentWidget->hide(); cw->show();
            currentWidget = cw;
        }
        });

    //�ʼʱ�����������
    this->hide();
}

settingScene::~settingScene()
{

}

//�����ؼ�
volumeWidget::volumeWidget(QWidget* parent)
{
    //�ؼ���������
    this->setParent(parent);
    this->setFixedSize(1000, 860);

    //��ý���ʼ��
    player = new QMediaPlayer(this);
    //playlist->clear();
    //QStringList music = QStringList("");

    //"��������ǩ
    QLabel* lab_volume = new QLabel(this);
    lab_volume->setFixedSize(152, 80);
    lab_volume->move(140, 83);
    lab_volume->setPixmap(QPixmap(":/myres/lab_voltitle.png"));

    //�������Լ�������������������
    QSlider* slider_volume = new QSlider(this);
    slider_volume->setOrientation(Qt::Horizontal);//ˮƽ���û�����
    slider_volume->setMinimum(0);    // ��Сֵ
    slider_volume->setMaximum(100);  // ���ֵ
    slider_volume->setSingleStep(5); // ����
    slider_volume->setValue(50);     // ��ʼֵ
    slider_volume->setFixedSize(500, 56); slider_volume->move(350, 100);
    //���û�������ʽ
    QString slider_style = QString("QSlider::groove:horizontal{"
        "border: 0px;"
        "image: url(:/myres/lab_volume.png);"
        "margin: 0px 0;}" 
    "QSlider::handle:horizontal{"
        "border: 0px;"
        "image: url(:/myres/lab_volblock.png);"
        "margin: 0px 0;}"
    );
    slider_volume->setStyleSheet(slider_style);
    //�������ı���������
    connect(slider_volume, &QSlider::valueChanged, [=](){
        player->setVolume(slider_volume->value());
        });
}

volumeWidget::~volumeWidget()
{

}

//��ʷ��¼�ؼ�
sqlWidget::sqlWidget(QWidget* parent)
{
    //�ؼ���������
    this->setParent(parent);
    this->setFixedSize(1000, 860);

    //����
    QLabel* bg = new QLabel(this); bg->setFixedSize(1000, 840);
    bg->setPixmap(QPixmap(":/myres/bg_sql.png"));

    //���ݿ�����
    connect_mysql();

    //���������
    QTextBrowser* record = new QTextBrowser(this); record->move(80, 100); record->setFixedSize(900, 740);
    QFont resfont("����", 14); record->setFont(resfont);
    QPalette pl = record->palette();//��ɫ�帺����ı����͸��
    pl.setBrush(QPalette::Base, QBrush(QColor(255, 0, 0, 0)));
    record->setPalette(pl); record->setStyleSheet("QTextBrowser{ border:0px; }");//ֱ��qml���ȥ���߿�
    QString history = QString(*sqlresult);
    record->setText(history.toUtf8());
}

sqlWidget::~sqlWidget()
{

}

void sqlWidget::connect_mysql()
{
    MYSQL mysql;//���ݿ���
    MYSQL_RES* res;//��ѯ�����
    MYSQL_ROW  row;//��¼�ṹ��
        //��ʼ�����ݿ�
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", "123456", "test", 3306, NULL, 0) == NULL)//�������ݿ�
    {
        printf("misson fail!\n");
        exit(-1);
    }

    int retn = mysql_set_character_set(&mysql, "utf8");//����mysql���ַ���ʽΪutf8
    int ret = mysql_query(&mysql, "select time,duration,map,winner,win_skill,loser,los_skill from battle;");//��ȡ�����
    printf("ret: %d\n ", ret);

    res = mysql_store_result(&mysql);//�Ѳ�ѯ���������������Ϊ�����ֻ��һ��������ֻ�ܲ�ѯһ�Σ�����������ϵ�

    string str;

    while (row = mysql_fetch_row(res))//�����ݿ�ÿһ�е����ݴ���str��
    {
        str += row[0]; str += "  ";
        str += row[1]; 
        for(int j = 0; j < 6 - strlen(row[1]); j++)str += " ";
        str += row[2];
        for (int j = 0; j < 12 - strlen(row[2]) / 3 * 2; j++)str += " ";
        str += row[3];
        for (int j = 0; j < 12 - strlen(row[2]) / 3 * 2; j++)str += " ";
        str += row[4];
        for (int j = 0; j < 6 - strlen(row[4]); j++)str += " ";
        str += row[5]; 
        for (int j = 0; j < 12 - strlen(row[2]) / 3 * 2; j++)str += " ";
        str += row[6];
        for (int j = 0; j < 6 - strlen(row[6]); j++)str += " ";
        /*
             for (int i = 0; i < 7; i++)
        {
            str += row[i];
            if (i != 2 && i != 3 && i != 5)//�жϸ����ǲ��Ǻ��֣���Ϊutf-8�Ժ��ֵĴ��������̱
            {
                for (int j = 0; j < 11 - strlen(row[i]); j++)
                    str += " ";
            }
            else
            {
                //utf-8��ʽ�ĵ���̱���ڣ������ַ�����Ϊ3������ʾ����Ϊ2��Ҳ����˵�����麣����strlenΪ9��
                //������ʾʱռ6�����ӣ�������ʾ�������ַ����ȳ���1.5���������̫�����
                for (int j = 0; j < 8 - strlen(row[i]) / 3 * 2; j++)
                    str += " ";
            }
        }
        */
        str += "\n";
    }

    sqlresult = new QString(str.c_str());

    mysql_free_result(res);//�ͷŽ����
    mysql_close(&mysql);//�ر����ݿ�
}

//�����߿ؼ�
creatorWidget::creatorWidget(QWidget* parent)
{
    //�ؼ���������
    this->setParent(parent);
    this->setFixedSize(1000, 860);

    //���Ա�ʶ
    QLabel* mark2 = new QLabel(this); mark2->setFixedSize(200, 200);
    mark2->setPixmap(QPixmap(":/myres/yang.png"));
}

creatorWidget::~creatorWidget()
{

}
#include "settingScene.h"

//设置页面的主背景页面
settingScene::settingScene(QWidget* parent)
{
	//窗口基本参数
    this->setFixedSize(1280, 960);
    setWindowIcon(QIcon(":/myres/good.png"));
    setWindowTitle("GYT's Battle Game");

    //左上角用于填充背景的标签
    QLabel* bkgrounds = new QLabel(this);
    bkgrounds->setFixedSize(300, 128); bkgrounds->move(0, -10);
    bkgrounds->setPixmap(QPixmap(":/myres/menusmall.png")); bkgrounds->show();

    //背景图
    QLabel* bkground = new QLabel(this);
    bkground->setFixedSize(1280, 960); bkground->move(0, 0);
    bkground->setPixmap(QPixmap(":/myres/menu.png")); bkground->show();

    //返回主菜单的按钮
    rtbtn = new myPushButton(":/myres/rtbtn.png");
    rtbtn->setParent(this); rtbtn->move(0, 0); rtbtn->show();

    //音量控件,默认显示
    vw = new volumeWidget(this);
    vw->move(280, 120); currentWidget = vw;

    //历史记录控件。默认隐藏
    sw = new sqlWidget(this);
    sw->move(280, 120); sw->hide();

    //游戏制作控件，默认隐藏
    cw = new creatorWidget(this);
    cw->move(280, 120); cw->hide();

    //打开音量界面的按钮
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

    //打开历史记录页面的按钮按钮
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

    //打开游戏制作界面的按钮
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

    //最开始时隐藏这个窗口
    this->hide();
}

settingScene::~settingScene()
{

}

//音量控件
volumeWidget::volumeWidget(QWidget* parent)
{
    //控件基本参数
    this->setParent(parent);
    this->setFixedSize(1000, 860);

    //多媒体初始化
    player = new QMediaPlayer(this);
    //playlist->clear();
    //QStringList music = QStringList("");

    //"音量“标签
    QLabel* lab_volume = new QLabel(this);
    lab_volume->setFixedSize(152, 80);
    lab_volume->move(140, 83);
    lab_volume->setPixmap(QPixmap(":/myres/lab_voltitle.png"));

    //滑动条以及滑动条与音量的连接
    QSlider* slider_volume = new QSlider(this);
    slider_volume->setOrientation(Qt::Horizontal);//水平放置滑动条
    slider_volume->setMinimum(0);    // 最小值
    slider_volume->setMaximum(100);  // 最大值
    slider_volume->setSingleStep(5); // 步长
    slider_volume->setValue(50);     // 初始值
    slider_volume->setFixedSize(500, 56); slider_volume->move(350, 100);
    //设置滑动条样式
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
    //滑动条改变音量功能
    connect(slider_volume, &QSlider::valueChanged, [=](){
        player->setVolume(slider_volume->value());
        });
}

volumeWidget::~volumeWidget()
{

}

//历史记录控件
sqlWidget::sqlWidget(QWidget* parent)
{
    //控件基本参数
    this->setParent(parent);
    this->setFixedSize(1000, 860);

    //背景
    QLabel* bg = new QLabel(this); bg->setFixedSize(1000, 840);
    bg->setPixmap(QPixmap(":/myres/bg_sql.png"));

    //数据库连接
    connect_mysql();

    //文字浏览器
    QTextBrowser* record = new QTextBrowser(this); record->move(80, 100); record->setFixedSize(900, 740);
    QFont resfont("楷体", 14); record->setFont(resfont);
    QPalette pl = record->palette();//调色板负责把文本框搞透明
    pl.setBrush(QPalette::Base, QBrush(QColor(255, 0, 0, 0)));
    record->setPalette(pl); record->setStyleSheet("QTextBrowser{ border:0px; }");//直接qml语句去除边框
    QString history = QString(*sqlresult);
    record->setText(history.toUtf8());
}

sqlWidget::~sqlWidget()
{

}

void sqlWidget::connect_mysql()
{
    MYSQL mysql;//数据库句柄
    MYSQL_RES* res;//查询结果集
    MYSQL_ROW  row;//记录结构体
        //初始化数据库
    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", "123456", "test", 3306, NULL, 0) == NULL)//连接数据库
    {
        printf("misson fail!\n");
        exit(-1);
    }

    int retn = mysql_set_character_set(&mysql, "utf8");//设置mysql的字符格式为utf8
    int ret = mysql_query(&mysql, "select time,duration,map,winner,win_skill,loser,los_skill from battle;");//获取结果集
    printf("ret: %d\n ", ret);

    res = mysql_store_result(&mysql);//把查询结果存入结果集，因为结果集只有一个，所有只能查询一次，否则会引发断点

    string str;

    while (row = mysql_fetch_row(res))//把数据库每一行的数据存入str中
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
            if (i != 2 && i != 3 && i != 5)//判断该列是不是汉字，因为utf-8对汉字的处理过于脑瘫
            {
                for (int j = 0; j < 11 - strlen(row[i]); j++)
                    str += " ";
            }
            else
            {
                //utf-8格式的的脑瘫在于，汉字字符长度为3，但显示长度为2，也就是说“孔祥海”的strlen为9，
                //但是显示时占6个格子，所以显示长度是字符长度除以1.5，这可真是太杨豪了
                for (int j = 0; j < 8 - strlen(row[i]) / 3 * 2; j++)
                    str += " ";
            }
        }
        */
        str += "\n";
    }

    sqlresult = new QString(str.c_str());

    mysql_free_result(res);//释放结果集
    mysql_close(&mysql);//关闭数据库
}

//创作者控件
creatorWidget::creatorWidget(QWidget* parent)
{
    //控件基本参数
    this->setParent(parent);
    this->setFixedSize(1000, 860);

    //调试标识
    QLabel* mark2 = new QLabel(this); mark2->setFixedSize(200, 200);
    mark2->setPixmap(QPixmap(":/myres/yang.png"));
}

creatorWidget::~creatorWidget()
{

}
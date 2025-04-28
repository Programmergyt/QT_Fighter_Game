#include <iostream>
#include<cstdio>
#include<mysql.h>
using namespace std;
int main()
{
    MYSQL mysql;//数据库句柄
    MYSQL_RES* res;//查询结果集
    MYSQL_ROW row;//记录结构体
    char s[14][7][30];//将数据库内的数据打印到该数组中

    mysql_init(&mysql);//初始化数据库
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", "123456", "test", 3306, NULL, 0) == NULL)//连接数据库
    {
        printf("错误原因 :%s\n", mysql_error(&mysql));
        printf("连接失败！\n");
        exit(-1);
    }
    int ret = mysql_query(&mysql, "select * from student order by score desc;");//获取结果集
    printf("ret: %d\n ", ret);

    res = mysql_store_result(&mysql);//存入结果集

    while (row = mysql_fetch_row(res))//直接打印row版
    {
        printf("%-8s  ", row[0]);//逐个打印字段
        printf("%-8s  ", row[1]);
        printf("%-8s  ", row[2]);
        printf("%-8s  ", row[3]);
        printf("%-8s  ", row[4]);
        printf("%-8s  ", row[5]);
        printf("%-8s  ", row[6]);
        printf("%-8s \n ", row[7]);
    }  
   
    /*
    int i = 0;
    while (row = mysql_fetch_row(res))//间接打row版
    {
        sprintf_s(s[i][0], "%s", row[0]);//逐个打印字段
        sprintf_s(s[i][1], "%s", row[1]);
        sprintf_s(s[i][2], "%s", row[2]);
        sprintf_s(s[i][3], "%s", row[3]);
        sprintf_s(s[i][4], "%s", row[4]);
        sprintf_s(s[i][5], "%s", row[5]);
        sprintf_s(s[i][6], "%s", row[6]);
        i++;//接着sprintf下一个数据对象
    }
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 7; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }//打印结果
    */
    
    
    mysql_free_result(res);//释放结果集
    
    mysql_close(&mysql);//关闭数据库
    system("pause");
    cout << "Hello World!\n";
}


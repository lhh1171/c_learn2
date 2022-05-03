
 Created by lqc on 2022/5/3.

#include <iostream>
#include<iostream>
#include<string>
#include<mysql/mysql.h>
using namespace std;

class MyDB
{
public:
    MyDB();
    ~MyDB();
    bool initDB(string host,string user,string pwd,string db_name); //连接mysql
    bool exeSQL(string sql);                                       //执行sql语句
private:
    MYSQL *mysql;                                                  //连接mysql句柄指针
    MYSQL_RES *result;    //指向查询结果的指针
    MYSQL_ROW row;       //按行返回的查询信息
};
MyDB::MyDB()
{
    mysql=mysql_init(NULL);   //初始化数据库连接变量
    if(mysql==NULL)
    {
        cout<<"Error:"<<mysql_error(mysql);
        exit(1);
    }
}

MyDB::~MyDB()
{
    if(mysql!=NULL)  //关闭数据连接
    {
        mysql_close(mysql);
    }
}


bool MyDB::initDB(string host,string user,string passwd,string db_name)
{
    // 函数mysql_real_connect建立一个数据库连接
    // 成功返回MYSQL*连接句柄，失败返回NULL
    mysql = mysql_real_connect(mysql, host.c_str(), user.c_str(), passwd.c_str(), db_name.c_str(), 0, NULL, 0);
    if(mysql == NULL)
    {
        cout << "Error: " << mysql_error(mysql);
        exit(1);
    }
    return true;
}

bool MyDB::exeSQL(string sql)
{
    //mysql_query()执行成功返回0,执行失败返回非0值。
    if (mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<mysql_error(mysql);
        return false;
    }
    else // 查询成功
    {
        result = mysql_store_result(mysql);  //获取结果集
        if (result)  // 返回了结果集
        {
            int  num_fields = mysql_num_fields(result);   //获取结果集中总共的字段数，即列数
            int  num_rows=mysql_num_rows(result);//获取结果集中总共的行数

            for(int i=0;i<num_rows;i++) //输出每一行
            {
                //获取下一行数据
                row=mysql_fetch_row(result);
//                //主键的值，这里指的是id
//                cout<<**row<<endl;
                if(**row<0) break;
                for(int j=0;j<num_fields;j++)  //输出每一字段
                {
                    cout<<row[j];
                }
                cout<<endl;
            }
        }
        else  // result==NULL
        {
            if(mysql_field_count(mysql) == 0)   //代表执行的是update,insert,delete类的非查询语句
            {
                // (it was not a SELECT)
                int num_rows = mysql_affected_rows(mysql);  //返回update,insert,delete影响的行数
            }
            else // error
            {
                cout<<"Get result error: "<<mysql_error(mysql);
                return false;
            }
        }
    }
    return true;

}




int main()
{
    MyDB db;
    //连接数据库
    db.initDB("localhost","root","root","test");
//    db.exeSQL("INSERT INTO t_user(id,username, password, realname) VALUES(999,'12349', '姚明39', '2539');");
//    //将所有用户信息读出，并输出。
    db.exeSQL("select * from t_user;");
    return 0;
}



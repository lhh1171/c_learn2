//
// Created by lqc on 2022/5/3.
//

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>
#include<mysql/mysql.h>
#include <thread>

using namespace std;
void dd(off_t offset,int fd,int position,string str){
      offset = lseek(fd, position, SEEK_SET);
      write(fd, str.c_str(), str.length());
}
int hole_test(MYSQL_RES *result,int num_rows,int  num_fields,char **row){
    int fd;
    off_t offset;
    fd = creat("/home/lqc/文档/tmp.csv", 0777);   //创建一个权限为可读可写可执行的文件"tmp"
    if(-1 == fd){   //如果出错返回-1
        perror("creat");
        return -1;
    }
    MYSQL_FIELD *field;
    int position=0;
    offset = lseek(fd, position, SEEK_SET);
    while((field = mysql_fetch_field(result)))
    {
        string ss=field->name;
        ss.append(",");
        write(fd, ss.c_str(), ss.length());
        position+=ss.length();
        offset = lseek(fd, position, SEEK_SET);
    }
    offset = lseek(fd, position-1, SEEK_SET);
    write(fd, "\n", 1);
    //for循环里面可以开多线程
    for(int i=0;i<num_rows;i++) //输出每一行
    {
        position+=100;
        //获取下一行数据
        row=mysql_fetch_row(result);
        if(**row<0) break;
        string str;
        for(int j=0;j<num_fields;j++)  //输出每一字段
        {
            //加 ,
            str.append(row[j]).append(",");
        }
        //加 \n
        str = str.substr(0, str.length() - 1);
        str.append("\n");
        try {
            thread t(dd,offset,fd,position,str);
            t.detach();
        } catch (const exception& e) {
            cerr << "EXCEPTION: " << e.what() << endl;
        }
        cout<<str;
    }
    cin.get();
    close(fd);   //关闭文件描述符
    return 0;
}



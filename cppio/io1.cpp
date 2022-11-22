

#include <fstream>
#include <zconf.h>
#include <iostream>

using namespace std;
/*
ios::in	打开一个可读取文件
ios::out	打开一个可写入文件
ios::app	你写入的所有数据将被追加到文件的末尾，此方式使用ios::out
ios::ate	你写入的所有数据将被追加到文件的末尾，此方式不使用ios::out
ios::trunk	删除文件原来已存在的内容（清空文件）
ios::binary	以二进制的形式打开一个文件。
 */
int cppio1()
{
    cout<<"xxx"<<endl;
    ofstream file("/opt/xxx", ios::ate);
    file << "Hello World, fromwww.cpp-home.com and Loobian!";
//    file.flush();
    _exit(0);
//    file.close();
    return 0;
}
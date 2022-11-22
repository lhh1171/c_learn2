
#include <fstream>
#include <iostream>
using namespace std;
int byteio1()
{
    fstream file("/opt/xxx",ios::out | ios::in | ios::binary);
    char ch;
    ch='o';
    file.put(ch); //将ch的内容写入文件
    file.sync();//同步写入磁盘
    file.seekg(ios::beg);//定位至文件首部
    file.get(ch); //读出一个字符
    cout << ch << endl;//将其显示在屏幕上

    file.close();
    return 0;
}
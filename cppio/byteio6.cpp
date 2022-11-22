
#include <fstream>
#include <iostream>
#include <string.h>
#include <zconf.h>
#include <stdlib.h>

using namespace std;
int byteio6()
{
    ofstream File;

    File.open("/opt/xxxy"); //创建一个文件
    File.close();

    cin.get();

    unlink("/opt/xxxy"); //删除这个文件

    //试图打开此文件，但假如它已不存在
    //函数将返回一个ios::failbit错误值
    File.open("/opt/xxxy",ios::in);

    //验证它是否返回该值
    if(File.rdstate() == ios::failbit)
        cout << "Error...!/n"; //耶，成功了

    File.close();
    return 0;
}
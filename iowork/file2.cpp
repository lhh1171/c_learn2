//
// Created by lqc on 2022/5/3.
//

#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
int byteio2()
{
    fstream file("/home/lqc/文档/sss.csv",ios::out | ios::in | ios::binary);
    char arr[20];
    string ss="id,name\n2002,xxx";
    strcpy(arr,ss.c_str());//将Hello World!存入数组

    //不要往后多写会乱码
    file.write(arr,ss.length());//将前5个字符——"Hello"写入文件

    file.close();
    return 0;
}
//int main(){
//    byteio2();
//}
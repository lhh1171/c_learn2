#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include<iostream>
#include <cstring>

using namespace std;

/*
 * mode参数
"r"	只读,文件必须已存在
"w" 只写,如果文件不存在则创建,如果文件已存在则把文件长度截断(Truncate)为0字节再重
新写,也就是替换掉原来的文件内容
"a" 只能在文件末尾追加数据,如果文件不存在则创建
"r+" 允许读和写,文件必须已存在
"w+" 允许读和写,如果文件不存在则创建,如果文件已存在则把文件长度截断为0字节再重新写
"a+" 允许读和追加数据,如果文件不存在则创建
 */

int io1()
{
    FILE *fp = fopen("aaa", "r");
    if (fp == NULL) {
        perror("error!!!!!");
        cout<<strerror(errno)<<"\t"<<errno<<endl;
//        cerr<<strerror(errno)<<"\t"<<errno<<endl;
        exit(2);
    }
    int res=fclose(fp);
    if(res<0){
        perror("error!!!!!");
        cout<<strerror(errno)<<"\t"<<errno<<endl;
        exit(2);
    }
    cout<<"ok"<<endl;
    return 0;
}

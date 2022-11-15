#include<iostream>
#include<string>
#include <cstring>

using namespace std;
int str(){
//    char str[] = "I am a programmer." ;//str 是一个字符数组
//    char * str1="abc"; //str1是一个字符指针变量，可以指向一个字符串   [-Wwrite-strings]
//    char * str2[]={"hello world","good bye"};  //str2是一个字符指针数组，可以存多个字符串

    string str4[]={"I am a programmer.","adfadfadsf"} ;

    string str3 = "I am a programmer, too.";  // str3是一个字符串变量
//    cout<<"str: "<<str<<endl;
//    cout<<"str1: "<<str1<<endl;
//    cout<<"str2[0]: "<<str2[0]<<endl;
    cout<<"str3: "<<str3<<endl;

    const char* strchar=str3.c_str();
    cout<<strchar[0]<<endl;
    cout<<strchar+2<<endl;

    char *buf = new char[strlen(strchar)+1];
    strcpy(buf, strchar);
    cout<<buf<<endl;
    cout<<++buf<<endl;

    const char * strr="abcdefg";
    char *buf1 = new char[2];
    strcpy(buf1, strr);
    buf1+=2;
    cout<<buf1<<endl;
    return 0;
}

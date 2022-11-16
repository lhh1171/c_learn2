#include <string>
#include <sstream>
#include<iostream>
#include <cstring>

using namespace std;
int strint()
{
//    string mystr="12";
//    const char * s=mystr.c_str();
//    char *src=(char *)malloc(mystr.length());
//    strcpy(src,s);
//
//    string str22=src;
    // int 转 string
    stringstream ss;
    int n = 123;
    string str;
    ss<<n;
    ss>>str;
    ss.clear();

    cout<<str+"aaa"<<endl;

    string str1="1000";
    int n1=0;
    ss<<str1;
    ss>>n1;
    ss.clear();
    cout<<n1+1<<endl;

    string sstr="abc";
    char *p=(char *)malloc(sizeof(4));
//    ss<<sstr;
//    ss>>p;
    strcpy(p,sstr.c_str());
    cout<<p<<endl;


    // string 转 int
//    str = "456";
//    n = atoi(str.c_str());
////    itoa()
//    cout<<n+1<<endl;
    return 0;
}

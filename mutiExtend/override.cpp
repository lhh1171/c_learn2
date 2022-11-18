//
// Created by lqc on 2022/11/18.
//
#include <stdio.h>
#include <iostream>
using namespace std;
class pp{
public:
    int id{};
    //在xxx() 后面加final 不允许继承
    virtual void xxx()  {
        cout<<"xxxx"<<endl;
    };
};

class stu: public pp{
    //提示加virtual
    void xxx() override {
        cout<<"override xxxx"<<endl;
    }
};

template <class T,int size>
void xxy(T (&t)[size]){
    for (T x:t) {
        cout<<x<<endl;
    }
    cout<<size<<endl;
}

void mm(){
    int arr[]={1,2,3,4,5};
    xxy(arr);
}

void cast(){
    double a=1.1;
    int b= static_cast<int>(a);
    cout<<b<<endl;
    stu s;
    pp *pp= dynamic_cast<class pp*>(&s);

    int c=1;
    int *ptr=&c;
    long l= reinterpret_cast<long>(ptr);\

    //当右边不在只读数据段中
    const char *str="abc";
    char *pstr= const_cast<char *>(str);
    *pstr='c';
    cout<<(char)*pstr<<endl;
}
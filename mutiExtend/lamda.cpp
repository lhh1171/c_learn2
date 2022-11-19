//
// Created by lqc on 2022/11/19.
//

#include <stdio.h>
#include <iostream>
using namespace std;
using Fun=int(*)(int,int);
int xxx(Fun f,int a,int b){
    return f(a,b);
}
void lm(){
    int c=1;
    //[=]表示值传递，只读传递，没有c也可以访问c
    auto f=[=](int a,int b){
        return a+b+c;
    };

    //全部传入
    auto f1=[&](int a,int b){
        c=12;
        return a+b+c;
    };

    //指定一个
    auto f2=[&c](int a,int b){
        c=12;
        return a+b+c;
    };

    //传入指针
    int *d=&c;
    auto f3=[d](int a,int b){
        *d=12;
        return a+b+d;
    };

    //组合
    auto f4=[=,&c](int a,int b){
        *d=12;
        return a+b+c+d;
    };

    //lamda表达式入参
    int res=xxx([](int a,int b){return a+b;},1,4);
    cout<<f(1,2)<<endl;
}
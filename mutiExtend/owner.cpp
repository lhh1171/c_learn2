//
// Created by lqc on 2022/11/18.
//
//将亡值
#include <stdio.h>
#include <iostream>
using namespace std;
void own(){
//     const int a=0x61;//相当于 #define a 0x61
//     //常量可以，变量不行
//     const int &aa=0x61;
//     const int &b=a;
//    //使用权转移
//    int &&b=0x61;
//    b=0x62;
//    cout<<b<<endl;

////左值转将亡值--》右值
//int a=1;
//int &&b= static_cast<int>(a);
//b=0x62;
//cout<<a<<endl;


//右值转将亡值--》左值
int a=1;
int b= static_cast<int>(1);
b=0x62;
cout<<a<<endl;

//取消使用权,按理来说a用不了
//    int a=1;
//    int &&b=move(a);
//    b=0x62;
//    cout<<a<<endl;
//    cout<<b<<endl;
 }
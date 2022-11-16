//
// Created by andilyliao on 2021/6/21.
//

#include<iostream>
using namespace std;
class classbitdomain{//0110000 1--->0x61
public:
    char a:1;
    char b:7;
}__attribute__((packed));
int classtest6(){

    classbitdomain bit;
    bit.a=0x01;
    bit.b=0x30;
    char *ptr=(char *)&bit;
    cout<<*ptr<<endl;
    return 0;
}
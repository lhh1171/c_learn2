//
// Created by lqc on 2022/11/19.
//
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

//int xxx(const int *ptr){
//    int *p=(int *)malloc(4);
//    memset(p,1,4);
//    ptr=p;
////    *ptr=2;
//    return 0;
//}

//写不写都一样
const int xxx(){
    int *p=(int *)malloc(4);
    memset(p,1,4);
    return *p;
}

class person{
    mutable int i;
public:
    void setI(int ii)const {
        //i不加mutable改不了
        this->i=ii;
    }
    int& getI()  {
        return this->i;
    }
};

//class person{
//    int i;
//public:
//    void setI(int ii){
//        this->i=ii;
//    }
//    const int& getI() const {
//        show();
//        return this->i;
//    }
//    void show() const {
//        cout<< this->i<<endl;
//    }
//};
void cm(){
//    int a=1;
//    int &&p=xxx();
    person p;
    p.getI()=2;
    cout<<p.getI()<<endl;
}
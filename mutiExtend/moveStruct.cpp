//
// Created by lqc on 2022/11/18.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class person{
public:
    char * i="9999";
    person(){
        cout<<"构造"<<endl;
    }

    ~person(){
        cout<<"~person"<<endl;
    }

    person(person& p){
        this->i=p.i;
        cout<<"copy"<<endl;
    }

    person(person &&p){
        this->i=p.i;
        p.i=0;
        cout<<"使用权转移"<<endl;
    }
};



person&& transform(person &&p){
    cout<<"=========="<<endl;
    return move(p);
}

template <class T>
T&& xxx(T&& t){
    return forward<T&&>(t); //万能转发使用权
}
int mmm(){
    person p1;
//    //move的底层就是static_cast<type&&>(__t);
//    person &&p2=transform(move(p1));
//    cout<<p1.i<<endl;


    person p2=xxx(p1);
    person &&p3=xxx(move(p1));//万能引用

}
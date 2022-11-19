//
// Created by lqc on 2022/11/19.
//


#include <stdio.h>
#include <iostream>
using namespace std;

auto  plus1(int a,int b)->int {
    return a+b;
}

template <class T,class U>
auto plus2(T a,U b)->decltype(a+b){
    return a+b;
}

using Fun  =int(*)(int,int);
//Fun xxxx(){
//    return plus1;
//}
//auto xxxx()->Fun {
//    return plus1;
//}
auto xxxx()->int(*)(int,int){
    return plus1;
}

void fm(){
    cout<<plus2(1,2.2f)<<endl;
    cout<<
    typeid(plus2(1,2)).name()<<endl;
    cout<<xxxx()(1,2)<<endl;
}
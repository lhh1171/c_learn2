//
// Created by andilyliao on 18-12-5.
//
#include<iostream>
#include <typeinfo>
#include<vector>
#include <cstring>
using namespace std;

//=======================template新特性１=======================

//在模板定义语法中关键字class与typename的作用完全一样。
//template<typename T> == template<class T>


//===================typename可以独立使用===============================
template <typename TP>
class COne {
public:
    typedef TP one_value_type;
};
template <typename COne>   // 用一个模板类作为模板参数
class CTwo {
public:
    // typedef COne::one_value_type  two_value_type;
    typedef typename COne::one_value_type  two_value_type;
};
// 以上两个模板类只是定义了两个内部的public类型, 但请注意第二个类CTwo的two_value_type类型
// 依赖COne的one_value_type, 而后者又取决于COne模板类实例化时传入的参数类型.
//===================================================

template<typename T, int size>
int asz(T (&)[size]) {
    return size;
}

//===================================================

int tmplate11() {
    typedef COne<int> OneInt_type;
    typedef CTwo< OneInt_type > TwoInt_type;
    TwoInt_type::two_value_type i;
    int j;
    cout<<typeid(i).name()<<"\t"<<typeid(j).name()<<endl;
    if ( typeid(i).name() == typeid(j).name() ) {   // 如果i是int型变量
        cout << "Right!" << endl;   // 打印Right
    }
    cout<<"==================================="<<endl;
    //==========================================
    int arr[30];
    cout << asz(arr) << endl;
    string strArr[15];
    cout << asz(strArr) << endl;
    return 0;
}

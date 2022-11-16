//
// Created by andilyliao on 16-11-4.
//
//C++ 编译器可以将一个函数进行内联编译 被 C++ 编译器内联编译的函数叫做内联函数
//内联函数在最终生成的代码中是没有定义的
//C++ 编译器直接将函数体插入函数调用的地方
//内联函数没有普通函数调用时的额外开销 ( 压栈，跳转，返回 )
//现代 C++ 编译器能够进行编译优化，因此一些函数即使没有 inline 声明，也可能被编译器内联编译
#include<iostream>

using namespace std;

#define MYFUNC(a, b) ((a) < (b) ? (a) : (b))

inline int myfunc(int a, int b)
{
    return a < b ? a : b;
}

int inline1()
{
    int a = 1;
    int b = 3;
    int c = myfunc(++a, b);
//    int c=0;
//    {
//        int a1=++a;
//        int b1=b;
//        c= a1 < b1 ? a1 : b1;
//    }
    int c1 = MYFUNC(++a, b);//((++a)<(b)?(++a):(b))-->2<b?3:3 //由于替换过程的原因，导致运算实际是错误的
    //((++a) < (b) ? (++a) : (b))
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
    return 0;
}

//C++ 中内联编译的限制：
//不能存在任何形式的循环语句
//不能存在过多的条件判断语句
//函数体不能过于庞大
//不能对函数进行取址操作
//函数内联声明必须在调用语句之前
//
// Created by andilyliao on 16-10-31.
//
/*
 * 四个针对语言级提供的抛出异常，分别为bad_alloc、bad_cast、bad_typeid以及bad_exception；
 * 另外四个为C++标准库抛出的异常，分别是out_of_range、invalid_argument、overflow_error以及ios_base::failure
 */

//1. bad_alloc bad_alloc针对C++中动态存储分配new的操作提供的异常信号，主要针对分配内存空间时内存耗尽（分配不足）时抛出的异常。
//2. bad_cast C++多态提供的dynamic_cast应用于指针类型时，通常需要考虑指针各类异常的情况。
//3. bad_typeid bad_typeid是针对dynamic_cast操作空指针抛出的异常。
//4. bad_exception 当应用程序出现了无法catch捕获的异常情况时，通常会调用terminate终止程序。而使用bad_exception时，出现类似情况则会抛出bad_exception异常，用来替代终止程序。
//5. out_of_range表示操作数组等结构下标时，访问超过设定范围所抛出的异常。它主要针对容器中at()方法与重载的下标访问运算符两类方法。
//6. invalid_argument则表示向函数传递无效参数时抛出的异常，开发者可以针对该类抛出的异常作出相应的处理。
//7. overflow_error表示运算时候发生的上溢情况抛出的异常。
//8. ios_base::failure则是针对输出输入流操作时抛出的异常。
#include <iostream>
using namespace std;
int bad_allocExp()
{
    try
    {
        new char[10000000000000];             //通过new开辟一个超大的内存空间
        //
    }catch(bad_alloc &e)
    {
        cout<<"memoryerror!"<<endl;
        cout<<e.what()<<endl;
    }
    cout<<"aaaa"<<endl;
    return 0;
}


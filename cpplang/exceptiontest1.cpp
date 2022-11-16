//
// Created by andilyliao on 16-10-31.
//
#include<iostream>     //包含头文件
#include<stdlib.h>
using namespace std;

int fuc(double x, double y) throw (int) //定义函数
{
    if (y == 0) {
        throw 255;     //除数为0，抛出异常
    }
    return x / y;     //否则返回两个数的商
}

int exceptiontest1() {
    double res;
    try                 //定义异常
    {
//        res = fuc(2, 3);
//        cout << "The result of x/y is : " << res << endl;
        res = fuc(4, 0);//出现异常，函数内部会抛出异常
        cout << "The result of x/y is : " << res << endl;
    }
    catch (int d)             //捕获并处理异常
    {
        cerr <<"param 2 is: "<<d<<"! error of dividing zero./n";
        exit(1);                //异常退出程序
    }catch(...)                                                                                      //捕获所有异常处理
    {
        cout<<"allexception!"<<endl;
    }
    return 0;
}


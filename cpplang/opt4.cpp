//
// Created by andilyliao on 16-10-31.
//
//有一个Time类，包含数据成员minute(分)和sec(秒)，模拟秒表，每次走一秒，满60秒进一分钟，此时秒又从0开始算。要求输出分和秒的值。

#include <iostream>

using namespace std;

class Time {
public:
    Time() {
        this->minute = 0;
        this->sec = 0;
    }

    Time(int m, int s) : minute(m), sec(s) {}

    Time operator++(); //声明前置自增运算符“++”重载函数
    Time operator++(int); //声明后置自增运算符“++”重载函数
    void display() { cout << this->minute << ":" << this->sec << endl; }

private:
    int minute;
    int sec;
};

Time Time::operator++() //定义前置自增运算符“++”重载函数
{
    if ((++(this->sec)) >= 60) {
        this->sec -= 60;
        ++(this->minute);
    }
    return *this;     //返回自加后的当前对象
}

Time Time::operator++(int) //定义后置自增运算符“++”重载函数
{
    (this->sec)++;
    if (this->sec >= 60) {
        this->sec -= 60;
        ++(this->minute);
    }
    return *this; //返回的是自加前的对象
}


int opt4() {
    Time time1(34, 59), time2;
    cout << " time1 : ";
    time1.display();
    ++time1;

    cout << "++time1: ";
    time1.display();
    time2 = time1++;        //将自加前的对象的值赋给time2
    cout << "time1++: ";
    time1.display();
    cout << " time2 :";
    time2.display();               //输出time2对象的值

    time1.operator++();
    time1.operator++(1);
}

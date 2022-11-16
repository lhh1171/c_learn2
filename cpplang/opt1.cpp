//
// Created by andilyliao on 16-10-31.
//
//重载运算符“+”，使之能用于两个复数相加
//c++不可以重载?: 以及sizeof 运算符
#include <iostream>

using namespace std;

class Complex {
public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex &c2);       //声明重载运算符的函数   c3=c1.+(c2)
    void display();

private:
    double real;
    double imag;
};

Complex Complex::operator+(Complex &c2) //定义重载运算符的函数
{
    Complex c;
    c.real = this->real + c2.real;
    c.imag = this->imag + c2.imag;
    return c;
}

void Complex::display()
{
    cout << "(" << real << "," << imag << "i)" << endl;
}

int opt1() {
    Complex c1(3, 4), c2(5, -10), c3,c4;
    c3 = c1 + c2;
    //运算符+用于复数运算
    int aaaa=1 + 1;
    c4=c1.operator+(c2);
    cout << "c1=";
    c1.display();
    cout << "c2=";
    c2.display();
    cout << "c1+c2=";
    c3.display();

    cout << "real c1+c2=";
    c4.display();
    return 0;
}



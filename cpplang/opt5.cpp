//
// Created by andilyliao on 16-10-31.
//
//用重载的“<<”输出复数
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

    Complex operator+(Complex &c2) const; //运算符“+”重载为成员函数
    friend ostream& operator<<(ostream &, Complex &);
//运算符“<<”重载为友元函数
private:
    double real;
    double imag;
};

Complex Complex::operator+(Complex &c2) const
//定义运算符“+”重载函数
{ return Complex(real + c2.real, imag + c2.imag); }

ostream& operator<<(ostream &output, Complex &c)
//定义运算符“<<”重载函数
{
    output << "(" << c.real << "+" << c.imag << "i)" << endl;
    return output;
}

int opt5() {

    Complex c1(2, 4), c2(6, 10), c3;
    c3 = c1 + c2;
//    cout << c3;
    operator<<(operator<<(cout,c3),c1);

    cout<<c3<<c1<<c2;
    return 0;
}


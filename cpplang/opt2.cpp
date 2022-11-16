//
// Created by andilyliao on 16-10-31.
//

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

    friend Complex operator+(Complex &c1, Complex &c2);

//重载函数作为友元函数
    void display() const;

private:
    double real;
    double imag;
};

Complex operator+(Complex &c1, Complex &c2)//定义作为友元函数的重载函数
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

void Complex::display() const
{
    cout << "(" << real << "," << imag << "i)" << endl;
}

int opt2() {
    Complex c1(3, 4), c2(5, -10), c3,c4;
    c3 = c1 + c2;
    //-->c1.operator+(c2)-->operator+(c1,c2)
    c4=operator+(c1,c2);
    cout << "c1=";
    c1.display();
    cout << "c2=";
    c2.display();
    cout << "c1+c2 =";
    c3.display();

    cout << "real c1+c2 =";
    c4.display();
}

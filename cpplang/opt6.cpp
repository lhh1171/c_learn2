////
//// Created by andilyliao on 16-10-31.
////
////用“cin>>”输入复数，用“cout<<”输出复数
//#include <iostream>
//
//using namespace std;
//
//class Complex {
//public:
//    friend ostream &operator<<(ostream &, Complex &);
//
//    //声明重载运算符“<<”
//    friend istream &operator>>(istream &, Complex &);
////声明重载运算符“>>”
//private:
//    double real;
//    double imag;
//};
////定义重载运算符“<<”
//ostream &operator<<(ostream &output, Complex &c)
//{
//    output << "(" << c.real << "+" << c.imag << "i)";
//    return output;
//}
//
//istream &operator>>(istream &input, Complex &c)
////定义重载运算符“>>”
//{
//    cout << "input real part and imaginary part of complex number:";
//    input >> c.real >> c.imag;
//    return input;
//}
//
//int opt6() {
//    Complex c1, c2,c3;
//    cin >> c1 >> c2;
//    cout << "c1=" << c1 << endl;
//    cout << "c2=" << c2 << endl;
//
//    operator>>(cin,c3);
//    operator<<(cout,c3);
//    return 0;
//}

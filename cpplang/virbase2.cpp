//
// Created by andilyliao on 16-10-28.
//

#include<iostream>
using namespace std;
class A
{
public:
    A(const char *s)
    {
        cout << "AAAAA"<<endl;
    }
    virtual ~A(){
        cout << "~~AAAAA"<<endl;
    }
};
class B :virtual public A
{
public:
    B(const char *s1, const char *s2):A(s1)
    {
        cout << "BBBBB"<<endl;
    }
    virtual ~B(){
        cout << "~~BBBBB"<<endl;
    }
};
class C : virtual public A
{
public:
    C(const char *s1, const char *s2):A(s1)
    {
        cout << "CCCCC"<<endl;
    }
    virtual ~C(){
        cout << "~~CCCCC"<<endl;
    }
};

class D : public B,public C
{
public:
    D(const char *s1, const char *s2, const char *s3, const char *s4)
                :B(s1, s2), C(s1, s3),A(s4)
    {
        cout << "DDDDD"<<endl;
    }
    ~D(){
        cout << "~~DDDDD"<<endl;
    }
};
int virbase2()
{
    A *ptr = new D("class A", "class B", "class C", "class D");
    delete ptr;
    return 0;
}
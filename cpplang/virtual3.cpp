#include<iostream>
using namespace std;
class A{
public:
    A(){}
    virtual void foo(){
        cout<<"This is A."<<endl;
    }
};

class B : public A{
public:
    B(){}
    void foo(){
        cout<<"This is B."<<endl;
    }
};

int virtual3(){
//    A a;
//    a.foo();
//    B b;
//    b.foo();

    A *a=new B();
    a->foo();
    delete a;
    return 0;
}

#include<iostream>
using namespace std;
class Base{
public:
    virtual void xxx(){   //虚函数
        cout<<"base_xxx"<<endl;
    }
//    virtual void dis()=0;  //纯虚函数
    Base(){ std::cout<<"Base::Base()"<<std::endl; }
    virtual ~Base(){ std::cout<<"Base::~Base()"<<std::endl; } //虚基类
};
class Derive:public Base{
public:
    void xxx(){
        cout<<"derive_xxx"<<endl;
    }
    void dis(){
        cout<<"derive_dis"<<endl;
    }
    Derive(){ std::cout<<"Derive::Derive()"<<std::endl; }
    ~Derive(){ std::cout<<"Derive::~Derive()"<<std::endl; }
};
int virbase(){
    Base* pBase = new Derive();
    pBase->xxx();
//    pBase->dis();
    /*这种base classed的设计目的是为了用来"通过base class接口处理derived class对象"*/
    delete pBase;


    Base* pBase1 = new Base();
    pBase1->xxx();
    delete pBase1;
    return 0;
}

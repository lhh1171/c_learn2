//
// Created by andilyliao on 17-11-3.
//

// test.cpp : 定义控制台应用程序的入口点。
//

#include <cstdlib>
#include <new>
#include <iostream>
using namespace std;

class test{
public:
    int a;
    double x;
    test() {
        a=0;
        x=0.0;
        cout<<"test()"<<endl;
    }
    test(int i,double m):a(i),x(m)
    {
        cout<<"test(int i,double m)"<<endl;
    };

    ~test()
    {
        cout<<"~test()"<<endl;
    }

    void* operator new(size_t sz)
    {
        cout<<"new"<<sz<<"\t"<<"sizeof(test): "<<sizeof(test)<<endl;
        void * p=malloc(sz);
        return p;
    }

    void* operator new[](size_t sz)
    {
        cout<<"new[]"<<sz<<"\t"<<"sizeof(test): "<<sizeof(test)<<endl;
        void * p=malloc(sz);
        return p;
    }

    void operator delete(void* p)
    {
        cout<<"delete"<<endl;
        free(p);
        p=0;
    }

    void operator delete[](void* p)
    {
        cout<<"delete[]"<<endl;
        free(p);
        p=0;
    }
};

int opt8()
{

    test* te=new test(1,12);
    delete te;

    test* te1=new test(2,10);
    delete te1;

    test* te2=new test[12];

    delete []te2;

    test* te3=new test[10];
    delete []te3;

    return 0;
}
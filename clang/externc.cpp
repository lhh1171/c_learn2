//
// Created by  on 16-10-31.
//
//gcc -S externc.cpp
#include <iostream>
using namespace std;
//#ifdef __cplusplus
extern "C" {
//#endif

    extern int ThisIsTest(int a, int b);

//#ifdef __cplusplus
}
//#endif

class FOO {
public:
    int bar(int a, int b)
    {
        cout<<"result="<< ThisIsTest(a, b)<<endl;
    }
};
int externc()
{
    int a = 1;
    int b = 2;

    FOO *foo = new FOO();
    foo->bar(a, b);
    delete foo;
    return 0;
}

//函数重载
int ThisIsTest(int a, int b)
{
    return (a + b);
}

int ThisIsTest(int a,long b)
{
    return (a + b);
}

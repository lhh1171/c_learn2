#include<iostream>
using namespace std;

int define8()
{
    cout << "Current File: " << __FILE__ << endl; //Current File: /opt/testio-cpp/clang/define8.cpp
    cout << "Current Line: " << __LINE__ << endl; //Current Line: 7
#line 1000 "wrongfile"
    cout << "Current File: " << __FILE__ << endl; //Current File: wrongfile
    cout << "Current Line: " << __LINE__ << endl; //Current Line: 1001
    cout << "Current Line: " << __LINE__ << endl; //Current Line: 1001
    return 0;
}

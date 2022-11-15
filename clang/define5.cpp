#include<iostream>
using namespace std;

int define5()
{
#define PI 3.14
    cout << PI << endl;         //3.14
#undef PI
//    cout << PI << endl;       //编译出错
    return 0;
}

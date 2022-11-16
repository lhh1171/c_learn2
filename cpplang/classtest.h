#ifndef CLASSTEST_H_INCLUDED
#define CLASSTEST_H_INCLUDED

#include <string>
using namespace std;
class CStudent{
public:
    void display();
    static void dis();
private:
    int num;
    char name[20];
    int age;
    static int xxx;
    string str;
};
#endif // CLASSTEST_H_INCLUDED

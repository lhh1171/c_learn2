//
// Created by andilyliao on 16-10-31.
//
//重载 * -> []
#include <iostream>
using namespace std;
struct Date
{
    int y;
    int m;
    int d;
};
class DatePtr
{
    Date* ptr;
public:
    DatePtr(Date* ptr = NULL):ptr(ptr)
    {
    }
    //重载了*号
    Date& operator*()
    {
        return *ptr;
    }
    //重载了箭头号
    Date* operator->()
    {
        return ptr;
    }
    //重载了中括号
    Date& operator[](int index)//[int]
    {
        return *(ptr+index);
    }
    ~DatePtr(){
        free(this->ptr);
    }

//    DatePtr operator[](float index)
//    {
//        return *this;
//    }

};
int opt7()
{
    Date d = {2012,9,27};

//    Date *pp=&d;
    DatePtr p = &d;
//    DatePtr p1(&d);
//    int i=10;
//    int i1(10);

    (*p).y = 2013;
//    ()(p.operator*())->y=2013;
//    (*pp).y=2013;

    p.operator*().y = 2013;

    p->m = 10;
//    p->->m=10;
    p.operator->()->m = 10;


    cout << d.y << '-' << d.m << '-' << d.d << endl;
    Date ds[3] = {
            {2012,9,27},
            {2012,9,30},
            {2012,12,21}
    };
    DatePtr p2 = ds;
    for (int i = 0; i<3; i++)
    {
        p2.operator[](i);

//        p2.operator[](1.1f).operator[](1.2f);
//        p2[1.1f][1.2f];
        cout << p2 [ i ] .y << '-' << p2[i].m
             << '-' << p2[i].d << endl;
    }
}
//语法糖
#include<iostream>
#include "classtest.h" //这里需要include这个头文件，否则无法找到Student类
#include "classtest.h"
using namespace std;
//int CStudent::num=0;
void CStudent::display(){  //这里要注明是Student类的
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
}
void CStudent::dis() {

}
int CStudent::xxx=10;
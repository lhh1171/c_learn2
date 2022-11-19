#include <iostream>
#include <unistd.h>
#include <term.h>

using namespace std;
class A{
    int id;
public:
    A(int id):id(id){
        cout<<"A"<<endl;
    }
    ~A(){
        cout<<"~A"<<endl;
    }
};
class B:virtual public A{
    int xxx;
public:
    B(int id,int xxx):A(id),xxx(xxx){
        cout<<"B"<<endl;
    }
};
class C:virtual public A{
    int xxx;
public:
    C(int id,int xxx):A(id),xxx(xxx){
        cout<<"C"<<endl;
    }
};
//class D: public B, public C{
//    int yyy;
//public:
//    D(int id,int xxx,int yyy):B(id,xxx),C(id,xxx),yyy(yyy){
//        cout<<"D"<<endl;
//    }
//};
class D: public B, public C{
    int yyy;
public:
    D(int id,int xxx,int yyy):A(id),B(id,xxx),C(id,xxx),yyy(yyy){
        cout<<"D"<<endl;
    }
};

//虚拟继承,解决菱形继承问题,不解决的话A内存就会有两份
void cm();
int main() {
//    D d(1,2,3);
//    fm();
//    pid_t  p1=fork();
//    //多来了一个进程跑这个main
//    pid_t  p2=fork();
//    pid_t  p3=fork();
//    printf("hhhhh(%d,%d,%d)\n",p1,p2,p3);
    cm();
}

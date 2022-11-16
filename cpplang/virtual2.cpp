#include<iostream>
using namespace std;
class A{

};
class B{
};
//class C:public A{
//
//};
//class D:public virtual B{//8
//};
//class E:public A,public B{
//};
class F:public virtual B,public virtual A{//8  //virtual
};
//class G:public F,public virtual D,public B{
//};
int virtual2(){
//    A a;
    B b;
//    C c;
//    D d;
//    E e;
    F f;
//    G g;
//    cout<<"sizeof(a):"<<sizeof(a)<<endl;
//    cout<<"sizeof(b):"<<sizeof(b)<<endl;
//    cout<<"sizeof(c):"<<sizeof(c)<<endl;
//    cout<<"sizeof(d):"<<sizeof(d)<<endl;
//    cout<<"sizeof(e):"<<sizeof(e)<<endl;
    cout<<"sizeof(f):"<<sizeof(f)<<endl;
//    cout<<"sizeof(g):"<<sizeof(g)<<endl;
    return 0;
}

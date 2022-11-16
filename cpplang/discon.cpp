#include<iostream>
using namespace std;
class Box1{
public:
    Box1(int h=2,int w=2,int l=2);
    ~Box1(){//析构函数
        cout<<"Destructor called."<<endl;//析构函数里的内容
    }
    int volume(){
        return height*width*length;
    }
private:
    int height,width,length;
};
Box1::Box1(int h,int w,int len){
    height=h;
    width=w;
    length=len;
}
int discon1(){
    Box1 box1;
    cout<<"The volume of box1 is "<<box1.volume()<<endl;
    cout<<"hello."<<endl;
    Box1 *box11=new Box1();
    delete box11;
    return 0;
}

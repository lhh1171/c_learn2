#include <iostream>
using namespace std;
class Box4{
public:
    Box4(int h=2,int w=2,int l=2);
    //在声明构造函数时指定默认参数
    int volume();
private:
    int height,width,length;
};
Box4::Box4(int h,int w,int len){
    //在定义函数时可以不指定默认参数
    height=h;
    width=w;
    length=len;
}
int Box4::volume(){
    return height*width*length;
}
int constructor4(){
    Box4 box1(1);
    //不指定第2、3个实参
    cout<<"box1's volume: "<<box1.volume()<<endl;
    Box4 box2(1,3);
    // 不指定第3个实参
    cout<<"box2's volume: "<<box2.volume()<<endl;
    return 0;
}

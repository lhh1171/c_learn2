//
// Created by lqc on 2022/11/19.
//
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

//int xxx(const int *ptr){
//    int *p=(int *)malloc(4);
//    memset(p,1,4);
//    ptr=p;
////    *ptr=2;
//    return 0;
//}

//写不写都一样
const int xxx(){
    int *p=(int *)malloc(4);
    memset(p,1,4);
    return *p;
}

class person{
    mutable int i;
public:
    void setI(int ii)const {
        //i不加mutable改不了
        this->i=ii;
    }
    int& getI()  {
        return this->i;
    }
};

//class person{
//    int i;
//public:
//    void setI(int ii){
//        this->i=ii;
//    }
//    const int& getI() const {
//        show();
//        return this->i;
//    }
//    void show() const {
//        cout<< this->i<<endl;
//    }
//};
void cm(){
//    int a=1;
//    int &&p=xxx();

    person p;
    p.getI()=2;
    cout<<p.getI()<<endl;
    //https://blog.csdn.net/xingjiarong/article/details/47282255
    //加在哪里哪里改不了
    //这两种写法是一样的，都是表示变量n的值不能被改变了，需要注意的是，
    // 用const修饰变量时，一定要给变脸初始化，否则之后就不能再进行赋值了。
    const int i=0;
    int const jj=0;

    //如果没有const的修饰，我们可能会在后面有意无意的写str[4]=’x’这样的语句，
    // 这样会导致对只读内存区域的赋值，然后程序会立刻异常终止。有了const，
    // 这个错误就能在程序被编译的时候就立即检查出来，这就是const的好处。
    // 让逻辑错误在编译期被发现。
    const char* str="fdsafdsa";
    /*1、常量指针说的是不能通过这个指针改变变量的值，但是还是可以通过其他的引用来改变变量的值的。
    int a=5;
    const int* n=&a;
    a=6;*/

    /*2、常量指针指向的值不能改变，但是这并不是意味着指针本身不能改变，常量指针可以指向其他的地址。
    int a=5;
    int b=6;
    const int* n=&a;
    n=&b;*/
    const int *j;
    int const *jjj;


}
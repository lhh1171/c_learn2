#include<iostream>
using namespace std;
int Mmin(int x,int y){
     if(x<y)return x;
     return y;
}
int Mmax(int x,int y){
    if(x>y)return x;
    return y;
}

int res1;
int * fun(int i,int j){
//    int res=i+j;
    static int res2;
//    res1=i+j;
    res2=i+j;
    return &res2;
}
int funptr(){
    int (*f)(int x,int y);
    int a=10,b=20;
    f=Mmin;   //把Mmin函数的入口地址赋给f
    cout << (*f)(a,b)<<endl;
    f=Mmax;  //把Mmax函数的入口地址赋给f
    cout << (*f)(a,b)<<endl;

    cout<<*fun(1,2)<<endl;
    return 0;
}

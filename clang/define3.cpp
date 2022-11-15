#include<iostream>
using namespace std;
//#define _DEBUG_ 3;
int define3(){
    //看看_DEBUG_又没有被定义成宏
    int x=10;
    #ifdef _DEBUG_
       cout<<"File:"<< __FILE__<<",Line:"<< __LINE__<<",x:"<<x<<endl;
    cout<<__FUNCTION__<<endl;
    #else
       printf("x = %d\n", x);
       cout<<x<<endl;
   #endif
    return 0;
}

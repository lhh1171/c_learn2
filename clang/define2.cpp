#include<iostream>
using namespace std;
#define area(x) x*x
#define fun(x,y) do \
{ \
    cout<<x<<"\t"<<y<<endl; \
}while(false)
int define2()
{
    //只认识3,3^2+2
    int y = area(2+3);
    fun(1,2);
    cout<<y<<endl;
    return 0;
}





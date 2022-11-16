#include<iostream>
using namespace std;
class CBox{
public:
    CBox(){};
    int c;
    virtual ~CBox(){};
};
int virtual1(){
    CBox boxobj;
    cout<<sizeof(boxobj)<<endl;//输出4
    return 0;
}

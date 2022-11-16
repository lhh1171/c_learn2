#include<iostream>
using namespace std;
class CBox{
public:
    CBox(){};
    ~CBox(){};
};
int discon2(){
    CBox boxobj;
    cout<<sizeof(boxobj)<<endl;
    return 0;
}

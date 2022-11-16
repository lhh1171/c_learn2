#include<iostream>
using namespace std;
class CBox{
    int length,width,height;
    short ww;
};
int classtest3(){
    CBox boxobj;
    cout<<sizeof(boxobj)<<endl;
    return 0;
}

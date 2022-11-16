#include<iostream>
using namespace std;
class CBox4{
    int length,width,height;
    static int count;
};
int classtest4(){
    CBox4 boxobj;
    cout<<sizeof(boxobj)<<endl;
    return 0;
}

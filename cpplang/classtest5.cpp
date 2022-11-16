#include<iostream>
using namespace std;
class CBox{
    int foo();
};
int classtest5(){
    CBox boxobj;
    cout<<sizeof(boxobj)<<endl;
    return 0;
}

#include <iostream>
using namespace std;

extern int j=1330;
static int i=10;
int hello() {
    i++;
    cout<<i<<endl;
    return 0;
}
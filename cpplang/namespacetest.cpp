#include <iostream>
using namespace std;
int x = 20;
namespace outer {
    int x = 10;
    namespace inner {
        int x=100;
        int z = x;
    }
}

extern int testns()
{
    using namespace outer::inner;
    cout<<z<<endl;
    //cout <<x<<"\t"<<outer::x<<"\t"<<outer::inner::z;
    return 0;
}


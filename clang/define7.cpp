#include<iostream>
using namespace std;

int define7()
{
#define OPTION 2

#if OPTION == 1
    cout << "Option: 1" << endl;
#elif OPTION == 2
    cout << "Option: 2" << endl; //选择这句
#else
    cout << "Option: Illegal" << endl;
#endif
    return 0;
}

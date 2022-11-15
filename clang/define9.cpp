#include<iostream>
using namespace std;

int define9()
{
#define OPTION 3
#if OPTION == 1
    cout << "Option： 1" << endl;
#elif OPTION == 2
    cout << "Option: 2" << endl;
#else
//   #error ILLEGAL OPTION!
    //fatal error C1189: #error :  ILLEGAL OPTION!
#endif
    return 0;
}

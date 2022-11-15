//
// Created by  on 16-10-31.
//

#include "define10.h"
#include <iostream>

using namespace std;
int define10()
{
    FOO foo;
    foo.member=10;
    cout<<foo.member<<endl;
    cout<<g_Value<<endl;
//引用包，后面会讲到
#pragma comment(lib, "pthread")

    S s;
    cout<<sizeof(s)<<endl;
    return 0;
}

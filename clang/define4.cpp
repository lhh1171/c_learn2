#include<cstdio>
#include <iostream>
using namespace std;
#define add(a,b) { \
    a+b \
}

int define4() {
#define TO_LITERAL(text) TO_LITERAL_(text)//TO_LITERAL_(201103L)
#define TO_LITERAL_(text) #text //201103L

/*  __cplusplus和c_plusplus这两个宏有定义，说明你使用的c++的编译器。 表示这是一段cpp文件的代码
就是如果你在编译这个程序的时候，如果用的是c++的编译器，这两个宏开关就会生效。*/

#ifndef __cplusplus
    /* this translation unit is being treated as a C one */
        printf("a C program\n");
#else
    /*this translation unit is being treated as a C++ one*/
    printf("a C++ program\n__cplusplus expands to \""
                   TO_LITERAL(__cplusplus) "\"\n");//TO_LITERAL_(201103L)-->"201103L"
    //TO_LITERAL_(__cplusplus)-->"__cplusplus"
#endif

    int c=add(1,2);

    int c1={
            1+2
    };


    cout<<c<<endl;


    return 0;
}


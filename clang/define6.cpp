#include<iostream>
using namespace std;

int define6()
{
#define CAT(n) "ABC"#n
    cout << CAT(123) << endl;//ABC123

#define NUM(a,b) a##b

#define STR(a,b) a b
    cout << NUM(1, 2) << endl;//12
    cout << STR("Hello", "World") << endl;//HelloWorld
    return 0;
}

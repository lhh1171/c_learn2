#include<iostream>

using namespace std;
struct aaa {
    int a;
    int b;
} bbbb{1, 2};
struct aaa bbb = {
        .a=11,
        .b=12
};
typedef struct {
    int a;
    int b;
} xxx;

int stru3() {

    aaa b;
    b.a = 1;
    b.b = 2;
    xxx x;
    cout << bbbb.a << endl;
    cout << bbb.a << "\t" << bbb.b << endl;
    return 0;
}


#include <fstream>
#include <iostream>
#include <string.h>
#include <zconf.h>
#include <stdlib.h>

using namespace std;
int byteio7()
{
    //包含内容"Hello World"
    ifstream File("/opt/xxx");

    char ch;

    File.get(ch);

    cout << ch << endl; //将显示"H"

    File.putback(ch);
    cout << ch << endl; //仍将显示"H"

    File.get(ch);
    cout << ch << endl; //再一次显示"H"

    File.close();
    return 0;
}
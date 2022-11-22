
#include <fstream>
#include <iostream>
using namespace std;

int cppio2()
{
    ifstream OpenFile("/opt/xxx",ios::in);

    char ch;
    while(!OpenFile.eof())
    {
        OpenFile.get(ch);
        cout << ch;
    }
    OpenFile.close();
    return 0;
}
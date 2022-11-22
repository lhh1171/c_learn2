

#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
int byteio5()
{
    ifstream File("/opt/xxx");//假设文本内容是：hello
    char ch;

    File.get(ch);
    cout << ch << endl; //将显示"H"

    cout << char(File.peek()) << endl; //将显示"e"
    cout << char(File.peek()) << endl; //将再次显示"e"

    File.get(ch);
    cout << ch << endl; //还是显示"e"

    File.close();
    return 0;
}
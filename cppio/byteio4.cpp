
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
int byteio4()
{
    ifstream file("/opt/xxx");//假设文本内容是：hello
    static char arr[10];
    /*读取，直到满足下面的条件之一：
1）已经读取10个字符
2）遇到字母"o"
3）出现新一行
    */
    file.seekg(ios::beg);
    char chstr[1024];
    file.getline(chstr,100);
    cout<<chstr<<endl;

    file.seekg(ios::beg);
    file.getline(arr,10,'o');

    cout << arr << endl; //将显示"Hell"

    file.seekg(ios::beg);
    string str1;
    getline(file,str1);
    cout<<str1<<endl;

    file.close();
    return 0;
}
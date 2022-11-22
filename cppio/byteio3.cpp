
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;
int byteio3()
{
    ifstream file("/opt/xxx");
    char arr[10];
    arr[9]='\0';
    file.read(arr,9);
    //tellg()——返回一个int型数值，它表示“内置指针”的当前位置。
    cout << file.tellg() << endl;
    cout<<arr<<endl;
    //假如一直没有遇到字符"l"，则向前定位直到跳过6个字符
    //而如果期间遇到"l"，则停止向前，定位在该处
    file.seekg(ios::beg);
    memset(arr,0,sizeof(arr)-1);

    cout<<arr<<endl;

    file.ignore(6,'l');

    file.read(arr,9);

    cout<<arr<<endl;

    file.close();
    return 0;
}
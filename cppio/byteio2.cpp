
//

#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
int byteio2()
{
    fstream file("/opt/xxx",ios::out | ios::in | ios::binary);

    char arr[13];
    strcpy(arr,"Hello World!");//将Hello World!存入数组

    file.write(arr,5);//将前5个字符——"Hello"写入文件

    file.seekg(ios::beg);//定位至文件首部

    static char read_array[10];//在此我将打算读出些数据(如果使用栈段，会有很多乱七八糟的东西被读出)

    file.read(read_array,3);//读出前三个字符——"Hel"

    cout << read_array << endl;//将它们输出

    file.close();
    return 0;
}
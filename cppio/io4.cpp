

#include <fstream>
#include <iostream>
using namespace std;

int cppio4()
{
    fstream file("/opt/xxx",ios::in | ios::out);
    file << "Hi!";
    char str[10];
    /*
    ios::beg —— 可将它移动到文件首端
    ios::end —— 可将它移动到文件末端
     */
    file.seekg(ios::end);// 回到文件首部
    while(!file.eof()){
        file >> str;
        cout << str <<" ";
    }
    cout<<endl;
    file.close();
    return 0;
}
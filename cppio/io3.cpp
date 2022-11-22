
#include <fstream>
#include <iostream>
using namespace std;
void read(ifstream &T){
    char ch;
    while(!T.eof())
    {
        T.get(ch);
        cout << ch;
    }
    cout << endl << "--------" << endl;
}
int cppio3(){
    ifstream T("/opt/xxx");
    read(T);
    T.close();

    T.open("/opt/xxx");
    read(T);
    T.close();
    return 0;
}

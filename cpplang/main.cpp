#include <iostream>
using namespace std;
class stu{
    string name;
public:
    stu(string name){
        this->name=name;
    }
    void dis(){
        cout<< this->name<<endl;
    }
    stu operator++(){
        return stu(this->name+"++stu");
    }
    stu operator++(int ){
        return stu(this->name+"stu++");
    }
};
int main() {
    stu s("lilei");
    s++.dis();
    (++s).dis();
    return 0;
}

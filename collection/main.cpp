#include <iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;

//提前声明一下
class tea;
class stu;
class course;

class course{
public:
    string c_name;
    int cno;
};
class stu{
public:
    string s_name;
    int sno;
};
class tea{
public:
    string t_name;
    int tno;
};
int main() {
    set<stu> students;
    set<tea> teachers;
    set<course> courses;
    map<tea,set<stu>> tea_and_stu;
    map<tea,course> tea_and_course;
    map<stu,set<course>> stu_and_course;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

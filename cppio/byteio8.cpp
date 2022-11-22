#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
public:
    //有元声明最后放在public里面，不知道为啥
    friend istream& operator>>(istream&is, Student&st);
    friend ostream& operator<<(ostream&os, const Student&st);

    Student() = default;
    Student(string na, int sc)
    {
        name = na;
        score = sc;
    }
    ~Student() = default;
    void dis(){
        cout<<this->name.c_str()<<"\t"<<this->score<<endl;
    }
private:
    string name;
    int score;
};

istream& operator>>(istream&is, Student&st)
//ifstream是isream的子类，也能作为函数的参数
{
    is >> st.name;
    is>>st.score;
    return is;
}

ostream& operator<<(ostream&os, const Student&st)//ofstream是osream的子类，也能作为函数的参数
{
    os << st.name << " " << st.score << endl;
    return os;
}

int byteio8()
{
    ////二进制文件操作
    //写文件
    ofstream fout("/opt/xxxb",ios::binary);//能自动创建文件
    Student  s1("李明",100);
    fout.write((char*)&s1,sizeof(s1));
    fout.flush();
    fout.close();

    //读文件
    ifstream fin("/opt/xxxb",ios::binary);
    Student *s2=new Student;//如果不适用堆内存，有可能会造成munmap_chunk(): invalid pointer
    fin.read((char *)s2, sizeof(Student));
    fin.close();
    s2->dis();

    ////文本文件操作

    //写文件
    ofstream fout2("/opt/xxx");//能自动创建文件
    Student  s12("李明1", 90);
    fout2 << s12;
    fout2.flush();
    fout2.close();

    //读文件
    ifstream fin2("/opt/xxx");
    Student  s22;
    fin2 >> s22;
    fin2.close();
    s22.dis();

    return 0;
}
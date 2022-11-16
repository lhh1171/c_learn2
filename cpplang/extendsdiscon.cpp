#include<iostream>
#include<string>
using namespace std;
class CStudent{//声明基类Student
public:
    CStudent(){
        cout<<"pppppppppp"<<endl;
    }
   CStudent(int n,string nam,char s){//基类构造函数
      num=n;
      name=nam;
      sex=s;
   }
    virtual void xxx(){
        cout<<"xxxxxxxx"<<endl;
    }
   virtual ~CStudent(){
       cout<<"aaaaaaaaaa"<<endl;
   } //基类析构函数
protected: //保护部分
   int num;
   string name;
   char sex ;
};
//声明派生类Student1
class CStudent1: public CStudent{
public : //派生类的公用部分
    CStudent1():CStudent(){
        cout<<"1111111111"<<endl;
    }
    //派生类构造函数
   CStudent1 (int n,string nam,char s,int a,string ad): CStudent (n,nam,s){
      age=a;
      //在函数体中只对派生类新增的数据成员初始化
      addr=ad;
   }
    void xxx(){
        cout<<"00000000000000"<<endl;
    }
   void show(){
      cout<<"num: "<<num<<endl;
      cout<<"name: "<<name<<endl;
      cout<<"sex: "<<sex<<endl;
      cout<<"age: "<<age<<endl;
      cout<<"address: "<<addr<<endl<<endl;
   }
   ~CStudent1(){
       cout<<"bbbbbbbbbbb"<<endl;
   } //派生类析构函数
private : //派生类的私有部分
   int age;
   string addr;
};
int extendsdiscon(){
//   CStudent1 stud1(10010,"Wang-li",'f',19,"115 Beijing Road,Shanghai");
//   CStudent1 stud2(10011,"Zhang-fun",'m',21,"213 Shanghai Road,Beijing");
//   stud1.show(); //输出第一个学生的数据
//   stud2.show(); //输出第二个学生的数据
    CStudent *stu1=new CStudent1();
    stu1->xxx();
    delete stu1;
   return 0;
}

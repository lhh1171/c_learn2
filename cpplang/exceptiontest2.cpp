#include <iostream>
#include <string>
using namespace std;
//自定义异常类

class MyException
{
public:
    //异常类无参数默认构造函数定义
    MyException()
    {
        m_context= "";                                      //初始化异常信息数据成员为空
    }
    //异常类空析构函数定义
    ~MyException(){}
    //异常类字符串类型参数构造函数定义
    MyException(const string & right)
    {
        m_context= right;                                 //初始化异常信息数据为字符串对象参数
    }
    //异常类字符串指针类型参数构造函数定义
    MyException(const char * right)
    {
        m_context= right;                                 //初始化异常信息数据为字符串指针参数
    }
    //异常类返回异常信息接口方法定义
    string what() const
    {
        return m_context;                                  //直接返回相应的异常信息数据成员
    }
private:
    string   m_context;                                       //字符串类型数据成员，表示异常信息
};
class Compute
{
public:
    Compute(int value1,int value2);                           //除法计算类构造函数，两个整型参数列表
    ~Compute(){}                                                  //除法计算类空析构函数定义
    void divideCompute()  noexcept;                                  //除法计算类除法计算方法成员
    void divideCompute2()throw(MyException);
private:
    int m_value1;                                                  //除法计算类数据成员，表示被除数
    int m_value2;                                                  //除法计算类数据成员，表示除数
};
Compute::Compute(int value1,int value2)                            //除法计算类构造函数定义
{
    m_value1= value1;                                                //初始化被除数数据成员
    m_value2= value2;                                                //初始化除数数据成员
}
void Compute::divideCompute() noexcept                                  //除法类除法计算方法成员定义
{
    try
    {
        if(m_value2== 0)                                          //如果除数为0，则抛出相应异常
        {
            throw MyException("divisor is 0!");
        }
        else                                                                            //否则计算两数相除，并打印结果
        {
            cout<<"m_value1/m_value2:"<<(m_value1/m_value2)<<endl;
        }
    }catch(MyException &e)                                         //捕获对应异常类型
    {
        string errorMessage = e.what();                            //定义错误信息字符串对象，获取对应异常信息
        cout<<errorMessage<<endl;                       //打印输出对应的异常信息
    }catch(...)                                                                   //捕获所有异常
    {
        string errorMessage = "Don’t knowerror!";//捕获所有异常处理信息
        cout<<errorMessage<<endl;
    }
}
void Compute::divideCompute2()throw(MyException)                                   //除法类除法计算方法成员定义
{
    if(m_value2== 0)                                          //如果除数为0，则抛出相应异常
    {
        throw MyException("divisor is 0!");
    }
    else                                                                            //否则计算两数相除，并打印结果
    {
        cout<<"m_value1/m_value2:"<<(m_value1/m_value2)<<endl;
    }
}
int exceptiontest2()
{
    int value1,value2;                                                    //定义两个整型变量
    cout<<"Pleaseinput two value:"<<endl;             //提述输入两个整型数据
    cin>>value1>>value2;                                          //从键盘输入两个整型数
    Compute compute(value1,value2);                     //定义计算类对象，同时传入输入的两个整型数构造初始化
    compute.divideCompute();
    try{
        compute.divideCompute2();//计算类对象调用其除法计算方法
    }catch (...){
        string errorMessage = "Don’t knowerror!";
        cout<<errorMessage<<endl;
    }
    return 0;
}
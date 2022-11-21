#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
using namespace std;

int doSomething (char c)
{
    std::default_random_engine dre(c); //初始化随机种子
    std::uniform_int_distribution<int> id(10,1000);  //// 使用给出的范围初始化分布类

    for (int i=0; i<10; ++i) {
        //chrono是一个time lib
        this_thread::sleep_for(chrono::milliseconds(id(dre)));  //id(dre)根据范围用种子生成随机数
//        cout.put(c).flush();
        cout<<c;
        cout.flush();
    }

    return c;
}

int func1 ()
{
    cout<<"func1"<<endl;
    return doSomething('.');
}

int func2 ()
{
    cout<<"func2"<<endl;
    return doSomething('+');
}

int cpp_async1()
{
    cout << "starting func1() in background"
              << " and func2() in foreground:" << endl;

    // start func1() asynchronously (now or later or never):
    std::future<int> result1(std::async(func1));

    int result2 = func2();    // call func2() synchronously (here and now)

    // print result (wait for func1() to finish and add its result to result2
    int result = result1.get() + result2;

    cout << "\nresult of func1()+func2(): " << result
              << endl;
    return 0;
}

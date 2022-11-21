#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future
using namespace std;
void print_int(std::future<int>& fut) {
    int x = fut.get(); // 获取共享状态的值.
    std::cout << "value: " << x << '\n'; // 打印 value: 10.
}
//promise set 然后future就可以get到东西　并且中断阻塞
int cpppromise1 ()
{
    std::promise<int> prom; // 生成一个 std::promise<int> 对象.
    std::future<int> fut = prom.get_future(); // 和 future 关联.
    std::thread t(print_int, std::ref(fut)); // 将 future 交给另外一个线程t.
    cout<<"====="<<endl;
    prom.set_value(10); // 设置共享状态的值, 此处和线程t保持同步.
    cout<<"====="<<endl;
    t.join();
    return 0;
}
#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

int queryNumber ()
{
    // read number
    cout << "read number: ";
    int num;
    cin >> num; 

    // throw exception if none
    if (!cin) {
        throw runtime_error("no number read");
    }

    return num;
}

void doSomething (char c, shared_future<int> f)
{
    try {
        // wait for number of characters to print
        int num = f.get();  // get result of queryNumber()

        for (int i=0; i<num; ++i) {
            this_thread::sleep_for(chrono::milliseconds(100));
            cout.put(c).flush();
        }
    }
    catch (const exception& e) {
        cerr << "EXCEPTION in thread " << this_thread::get_id()
                  << ": " << e.what() << endl;
    }
}

int cppsharedfuture1()
{
    try {
        // start one thread to query a number
        shared_future<int> f = async(queryNumber);

        // start three threads each processing this number in a loop
        /**
         * std::launch::async发射策略意味着函数f必须异步执行，即在另一线程执行。
std::launch::deferred发射策略意味着函数f可能只会在——std::async返回的future对象调用get或wait时——执行。
         那就是，执行会推迟到其中一个调用发生。
         当调用get或wait时，f会同步执行，即，调用者会阻塞直到f运行结束。
         如果get或wait没有被调用，f就绝对不会执行。
         */
//        auto f1 = async(launch::async,doSomething,'.',f);
//        auto f2 = async(launch::async,doSomething,'+',f);
//        auto f3 = async(launch::async,doSomething,'*',f);

        cout<<"＋＋＋＋＋"<<endl;


        auto f1 = async(launch::deferred,doSomething,'.',f);
        cout<<"====="<<endl;
        auto f2 = async(launch::deferred,doSomething,'+',f);
        auto f3 = async(launch::deferred,doSomething,'*',f);


        // wait for all loops to be finished
        cout<<"-------"<<endl;
        f1.get();
        cout<<"f1"<<endl;
        f2.get();
        cout<<"f2"<<endl;
        f3.get();
        cout<<"f3"<<endl;
    }
    catch (const exception& e) {
        cout << "\nEXCEPTION: " << e.what() << endl;
    }
    cout << "\ndone" << endl;
    return 0;
}

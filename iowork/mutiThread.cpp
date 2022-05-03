//
// Created by lqc on 2022/5/3.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <exception>
using namespace std;
void doSomething (int num, char c)
{
    try {
        // random-number generator (use c as seed to get different sequences)
        default_random_engine dre(42*c);
        uniform_int_distribution<int> id(10,1000);
//        cout<<id<<"\t"<<id(dre)<<endl;
        int t=id(dre);
        this_thread::sleep_for(chrono::milliseconds(t));
        for (int i=0; i<num; ++i) {
            cout.put(c).flush();
        }
    }
        // make sure no exception leaves the thread and terminates the program
    catch (const exception& e) {
        cerr << "THREAD-EXCEPTION (thread "
             << this_thread::get_id() << "): " << e.what() << endl;
    }
    catch (...) {
        cerr << "THREAD-EXCEPTION (thread "
             << this_thread::get_id() << ")" << endl;
    }
}

int cppthread1()
{
    try {
        // print other characters in other background threads
        for (int i=0; i<5; ++i) {
            thread t(doSomething,10,'a'+i); // print 10 chars in separate thread
            cout << "- detach started bg thread " << t.get_id() << endl;
            t.detach();  // detach thread into the background
        }
        cin.get();  // wait for any input (return)
    }
    catch (const exception& e) {
        cerr << "EXCEPTION: " << e.what() << endl;
    }
    return 0;
}

//int main(){
//    cppthread1();
//}


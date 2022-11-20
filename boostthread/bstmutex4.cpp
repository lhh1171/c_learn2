//
// Created by andilyliao on 16-12-16.
//
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

int bstmutex4()
{
    try
    {
        managed_shared_memory managed_shm(open_or_create, "shm", 1024);
        int *i = managed_shm.find_or_construct<int>("Integer")(0);
        interprocess_mutex *mtx = managed_shm.find_or_construct<interprocess_mutex>("mtx")();
        interprocess_condition *cnd = managed_shm.find_or_construct<interprocess_condition>("cnd")();
        //放在栈里会被析构，释放
        scoped_lock<interprocess_mutex> lock(*mtx);
        while (*i < 10)
        {
            if (*i % 2 == 0)
            {
                ++(*i);
                cnd->notify_all();
                cnd->wait(lock);
            }
            else
            {
                cout << *i << endl;
                ++(*i);
                cnd->notify_all();
                cnd->wait(lock);
            }
        }
        cnd->notify_all();
    }
    catch (...)
    {
    }
    shared_memory_object::remove("shm");
    return 0;
}

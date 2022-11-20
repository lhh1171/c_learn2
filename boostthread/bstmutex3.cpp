//
// Created by andilyliao on 16-12-16.
//
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <boost/interprocess/sync/named_condition.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

int bstmutex3()
{
    managed_shared_memory managed_shm(open_or_create, "shm1", 1024);
    int *i = managed_shm.find_or_construct<int>("Integer")(0);
    named_mutex named_mtx(open_or_create, "mtx1");
    named_condition named_cnd(open_or_create, "cnd1");
    scoped_lock<named_mutex> lock(named_mtx);
    while (*i < 10)
    {
        if (*i % 2 == 0)
        {
            ++(*i);
            named_cnd.notify_one();
            named_cnd.notify_all();
            named_cnd.wait(lock);
        }
        else
        {
            cout << *i << endl;
            ++(*i);
            named_cnd.notify_all();
            named_cnd.wait(lock);
        }

    }
    named_cnd.notify_all();
    shared_memory_object::remove("shm1");
    named_mutex::remove("mtx1");
    named_condition::remove("cnd1");
    return 0;
}

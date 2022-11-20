
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

int bstmutex1()
{
    managed_shared_memory managed_shm(open_or_create, "shm", 1024);
    int *i = managed_shm.find_or_construct<int>("Integer")();
    named_mutex named_mtx(open_or_create, "mtx");
    named_mtx.lock();
    ++(*i);
    cout << *i << endl;
    named_mtx.unlock();
    return 0;
}

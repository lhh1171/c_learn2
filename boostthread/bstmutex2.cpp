//
// Created by andilyliao on 16-12-16.
//
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

//上锁、解锁
int bstmutex2()
{
    managed_shared_memory managed_shm(open_or_create, "shm", 1024);
    int *i = managed_shm.find_or_construct<int>("Integer")();
    interprocess_mutex *mtx = managed_shm.find_or_construct<interprocess_mutex>("mtx")();
    mtx->lock();
    ++(*i);
    cout << *i << endl;
    mtx->unlock();
    return 0;
}

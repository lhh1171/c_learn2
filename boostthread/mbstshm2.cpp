#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

int mbstshm2()
{
    shared_memory_object::remove("Highscore");
    managed_shared_memory managed_shm(open_or_create, "Highscore", 1024);
    //声明了一个数组 
    int *i = managed_shm.construct<int>("Integer")[10](99);
    cout << *i <<" "<<*(i+1)<< endl;
    pair<int*, size_t> p = managed_shm.find<int>("Integer");
    if (p.first)
    {
        cout << *p.first << endl;
        cout << p.second << endl;
    }
    return 0;
}

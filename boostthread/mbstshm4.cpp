
#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

int mbstshm4()
{
    shared_memory_object::remove("Highscore");
    managed_shared_memory managed_shm(open_or_create, "Highscore", 1024);
    int *i = managed_shm.find_or_construct<int>("Integer")(99);
    cout << *i << endl;
    managed_shm.destroy<int>("Integer");
    pair<int*, size_t> p = managed_shm.find<int>("Integer");
    cout << p.first << endl;
    return 0;
}


#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

int mbstshm1()
{
    shared_memory_object::remove("Highscore");
    //共享内存
    managed_shared_memory managed_shm(open_or_create, "Highscore", 1024);
    //一个k,v
    int *i = managed_shm.construct<int>("Integer")(99);
    std::cout << *i << std::endl;
    //通过key找到value
    std::pair<int*, std::size_t> p = managed_shm.find<int>("Integer");
    if (p.first) {
        std::cout << *p.first << std::endl;
    }
    return 0;
}

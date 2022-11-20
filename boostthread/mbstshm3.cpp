
#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

int mbstshm3()
{
    try
    {
        shared_memory_object::remove("Highscore");
        managed_shared_memory managed_shm(open_or_create, "Highscore", 1024);
        //如果大小超过1024会报错
        int *i = managed_shm.construct<int>("Integer")[4096](99);
    }
    catch (boost::interprocess::bad_alloc &ex)
    {
        cerr << ex.what() << endl;
    }
    return 0;
}

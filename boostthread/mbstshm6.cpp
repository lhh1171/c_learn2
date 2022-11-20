
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/bind.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

managed_shared_memory *managed_shm=NULL;
void construct_objects()
{
    managed_shm->construct<int>("Integer")(99);
    managed_shm->construct<float>("Float")(3.14);
}

int mbstshm6()
{
    shared_memory_object::remove("HHHHH");
    managed_shm=new managed_shared_memory(open_or_create, "HHHHH", 1024);

    managed_shm->atomic_func(construct_objects);//为了立刻执行多个操作而不被其他应用程序的操作打断，可以使用 atomic_func() 函数

    cout << *managed_shm->find<int>("Integer").first << endl;
    cout << *managed_shm->find<float>("Float").first << endl;
    return 0;
}

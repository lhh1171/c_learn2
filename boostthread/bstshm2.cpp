
#include <boost/interprocess/shared_memory_object.hpp>
#include <iostream>
#include <boost/interprocess/mapped_region.hpp>
using namespace std;
using namespace boost::interprocess;

int bstshm2()
{
    shared_memory_object shdmem(open_or_create, "Highscore", read_write);
    shdmem.truncate(1024);
    mapped_region region(shdmem, read_write);
    cout << hex << "0x" << region.get_address() << endl;
    cout << dec << region.get_size() << endl;
    mapped_region region2(shdmem, read_only);
    //虽然变量 region 和 region2 表示的是该进程内不同的内存区域，但由于两个内存区域底层实际访问的是同一块共享内存
    cout << hex << "0x" << region2.get_address() << endl;
    cout << dec << region2.get_size() << endl;
    return 0;
}

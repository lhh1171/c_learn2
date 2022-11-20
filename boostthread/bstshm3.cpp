
#include <boost/interprocess/shared_memory_object.hpp>
#include <iostream>
#include <boost/interprocess/mapped_region.hpp>
using namespace std;
using namespace boost::interprocess;

int bstshm3()
{
    shared_memory_object shdmem(open_or_create, "Highscore", read_write);
    shdmem.truncate(1024);
    mapped_region region(shdmem, read_write);
    int *i1 = static_cast<int*>(region.get_address());
    *i1 = 99;
    mapped_region region2(shdmem, read_only);
//    虽然变量 region 和 region2 表示的是该进程内不同的内存区域，但由于两个内存区域底层实际访问的是同一块共享内存
//    所以还是99
    int *i2 = static_cast<int*>(region2.get_address());
    cout << *i2 << endl;
    return 0;
}

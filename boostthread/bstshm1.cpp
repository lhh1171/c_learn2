
#include <boost/interprocess/shared_memory_object.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;
int bstshm1()
{
    shared_memory_object shdmem(open_or_create, "Highscore", read_write);
    shdmem.truncate(1024);
    cout << shdmem.get_name() << endl;
    offset_t size;
    if (shdmem.get_size(size)){
        cout << size << endl;
    }
    return 0;
}

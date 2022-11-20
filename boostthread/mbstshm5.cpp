
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <iostream>
using namespace std;
using namespace boost::interprocess;

int mbstshm5()
{
    shared_memory_object::remove("Highscore");
    managed_shared_memory managed_shm(open_or_create, "Highscore", 1024);
    typedef boost::interprocess::allocator<char, managed_shared_memory::segment_manager> CharAllocator;

    //boost::interprocess::string 的行为实际上对应的是 std::string
    typedef boost::container::basic_string<char, char_traits<char>, CharAllocator> string;

    string *s = managed_shm.find_or_construct<string>("String")("Hello!", managed_shm.get_segment_manager());
    s->insert(5, ", world");
    cout << *s << endl;
    return 0;
}
